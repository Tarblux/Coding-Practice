from collections import deque

class solution:
    
    def __init__(self):
        
        self.visited = set()
        
    def neighbors(self,matrix,r,c):
        
        directions = [(-1,0),(1,0),(0,-1),(0,1)]
        
        for dr , dc in directions:
            
            nr = r + dr
            nc = c + dc
            
            if  0 <= nr < len(matrix) and 0 <= nc < len(matrix[0]):
                yield (nr,nc)
    
    def bfs(self,matrix):
        
        output = 0
        
        if not matrix:
            return None
        
        queue = deque([(0,0)])
        
        while queue:
            
            r , c = queue.popleft()
            
            if (r,c) in self.visited:
                continue
            
            self.visited.add((r,c))
            
            if matrix[r][c] == 1:
                output += 1
            
            for n in self.neighbors(matrix,r,c):
                
                if n not in self.visited:
                    queue.append(n)
                
        return output
                
        
        
data  = [[0,0,1,1],
         [0,0,0,1],
         [0,0,0,1],
         [0,0,0,0]]   

test = solution() 
test.bfs(data)
