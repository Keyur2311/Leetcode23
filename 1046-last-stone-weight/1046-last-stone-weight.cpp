class Solution{
public:
    int lastStoneWeight(vector<int> &stones){
        
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (x != y)
                pq.push(y - x);
        }

        int ans = 0;
        if (pq.size() > 0)
            ans = pq.top();
        
        return ans;
    }
};