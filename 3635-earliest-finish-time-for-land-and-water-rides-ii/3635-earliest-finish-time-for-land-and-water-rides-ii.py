from bisect import bisect_right

class Solution:
    def earliestFinishTime(self,
                           landStartTime,
                           landDuration,
                           waterStartTime,
                           waterDuration):

        INF = float('inf')

        def solve(firstStart, firstDur,
                  secondStart, secondDur):

            rides = sorted(zip(secondStart, secondDur))

            starts = [s for s, d in rides]

            m = len(rides)

            pref = [0] * m
            pref[0] = rides[0][1]

            for i in range(1, m):
                pref[i] = min(pref[i - 1], rides[i][1])

            suff = [0] * m
            suff[m - 1] = rides[m - 1][0] + rides[m - 1][1]

            for i in range(m - 2, -1, -1):
                suff[i] = min(
                    suff[i + 1],
                    rides[i][0] + rides[i][1]
                )

            ans = INF

            for s, d in zip(firstStart, firstDur):

                finish_first = s + d

                idx = bisect_right(starts, finish_first)

                if idx > 0:
                    ans = min(
                        ans,
                        finish_first + pref[idx - 1]
                    )

                if idx < m:
                    ans = min(
                        ans,
                        suff[idx]
                    )

            return ans

        return min(
            solve(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration
            ),
            solve(
                waterStartTime,
                waterDuration,
                landStartTime,
                landDuration
            )
        )