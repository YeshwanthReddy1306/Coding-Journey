class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        if (m == 0) return 0;
        if (m > n) return -1;

        const int base = 26;      // alphabet size
        const int mod = 1e9 + 7;  // large prime
        
        long long needleHash = 0;
        long long windowHash = 0;
        long long power = 1;

        // Compute base^(m-1)
        for (int i = 0; i < m - 1; i++)
            power = (power * base) % mod;

        // Compute initial hashes
        for (int i = 0; i < m; i++) {
            needleHash = (needleHash * base + needle[i]) % mod;
            windowHash = (windowHash * base + haystack[i]) % mod;
        }

        for (int i = 0; i <= n - m; i++) {
            
            // If hashes match, verify characters
            if (needleHash == windowHash) {
                if (haystack.substr(i, m) == needle)
                    return i;
            }

            // Slide window
            if (i < n - m) {
                windowHash = (windowHash - haystack[i] * power % mod + mod) % mod;
                windowHash = (windowHash * base + haystack[i + m]) % mod;
            }
        }

        return -1;
    }
};
