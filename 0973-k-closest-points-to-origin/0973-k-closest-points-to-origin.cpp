class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
         int n = points.size();
    for (int i = 0; i < n; i++)
    {
        int x = points[i][0];
        int y = points[i][1];

        int dis = x * x + y * y;

        pq.push({dis, {x, y}});
        if (pq.size() > k)
            pq.pop();
    }

    vector<vector<int>> v(k, vector<int>(2));

    for (int i = 0; i < k; i++)
    {
        v[i][0] = pq.top().second.first;
        v[i][1] = pq.top().second.second;
        pq.pop();
    }

    return v;
    }
};