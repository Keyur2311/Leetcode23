class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        freq = {}
        sz = len(nums)

        for i in range(0,sz):
            for j in range(i+1,sz):
                x = nums[i]
                y = nums[j]
                if x != y:
                    prod = x * y
                    if prod in freq:
                        freq[prod] += 1
                    else:
                        freq[prod] = 1

        ans = int(0)
        for key, val in freq.items():
            x = int((val * (val - 1)) / 2)
            ans += x * 8
        
        return ans
