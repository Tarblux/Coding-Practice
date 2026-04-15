# The old problematic way 

file = open('stuff.txt',"r")

for line in file:
    print(line)

# This does nothing cuz the iterator is already exhausted
for line in file:
    print(line)


file.close()

