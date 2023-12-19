nums = [0,1,2,2,3,0,4,2]

next_pos = 0

val = 2 

for i in range (0,len(nums)) : 
    
    if nums[i] != val : 
        
        nums[next_pos] = nums[i]
        
        next_pos += 1 
        
        
for i in range (next_pos, len(nums)) : 
    
    nums[i] = '_'

print(nums)        
print(next_pos)