/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximizeSum = function (nums, k) {

    var mx = Number(0), ans = Number(0);

    for (let val of nums)
        mx = Math.max(mx, val);

    var n = Number(mx + k - 1);
    var tot = Number((n * (n + 1)) / 2);
    var rn = mx - 1;
    var rtot = Number((rn * (rn + 1)) / 2);

    return tot - rtot;
};