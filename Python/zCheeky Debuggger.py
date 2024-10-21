from typing import List


# Combination sum 

class Solution:
    def backtrack3(self, result, cur: List[int], curSum: int, lastIndex: int, target: int, candidates: List[int]):
        if curSum == target:
            result.append(cur.copy())
            return
        elif curSum > target:
            return
        
        for i in range(lastIndex, len(candidates)):
            cur.append(candidates[i])
            curSum += candidates[i]
            self.backtrack3(result, cur, curSum, i, target, candidates)

            cur.pop()
            curSum -= candidates[i]
        

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        self.backtrack3(result, [], 0, 0,  target, candidates)
        return result
    
# Combination sum II

class Solution:
    def backtrack(self, candidates, target, res, cur, s, lastIdx):
        if s == target:
            res.append(cur.copy())
        elif s > target:
            return
        
        for i in range(lastIdx + 1, len(candidates)):
            if i > lastIdx + 1 and candidates[i] == candidates[i - 1]:
                continue
            
            cur.append(candidates[i])
            s += candidates[i]

            self.backtrack(candidates, target, res, cur, s, i)

            cur.pop()
            s -= candidates[i]

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []
        self.backtrack(candidates, target, res, [], 0, -1)
        return res
    
# Generate Parentheses

class Solution:
    def backtrack2(self, result, cur: List[str], n: int, left: int, right: int):
        # Stopping point
        if len(cur) == n * 2:
            result.append(''.join(cur))

        if left < n:
            cur.append("(")
            self.backtrack2(result, cur , n, left + 1, right)
            cur.pop()
            
        if right < left:
            cur.append(")")
            self.backtrack2(result, cur, n, left, right + 1)
            cur.pop()
    
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        self.backtrack2(result, [], n, 0, 0)
        return result
        
#Subsets

class Solution:
    def backtrack6(self, result, cur, lastDigit, nums):
        if len(cur) <= len(nums):
            result.append(cur.copy())
        else:
            return

        for i in range(lastDigit + 1, len(nums)):
            cur.append(nums[i])
            self.backtrack6(result, cur, i, nums)
            cur.pop()


    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        self.backtrack6(result, [], -1, nums)
        return result
    
# N- Queens

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def backtrack(res, matrix: List[str], r: int, hori, diaglr, diagrl):
            if r >= n:
                res.append(matrix.copy())
                return
                
            for i in range(n):
                lr, rl = r - i + 3, r + i
                checkHori = hori[i]

                checkDiaglr = diaglr[lr]
                checkDiagrl = diagrl[rl]

                
                if checkHori and checkDiaglr and checkDiagrl:
                    hori[i], diaglr[lr], diagrl[rl] = False, False, False
                    newR = "." * i + "Q" + "." * (n - (i + 1))
                    matrix.append(newR)

                    backtrack(res, matrix, r + 1, hori, diaglr, diagrl)

                    hori[i], diaglr[lr], diagrl[rl] = True, True, True
                    matrix.pop()

        hori = [True for _ in range(n)]
        diaglr, diagrl = [True for _ in range(4 * n)], [True for _ in range(4 * n)]
        # print(diaglr, diagrl)
        res, matrix = [], []
        backtrack(res, matrix, 0, hori, diaglr, diagrl)

        return res