class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        m = len(nums1)
        n = len(nums2)
        half = (m + n + 1) // 2

        left = 0
        right = m

        while left <= right:
            i = (left + right) // 2
            j = half - i

            l1 = nums1[i-1] if i > 0 else float('-inf')
            r1 = nums1[i] if i < m else float('inf')
            l2 = nums2[j-1] if j > 0 else float('-inf')
            r2 = nums2[j] if j < n else float('inf')

            if l1 <= r2 and l2 <= r1:
                if (m + n) % 2 == 0:
                    return (max(l1, l2) + min(r1, r2)) / 2.0
                return max(l1, l2)

            elif l1 > r2:
                right = i - 1
            else:
                left = i + 1