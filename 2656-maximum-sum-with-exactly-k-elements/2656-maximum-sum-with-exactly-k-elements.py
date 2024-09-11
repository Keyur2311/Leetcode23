class Solution(object):
    def maximizeSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        mx = int(0)

        for val in nums:
            mx = max(mx, val)

        n = mx + k - 1
        totn = (n * (n + 1)) / 2
        rn = mx - 1
        totr = (rn * (rn + 1)) / 2

        return totn - totr
