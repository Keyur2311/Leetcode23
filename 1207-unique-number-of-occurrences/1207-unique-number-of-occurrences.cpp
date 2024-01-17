class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    int n = (int)arr.size();
    map<int, int> mp;
    for (auto val : arr)
      mp[val]++;

    map<int, int> fr;
    for (auto it : mp)
      fr[it.second]++;

    for (auto it : fr) {
      if (it.second != 1)
        return false;
    }

    return true;
  }
};