// User function Template for C++

class Solution
{
public:
    int countPaths(int N)
    {
        // code here
        if (N < 2)
        {
            return 0;
        }

        int i = 2;
        long int path = 0;
        long int mod = 1000000007;
        while (i <= N)
        {
            path = (path * 3) % mod;
            if (i % 2 == 0)
            {
                path = (path + 3) % mod;
            }
            else
            {
                path = (path - 3) % mod;
            }
            i++;
        }
        return path;
    }
};