class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<pair<int,int>> vp;
        int n = nums.size();
        for(int i=0;i<n;i++) vp.push_back({nums[i],i});
        sort(vp.begin(),vp.end());
        int l =0,r=n-1;
        vector<int> ans;
        while(l<r){
            if(vp[l].first+vp[r].first==target){
                ans.push_back(vp[l].second);
                ans.push_back(vp[r].second);
                break;
            }
            else if(vp[l].first+vp[r].first<target){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};
