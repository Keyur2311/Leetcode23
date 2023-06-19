class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0,alt=0;
        for(auto &val:gain){
            alt+=val;
            ans=max(ans,alt);
        }
        return ans;
    }
};