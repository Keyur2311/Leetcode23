class Solution{
public:
   string simplifyPath(string path)
    {
        int n = (int)path.size();
        vector<string> v;

        for (int i = 0; i < n; i++)
        {
            if (path[i] == '/')
                continue;

            string x = "";
            string a = ".", b = "..", c = "...";
            while (i < n && path[i] != '/')
                x += path[i], i++;
            if (x == a)
                continue;
            else if (x == b)
            {
                if ((int)v.size() > 0)
                    v.pop_back();
            }
            else
                v.push_back(x);
        }

        string ans = "/";
        for (int i = 0; i < (int)v.size(); i++)
        {
            ans = ans + v[i];
            if (i != (int)v.size() - 1)
                ans += '/';
        }
        return ans;
    }
};