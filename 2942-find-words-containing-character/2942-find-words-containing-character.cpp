class Solution {
public:
  vector<int> findWordsContaining(vector<string> &words, char x) {

    int i = 0;
    vector<int> ans;

    for (auto word : words) {
      if (word.find(x) != string::npos)
        ans.push_back(i);
      i++;
    }

    return ans;
  }
};