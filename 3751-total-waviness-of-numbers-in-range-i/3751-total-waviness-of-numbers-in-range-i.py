class Solution:
    def totalWaviness(self, num1, num2):

        def waviness(num):
            digits = [int(d) for d in str(num)]

            if len(digits) < 3:
                return 0

            count = 0

            for i in range(1, len(digits) - 1):
                if digits[i] > digits[i - 1] and digits[i] > digits[i + 1]:
                    count += 1
                elif digits[i] < digits[i - 1] and digits[i] < digits[i + 1]:
                    count += 1

            return count

        ans = 0

        for num in range(num1, num2 + 1):
            ans += waviness(num)

        return ans