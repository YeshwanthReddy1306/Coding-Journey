class Solution {
public:
    vector<string> result;

    bool isValid(string &s, int start, int len) {
        if (len > 1 && s[start] == '0') return false; // leading zero
        int num = stoi(s.substr(start, len));
        return num >= 0 && num <= 255;
    }

    void backtrack(string &s, int index, int parts, string current) {
        // If 4 parts formed
        if (parts == 4) {
            if (index == s.size()) {
                current.pop_back(); // remove last '.'
                result.push_back(current);
            }
            return;
        }

        // Try lengths 1 to 3
        for (int len = 1; len <= 3; len++) {
            if (index + len > s.size()) break;

            if (isValid(s, index, len)) {
                backtrack(s, index + len, parts + 1,
                          current + s.substr(index, len) + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return result;
    }
};