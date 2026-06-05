class Solution(object):
    def earliestFinishTime(self, landStartTime, landDuration,
                           waterStartTime, waterDuration):

        ans = float('inf')

        for i in range(len(landStartTime)):
            for j in range(len(waterStartTime)):

                land_end = landStartTime[i] + landDuration[i]
                water_end = waterStartTime[j] + waterDuration[j]

                # Land -> Water
                ans = min(
                    ans,
                    max(land_end, waterStartTime[j]) + waterDuration[j]
                )

                # Water -> Land
                ans = min(
                    ans,
                    max(water_end, landStartTime[i]) + landDuration[i]
                )

        return ans
        