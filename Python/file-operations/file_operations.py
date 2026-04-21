# The old problematic way 

file = open('stuff.txt',"r")

for line in file:
    print(line)

# This does nothing cuz the iterator is already exhausted
for line in file:
    print(line)

# Flushes the buffer and makes sure that we don't corrupt the file
file.close()

# We can do relative and absolute paths if we need things from other directories

file_2 = open("random_directory/other_file.txt","r")
file_21 = open("/Users/twilliams/.cdprct/Coding Practice/Python/file-operations/random_directory/other_file.txt","r")

line1 = next(file_2)
print(line1)

# I was just being lazy so I did multiple assignment and then just tossed the first line since I just wanted the second
toss ,line2 = next(file_21) , next(file_21)
print(line2)

file_2.close()
file_21.close()

# -------NEW WAY TO DO FILE OPERATIONS------------
# The old way is problematic because you always have to close the file

with open("stuff.txt","r") as f:
    print("NEW WAY")
    for line in f:
        print(line)








