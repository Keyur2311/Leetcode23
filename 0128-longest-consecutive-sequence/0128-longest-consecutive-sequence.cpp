class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_map<int, bool> mp;
    for (int i = 0; i < nums.size(); i++) {
      mp[nums[i]] = true;
    }
    
    for (int i = 0; i < nums.size(); i++) {
      if (mp.count(nums[i] - 1) > 0) {
        mp[nums[i]] = false;
      }
    }

    int maxlen = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (mp[nums[i]] == true) {
        int j = 0;
        int count = 0;
        while (mp.count(nums[i] + j) > 0) {
          j++;
          count++;
        }
        if (count > maxlen) {
          maxlen = count;
        }
      }
    }
    return maxlen;
  }
};