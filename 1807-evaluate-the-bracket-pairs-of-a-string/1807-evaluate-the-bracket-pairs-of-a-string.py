class Solution(object):
    def evaluate(self, s, knowledge):
        mapping = dict(knowledge)
        res = []
        key = []
        in_bracket = False
        
        for ch in s:
            if ch == '(':
                in_bracket = True
            elif ch == ')':
                in_bracket = False
                res.append(mapping.get("".join(key), "?"))
                key = []
            elif in_bracket:
                key.append(ch)
            else:
                res.append(ch)
                
        return "".join(res)