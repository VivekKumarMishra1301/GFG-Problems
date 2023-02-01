// User function Template for C++

class Solution
{
public:
    long long int distinctColoring(int N, int r[], int g[], int b[])
    {
        // code here
        vector<vector<long long int>> hold(N, vector<long long int>(3, -1));
        hold[0][0] = r[0];
        hold[0][1] = g[0];
        hold[0][2] = b[0];
        for (int i = 1; i < N; i++)
        {
            hold[i][0] = r[i] + min(hold[i - 1][1], hold[i - 1][2]);
            hold[i][1] = g[i] + min(hold[i - 1][0], hold[i - 1][2]);
            hold[i][2] = b[i] + min(hold[i - 1][0], hold[i - 1][1]);
        }

        return min(hold[N - 1][0], min(hold[N - 1][1], hold[N - 1][2]));
    }
};