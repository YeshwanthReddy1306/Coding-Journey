class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // If valid combination formed
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we still have some left
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }

        // Add ')' if it won't make invalid string
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
