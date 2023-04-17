//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution
{
public:
    vector<int> JobScheduling(Job arr[], int n)
    {
        int mx_jobs = 0;
        for (int i = 0; i < n; i++)
            mx_jobs = max(mx_jobs, arr[i].dead);

        priority_queue<int> pq[mx_jobs+1];
        vector<int> ans = {0, 0};

        for (int i = 0; i < n; i++)
        {
            int deadline = arr[i].dead;
            int profit = arr[i].profit;

            pq[deadline].push(profit);
        }

        for (int i = mx_jobs; i >= 1; i--)
        {
            if (pq[i].empty())
                continue;
            ans[0] += 1;
            ans[1] += pq[i].top();
            pq[i].pop();
            while (!pq[i].empty() && i!=1)
            {
                pq[i - 1].push(pq[i].top());
                pq[i].pop();
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends