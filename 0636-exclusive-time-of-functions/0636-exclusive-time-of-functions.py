class Solution(object):
    def exclusiveTime(self, n, logs):
        res = [0] * n
        stack = []
        prev_time = 0
        
        for log in logs:
            fn_id, action, timestamp = log.split(":")
            fn_id = int(fn_id)
            timestamp = int(timestamp)
            
            if action == "start":
                if stack:
                    res[stack[-1]] += timestamp - prev_time
                stack.append(fn_id)
                prev_time = timestamp
            else:
                res[stack.pop()] += timestamp - prev_time + 1
                prev_time = timestamp + 1
                
        return res