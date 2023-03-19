class Solution {
public:
    int minSetSize(vector<int>& arr) {
       
        int n = arr.size();
        unordered_map<int,int> fre;
        for(auto &val:arr) 
            fre[val]++;
        
        priority_queue<int> pq;
        for(auto &it:fre) 
            pq.push(it.second);
        
        int ctr = 0,ans=0;
        while(pq.size()> 0)
        {
            ctr += pq.top();
            ans++;
            pq.pop();
            if(ctr>=(n/2)) 
                break;
        }
        
        return ans;
    }
};