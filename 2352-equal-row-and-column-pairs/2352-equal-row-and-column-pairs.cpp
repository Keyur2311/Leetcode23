class Solution{
public:
    int equalPairs(vector<vector<int>> &grid){
        
        int ctr = 0;
        int n = (int)grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool ok = true;
                for (int k = 0; k < n; k++)
                {
                    if (grid[i][k] != grid[k][j])
                        ok = false;
                }
                if (ok)
                    ctr++;
            }
        }

        return ctr;
    }
};