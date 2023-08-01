class Solution {
public:
  void generateCombinations(int i, int n, int k, vector<int> &chosen,
                            vector<vector<int>> &combs) {
    if (chosen.size() == k) {
      combs.push_back(chosen);
      return;
    }
      
    if(i > n) return;
      
    chosen.push_back(i);
    generateCombinations(i + 1, n, k, chosen, combs);

    chosen.pop_back();
    generateCombinations(i + 1, n, k, chosen, combs);
  }

  vector<vector<int>> combine(int n, int k) {
    vector<int> chosen;
    vector<vector<int>> combs;
    generateCombinations(1, n, k, chosen, combs);
    return combs;
  }
};