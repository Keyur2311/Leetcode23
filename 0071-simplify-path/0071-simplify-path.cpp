class Solution{
public:
    string simplifyPath(string path)
    {
        int n = (int)path.size();
        stack<string> st;

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
                if (!st.empty())
                    st.pop();
            }
            else
                st.push(x);
        }
        vector<string> v;
        while (st.size() > 0)
        {
            string tp = st.top();
            st.pop();
            v.push_back(tp);
        }
        reverse(v.begin(), v.end());

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