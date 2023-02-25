class Solution
{
    int mod = 1e9 + 7;

public:
    int uniquePaths(int r, int f3, vector<vector<int>> &grid)
    {
        if (grid[0][0] == 0 or grid[r - 1][f3 - 1] == 0)
        {
            return 0;
        }
        int dp[r][f3];
        dp[0][0] = 1;
        // fill the first row
        for (int p = 1; p < f3; p++)
        {
            if (grid[0][p] == 0)
            {
                dp[0][p] = 0;
            }
            else
            {
                dp[0][p] = dp[0][p - 1];
            }
        }
        // fill the first col
        for (int p = 1; p < r; p++)
        {
            if (grid[p][0] == 0)
            {
                dp[p][0] = 0;
            }
            else
            {
                dp[p][0] = dp[p - 1][0];
            }
        }
        // fill the rest
        for (int f1 = 1; f1 < r; f1++)
        {
            for (int f2 = 1; f2 < f3; f2++)
            {
                if (grid[f1][f2] == 0)
                {
                    dp[f1][f2] = 0;
                }
                else
                {
                    dp[f1][f2] = (dp[f1 - 1][f2] % mod + dp[f1][f2 - 1] % mod) % mod;
                }
            }
        }
        return dp[r - 1][f3 - 1] % mod;
    }
};






             vector<pair<int, int>> times;

        

    for (int i = 0; i < n; i++) times.push_back({finish[i], start[i]});

    sort(times.begin(), times.end());

    

    

    int ans = 1;

    

    

   int phle=times[0].first;

   for(int i=1;i<n;i++){

      int currst=times[i].second;

       if(phle<currst){

           ans++; 
           phle=times[i].first;

          

       }

   }

    return ans;