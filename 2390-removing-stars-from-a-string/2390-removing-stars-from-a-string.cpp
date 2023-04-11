class Solution
{
public:
    string removeStars(string s)
    {
        string ans;
        int n = (int)s.size();
        int ctr = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '*')
                ctr++;
            else
            {
                if (ctr > 0)
                    ctr--;
                else
                    ans.push_back(s[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};