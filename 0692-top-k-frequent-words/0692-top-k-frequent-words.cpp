class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
    int n = (int)words.size();
    map<string, int> mp;
    for (auto &word : words)
        mp[word]++;

    vector<string> ans;
    for (int i = n; i >= 1; i--)
    {
        for (auto &it : mp)
        {
            if (it.second == i)
                ans.push_back(it.first);
            if ((int)ans.size() == k)
                return ans;
        }
    }
    return ans;
    }
};