class Solution(object):
    def minimumCost(self, cost):
        cost.sort(reverse=True)

        ans = 0

        for i in range(len(cost)):
            if i % 3 != 2:      # every 3rd candy is free
                ans += cost[i]

        return ans
        