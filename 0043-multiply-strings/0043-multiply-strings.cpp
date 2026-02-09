class Solution {
public:
    string multiply(string num1, string num2) {
        // If either number is "0", result is "0"
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();

        // Result can have at most n + m digits
        vector<int> result(n + m, 0);

        // Multiply digits from right to left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;   // current digit
                result[i + j] += sum / 10;      // carry
            }
        }

        // Convert result array to string
        string ans = "";
        int i = 0;

        // Skip leading zeros
        while (i < result.size() && result[i] == 0) i++;

        for (; i < result.size(); i++) {
            ans.push_back(result[i] + '0');
        }

        return ans;
    }
};
