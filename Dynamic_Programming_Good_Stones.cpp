// User function Template for C++
class Solution
{
public:
    int goodStones(int n, vector<int> &arr)
    {
        // Code here
        vector<bool> reached(n, false);
        set<int> s;
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (reached[i])
            {
                continue;
            }
            int j = i;
            while (!reached[j])
            {
                reached[j] = true;
                temp.push_back(j);
                j = j + arr[j];
                if (j >= n || j < 0)
                {
                    for (auto k : temp)
                    {
                        s.insert(k);
                    }
                    temp.clear();
                    break;
                }
            }
            if (temp.size() && s.count(j))
            {
                for (auto k : temp)
                {
                    s.insert(k);
                }
            }
            temp.clear();
        }
        return s.size();
    }
};