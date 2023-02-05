class Solution {
public:
    string frequencySort(string s) {
        
    int n = s.length();
    map<char, int> mp;
    for (auto &it : s)
        mp[it]++;

    vector<pair<int, char>> vp;
    for (auto &it : mp)
        vp.push_back({it.second, it.first});
    sort(vp.rbegin(), vp.rend());

    int j = 0;
    int fre = vp[j].first;
    for (int i = 0; i < n; i++)
    {
       if (fre == 0)
        {
            if(j<(int)vp.size()){
            j++;
            fre = vp[j].first;
            }
        }
        s[i] = vp[j].second;
        fre--;
      
    }
    return s;
    }
};