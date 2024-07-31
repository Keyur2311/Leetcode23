class Solution {
public:
  int majorityElement(vector<int> &nums) {
     
      int curr = -1,votes=0;
      for(auto val:nums){
          if(votes==0){
              curr=val;
              votes=1;
          }else{
              if(curr==val) votes++;
              else votes--;
          }
      }
         return curr;
  }
 
};