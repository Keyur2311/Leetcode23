class Solution{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker){
        int n = (int)profit.size();
        int m = (int)worker.size();
        
         auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first < b.first)
                return true;
            else if (a.first == b.first && a.second > b.second)
                return true;
            else
                return false;
        };

        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; i++)
            vp[i] = {difficulty[i], profit[i]};

        sort(vp.begin(), vp.end(), cmp);

        for (int i = 1; i < n; i++)
            vp[i].second = max(vp[i].second, vp[i - 1].second);

        int ans = 0;

        for (int i = 0; i < m; i++){
            if (worker[i] < vp[0].first)
                continue;
            int x = worker[i];
            if (x > vp[n - 1].first)
                x = vp[n - 1].first;
            
            pair<int, int> p = {x, INT_MIN};
            auto it = lower_bound(vp.begin(), vp.end(), p) - vp.begin();
            if (vp[it].first > worker[i])
                it--;
            ans += vp[it].second;
        }

        return ans;
    }
};