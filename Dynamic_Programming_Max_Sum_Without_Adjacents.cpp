// User function template for C++
class Solution
{
public:
    // calculate the maximum sum with out adjacent

    int find(int *arr, int ind, vector<int> &dp)
    {
        if (ind < 0)
        {
            return 0;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        return dp[ind] = max(arr[ind] + find(arr, ind - 2, dp), find(arr, ind - 1, dp));
    }

    int findMaxSum(int *arr, int n)
    {
        // code here

        vector<int> dp(n, -1);
        return find(arr, n - 1, dp);
    }
};