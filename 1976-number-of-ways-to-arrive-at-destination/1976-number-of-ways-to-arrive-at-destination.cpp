class Solution {
public:
    int countPaths(int n, vector<vector<int>> &roads) {
        vector<pair<long long, long long>> adj[n];
        for (auto road : roads) {
            long long a = road[0];
            long long b = road[1];
            long long time = road[2];
            adj[a].push_back({b, time});
            adj[b].push_back({a, time});
        }

        vector<long long> dist(n, LLONG_MAX), ways(n, 0);
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>> pq;

        pq.push({0, 0}); // {distance, node}
        dist[0] = 0;
        ways[0] = 1;
        int M = (int)1e9 + 7;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            long long currdist = curr.first;
            long long currnode = curr.second;

            if (currdist > dist[currnode]) continue;

            for (auto child : adj[currnode]) {
                long long childnode = child.first;
                long long childdist = child.second;

                if (dist[childnode] > currdist + childdist) {
                    dist[childnode] = currdist + childdist;
                    ways[childnode] = ways[currnode] % M;
                    pq.push({dist[childnode], childnode});
                } else if (dist[childnode] == currdist + childdist) {
                    ways[childnode] = (ways[childnode] % M + ways[currnode] % M) % M;
                }
            }
        }

        return ways[n - 1] % M;
    }
};
