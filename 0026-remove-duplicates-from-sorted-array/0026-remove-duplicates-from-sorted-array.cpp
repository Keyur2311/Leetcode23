class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(auto &it:nums) st.insert(it);
        int k = (int)st.size();
        for(int i=0;i<k;i++){
            nums[i]=*st.begin();
            st.erase(st.begin());
        }
        
        for(int i=k;i<(int)nums.size();i++) nums[i]=0;
        
        return k;
    }
};