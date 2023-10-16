class Solution {
public:
    vector<int> searchRange(vector<int>& v, int target) {
        vector<int> ans = {-1,-1};
        ans[0] = firstIndex(v,target);
        ans[1] = lastIndex(v,target);
        
        return ans;
    }
    
    int firstIndex(vector<int> &v,int target){
        int n = (int)v.size();
        int l = 0,r=n-1,mid;
        int idx = -1;
        while(l<=r){
            mid = l+(r-l)/2;
            if(v[mid]==target){
                idx = mid;
                r=mid-1;
            }else if(v[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return idx;
    }
    int lastIndex(vector<int> &v,int target){
         int n = (int)v.size();
        int l = 0,r=n-1,mid;
        int idx = -1;
        while(l<=r){
            mid = l+(r-l)/2;
            if(v[mid]==target){
                idx = mid;
                l=mid+1;
            }else if(v[mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return idx;
    }
};