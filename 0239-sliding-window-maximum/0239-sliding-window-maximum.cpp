class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int n = (int)v.size();
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < k; i++)
    {
        while ((!dq.empty()) && v[i] >= v[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    ans.push_back(v[dq.front()]);
    for (int i = 1; i < n - k + 1; i++)
    {

        while ((!dq.empty()) && dq.front() == i - 1)
            dq.pop_front();
        while ((!dq.empty()) && v[i + k - 1] >= v[dq.back()])
            dq.pop_back();
        dq.push_back(i + k - 1);
        ans.push_back(v[dq.front()]);
    }
        
        return ans;
        
    }
};