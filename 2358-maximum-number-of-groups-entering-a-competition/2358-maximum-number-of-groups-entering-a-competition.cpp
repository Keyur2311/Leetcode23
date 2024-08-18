class Solution {
public:
  int maximumGroups(vector<int> &grades) {
    int n = (int)grades.size();

    sort(grades.begin(), grades.end());

    int ans = 0, currcount = 0, prevcount = 0, currsum = 0, prevsum = 0;
    for (int i = 0; i < n; i++) {
      currcount++;
      currsum += grades[i];
      if (currcount > prevcount && currsum > prevsum) {
        ans++;
        prevcount = currcount, prevsum = currsum;
        currcount = 0, currsum = 0;
      }
    }

    return ans;
  }
};

// 3 5 6 7 10 12
