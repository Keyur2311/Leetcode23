class Solution {
public:
   bool compare(string a, string b, map<char, int> mp)
{
    if (a == b)
        return true;
    for (int i = 0; i < min(a.length(), b.length()); i++)
    {
        if(mp[a[i]] < mp[b[i]]) return true;
        if (mp[b[i]] < mp[a[i]])
            return false;
    }
    if (a.length() > b.length())
        return false;

    return true;
}
bool isAlienSorted(vector<string> &words, string order)
{
    map<char, int> mp;
    for (int i = 0; i < 26; i++)
        mp[order[i]] = i;

    for (int i = 0; i < (int)words.size() - 1; i++)
    {
        if (!compare(words[i], words[i+1], mp))
            return false;
    }
    return true;
}
};