// User function Template for C++

class Solution
{
public:
    pair<int, int> endPoints(vector<vector<int>> matrix, int R, int C)
    {
        // code here
        int i = 0;
        int j = 0;
        pair<int, int> hold = {0, 0};
        char dir = 'r';

        while (i < R && i >= 0 && j < C && j >= 0)
        {
            if (matrix[i][j] == 0)
            {
                hold = {i, j};
                if (dir == 'r')
                {
                    j++;
                }
                else if (dir == 'l')
                {
                    j--;
                }
                else if (dir == 'u')
                {
                    i--;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                matrix[i][j] = 0;
                if (dir == 'u')
                {
                    hold = {i, j};
                    j++;
                    dir = 'r';
                }
                else if (dir == 'r')
                {
                    hold = {i, j};
                    i++;
                    dir = 'd';
                }
                else if (dir == 'd')
                {
                    hold = {i, j};
                    j--;
                    dir = 'l';
                }
                else
                {
                    hold = {i, j};
                    i--;
                    dir = 'u';
                }
            }
        }
        return hold;
    }
};