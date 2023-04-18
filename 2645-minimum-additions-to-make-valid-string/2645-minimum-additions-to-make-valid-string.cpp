class Solution
{
public:
    int addMinimum(string s)
    {
        int n = (int)s.size();

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (s[i] == 'a')
                    continue;
                if (s[i] == 'b')
                    count += 1;
                if (s[i] == 'c')
                    count += 2;
            }
            else
            {
                if (s[i - 1] == 'a' && s[i] == 'b')
                    continue;
                if (s[i - 1] == 'b' && s[i] == 'c')
                    continue;
                if (s[i - 1] == 'a' && s[i] == 'c')
                    count += 1;
                if (s[i - 1] == 'b' && s[i] == 'a')
                    count += 1;
                if (s[i - 1] == 'c' && s[i] == 'a')
                    continue;
                if (s[i - 1] == 'c' && s[i] == 'b')
                    count += 1;
                if (s[i - 1] == 'a' && s[i] == 'a')
                    count += 2;
                if (s[i - 1] == 'b' && s[i] == 'b')
                    count += 2;
                if (s[i - 1] == 'c' && s[i] == 'c')
                    count += 2;
            }
        }

        if (s[n - 1] == 'a')
            count += 2;
        else if (s[n - 1] == 'b')
            count += 1;

        return count;
    }
};