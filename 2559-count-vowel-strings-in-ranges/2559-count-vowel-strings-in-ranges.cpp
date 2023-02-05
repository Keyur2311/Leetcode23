class Solution {
public:
    bool isVowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
{
    int n = (int)words.size();
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (isVowel(words[i][0]) && isVowel(words[i][(int)words[i].size() - 1]))
            dp[i + 1] += 1;
        dp[i + 1] += dp[i];
    }
    vector<int> ans;
    for (int i = 0; i < (int)queries.size(); i++)
    {
        int st = queries[i][0];
        int end = queries[i][1];
        st++, end++;
        if (st == 1)
            ans.push_back(dp[end]);
        else
            ans.push_back(dp[end] - dp[st - 1]);
    }
    return ans;
}
};