class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> result;
        int n = words.size();
        int i = 0;
        
        while (i < n) {
            
            int j = i;
            int lineLength = 0;
            
            // 1️⃣ Pick words greedily
            while (j < n && lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }
            
            int totalSpaces = maxWidth - lineLength;
            int slots = j - i - 1;
            
            string line = "";
            
            // 2️⃣ Last line OR single word
            if (j == n || slots == 0) {
                
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1)
                        line += " ";
                }
                
                // Fill remaining spaces at end
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                // 3️⃣ Fully justified line
                
                int evenSpaces = totalSpaces / slots;
                int extraSpaces = totalSpaces % slots;
                
                for (int k = i; k < j; k++) {
                    line += words[k];
                    
                    if (k < j - 1) {
                        int spaces = evenSpaces;
                        if (extraSpaces > 0) {
                            spaces++;
                            extraSpaces--;
                        }
                        line += string(spaces, ' ');
                    }
                }
            }
            
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};