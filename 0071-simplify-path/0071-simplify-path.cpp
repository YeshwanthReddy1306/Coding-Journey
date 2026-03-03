class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> stack;
        string temp;
        
        stringstream ss(path);
        
        while(getline(ss, temp, '/')) {
            
            if(temp == "" || temp == ".") {
                continue;
            }
            else if(temp == "..") {
                if(!stack.empty()) {
                    stack.pop_back();
                }
            }
            else {
                stack.push_back(temp);
            }
        }
        
        string result = "";
        
        for(string dir : stack) {
            result += "/" + dir;
        }
        
        return result.empty() ? "/" : result;
    }
};