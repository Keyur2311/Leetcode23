/**
 * @param {number[]} nums
 * @return {number}
 */
var tupleSameProduct = function (nums) {
    let freq = {}

    let n = nums.length

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            let prod = nums[i] * nums[j]
            if (freq[prod]) freq[prod] += 1;
            else freq[prod] = 1
        }
    }

    let ans = Number(0)

    for (key in freq) {
        let fr = freq[key]
        let x = Number((fr * (fr - 1)) / 2)
        ans += x * 8
    }
    return ans;
};