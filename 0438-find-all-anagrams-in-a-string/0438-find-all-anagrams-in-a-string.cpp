class Solution {
public:
   vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;
    int n1 = s.length(), n2 = p.length();
    if (n2 > n1)
        return ans;
    vector<int> v1(26, 0), v2(26, 0);
    for (auto &c : p)
        v2[c - 'a'] += 1;

    for (int i = 0; i < n2; i++)
        v1[s[i] - 'a'] += 1;

    if (v1 == v2)
        ans.push_back(0);

    for (int i = 1; i < n1 - n2 + 1; i++)
    {
        v1[s[i - 1] - 'a'] -= 1;
        v1[s[i + n2 - 1] - 'a'] += 1;

        if (v1 == v2)
            ans.push_back(i);
    }
    return ans;
}
};