class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = (int)nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        int ctr1 = 0;
        for(auto &it:mp){
            ctr1+=(it.second/2);
        }
        int ctr2 = n - ctr1*2;
        vector<int> ans ={ctr1,ctr2};
        return ans;
    }
};