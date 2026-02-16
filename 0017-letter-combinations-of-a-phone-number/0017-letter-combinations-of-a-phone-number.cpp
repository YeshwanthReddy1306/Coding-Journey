class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        vector<string> result;
        
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        
        string current = "";
        backtrack(digits, 0, current, result, mp);
        return result;
    }
    
    void backtrack(string &digits, int index, string &current,
                   vector<string> &result,
                   unordered_map<char,string> &mp) {
        
        if(index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        for(char ch : mp[digits[index]]) {
            current.push_back(ch);
            backtrack(digits, index + 1, current, result, mp);
            current.pop_back();  // backtrack
        }
    }
};
