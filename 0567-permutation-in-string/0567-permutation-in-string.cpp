class Solution {
public:
bool checkInclusion(string s1, string s2)
{

    int n1 = s1.length(), n2 = s2.length();
    if (n1 > n2)
        return false;
    vector<int> v1(26, 0), v2(26, 0);
    for (auto &c : s1)
        v1[c - 'a'] += 1;

    for (int i = 0; i < n1; i++)
        v2[s2[i] - 'a'] += 1;

    if (v1 == v2)
        return true;

    for (int i = 1; i < n2 - n1 + 1; i++)
    {
        v2[s2[i - 1] - 'a'] -= 1;
        v2[s2[i + n1 - 1] - 'a'] += 1;

        if (v1 == v2)
            return true;
    }

    return false;
}

};