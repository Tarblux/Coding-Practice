#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// #define MAX_DATA 512
// #define MAX_ROWS 100

typedef struct Address {
	int id;
	int set;
	char *name;
	char *email;
} Address;

struct Database{
	int max_data;
	int max_rows;
	Address *rows;
};

struct Connection{
	FILE *file;
	struct Database *db;
};

void die(const char *message)
{
	if (errno){
		perror(message);
	} else {
		printf("ERROR: %s\n",message);
	}

	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s \n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
	int i = 0;

	fread(&conn->db->max_data, sizeof(int), 1, conn->file);
	fread(&conn->db->max_rows, sizeof(int), 1, conn->file);

	conn->db->rows = malloc(sizeof(Address) * conn->db->max_rows);

	for (i = 0; i < conn->db->max_rows; i++) {
		Address *addr = &conn->db->rows[i];

		addr->name = malloc(conn->db->max_data);
		addr->email = malloc(conn->db->max_data);

		fread(&addr->id, sizeof(int), 1, conn->file);
		fread(&addr->set, sizeof(int), 1, conn->file);
		fread(addr->name, conn->db->max_data, 1, conn->file);
		fread(addr->email, conn->db->max_data, 1, conn->file);
	}
}

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if (!conn){
		die("Memory error");
	}

	conn->db = malloc(sizeof(struct Database));
	if (!conn->db){
		die("Memory error");
	}

	if (mode == 'c'){
		conn->file = fopen(filename,"wb");
	} else {
		conn -> file = fopen(filename, "rb+");

		if (conn->file){
			Database_load(conn);
		}
	}

	return conn;
}

void Database_close(struct Connection *conn)
{
    int i;

    if (conn) {
        if (conn->db) {
            if (conn->db->rows) {
                for (i = 0; i < conn->db->max_rows; i++) {
                    free(conn->db->rows[i].name);
                    free(conn->db->rows[i].email);
                }
                free(conn->db->rows);
            }
            free(conn->db);
        }

        if (conn->file) fclose(conn->file);
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
	int i = 0;

	rewind(conn->file);

	fwrite(&conn->db->max_data, sizeof(int), 1, conn->file);
	fwrite(&conn->db->max_rows, sizeof(int), 1, conn->file);

	for (i = 0; i < conn->db->max_rows; i++) {
		Address *addr = &conn->db->rows[i];

		fwrite(&addr->id, sizeof(int), 1, conn->file);
		fwrite(&addr->set, sizeof(int), 1, conn->file);
		fwrite(addr->name, conn->db->max_data, 1, conn->file);
		fwrite(addr->email, conn->db->max_data, 1, conn->file);
	}

	fflush(conn->file);
}

void Database_create(struct Connection *conn, int max_data, int max_rows)
{
	int i = 0;

	conn->db->max_data = max_data;
	conn->db->max_rows = max_rows;

	conn->db->rows = malloc(sizeof(Address) * max_rows);

	for (i = 0; i < max_rows; i++){

		conn->db->rows[i].id = i;
		conn->db->rows[i].set = 0;

		conn->db->rows[i].name = malloc(max_data);
		conn->db->rows[i].email = malloc(max_data);

	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	
	struct Address *addr = &conn->db->rows[id];

	int max_data = conn->db->max_data;
	// int max_rows = conn->db->max_rows;

	if (addr->set){
		die("Already set, delete it first");
	}

	addr->set = 1;

	char *res = strncpy(addr->name, name, max_data);
	addr->name[max_data - 1] = '\0';	

	res = strncpy(addr->email, email, max_data);
	addr->email[max_data - 1] = '\0';	
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if (addr->set) {
		Address_print(addr);
	}else{
		die("ID is not set");
	}
}

void Database_delete(struct Connection *conn,int id)
{
	struct Address *record = &conn->db->rows[id];
	record->set = 0;
}

void Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn->db;
	// int max_rows = conn->db->max_rows;

	for (i = 0; i < db->max_rows; i++){
		struct Address *cur = &db->rows[i];

		if (cur->set) {
			Address_print(cur);
		}
	}
}

void Database_find(struct Connection *conn , char *name)
{
	int i = 0;
	struct Database *db = conn->db;
	int found = 0

	for (i = 0; i < db->max_rows; i++){
		struct Address *cur = &db->rows[i];

		if (cur->set){

			if (strstr(cur->name, name)) {
				Address_print(cur);
				found = 1;
			}
		}
		break;
	}

	if (!found){
		printf("That person is an alien ! \n");	
	}
	

}

int main(int argc, char *argv[])
{
	if (argc < 3){
		die("USAGE: ex17 <dbfile> <action> [action params]");
	}

	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);

	int max_data = conn->db->max_data;
	int max_rows = conn->db->max_rows;

	int id = 0;

	if (argc > 3){
		id = atoi(argv[3]);
	}


	switch(action){
		
		case 'c':

			if (argc != 5){
				die("Need to give max_data and max_rows");
			}

			max_data = atoi(argv[3]); 
			max_rows = atoi(argv[4]);

			Database_create(conn, max_data, max_rows);
			Database_write(conn);

			break;

		case 'g':
			if (argc != 4){
				die("Need an id to get");
			}

			if (id >= conn->db->max_rows) die("Not that many records");

			Database_get(conn, id);
			break;

		case 's':
			if (argc != 6){
				die("Need id, name, email to set");
			}

			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;

		case 'd':
			if (argc != 4){
				die("Need id to delete");
			}

			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'f':
			if (argc != 4){
				die("Need name to find");
			}
			Database_find(conn,argv[3]);
			break;
		default:
			die("Invalid action: c=create, g=get, s=set, d=del, l=list");
	}

	Database_close(conn);

	return 0;
}