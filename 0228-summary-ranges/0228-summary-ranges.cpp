class Solution {
public:

vector<string> summaryRanges(vector<int> &nums)
{
    int n = (int)nums.size();
    vector<string> ans;
     
    vector<long long int> v(n);
    for(int i=0;i<n;i++) v[i]=nums[i];
    if(n==0){
        vector<string> x(0);
        return x;
    }

    long long int left = v[0];
 

    for (int i = 1; i < n; i++)
    {
        if (i < n - 1)
        {

            if (v[i] - v[i - 1] == 1 && v[i + 1] - v[i] == 1 && left != v[i])
                continue;
            else if (v[i] - v[i - 1] == 1 && v[i + 1] - v[i] > 1 && left != v[i])
            {
                string val = to_string(left) + "->" + to_string(v[i]);
                ans.push_back(val);
                left = v[i + 1];
            }
            else if (v[i] - v[i - 1] > 1)
            {
               
                if (left == v[i] && v[i+1]-v[i]>1)
                {
                    string val = to_string(v[i]);
                    ans.push_back(val);
                    left = v[i + 1];
                }
                else if(left==v[i-1]){
                    string val = to_string(v[i-1]);
                    ans.push_back(val);
                    left = v[i];
                }
            }
        }
        else
        {
            if (left == v[i])
            {
                string val = to_string(v[i]);
                ans.push_back(val);
            }
            else
            {
                if(v[i]-v[i-1]==1){
                string val = to_string(left) + "->" + to_string(v[i]);
                ans.push_back(val);
                }
                else{
                    string val = to_string(v[i-1]);
                    ans.push_back(val);
                    val = to_string(v[i]);
                    ans.push_back(val);
                }
            }
        }
    }
    
    
    if(n==1){
         string val = to_string(v[0]);
         ans.push_back(val);
    }
    
    
    return ans;
}
};