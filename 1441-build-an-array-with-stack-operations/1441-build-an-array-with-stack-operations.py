class Solution(object):
    def buildArray(self, target, n):
        res = []
        target_idx = 0
        
        for num in range(1, n + 1):
            if target_idx == len(target):
                break
            
            res.append("Push")
            if num == target[target_idx]:
                target_idx += 1
            else:
                res.append("Pop")
                
        return res