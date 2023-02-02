// User function Template for C++
class Solution
{
public:
    long long largestSumCycle(int N, vector<int> Edge)
    {
        // code here
        vector<int> counter(N, 0);
        for (auto i : Edge)
        {
            if (i == -1)
            {
                continue;
            }
            counter[i]++;
        }

        queue<int> q;
        vector<int> visited(N, false);
        for (int i = 0; i < N; i++)
        {
            if (counter[i] == 0)
            {
                visited[i] = true;
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            int par = Edge[current];
            if (par == -1)
            {
                continue;
            }
            --counter[par];
            if (counter[par] == 0)
            {
                q.push(par);
                visited[par] = true;
            }
        }

        int hold = -1;
        for (int i = 0; i < N; i++)
        {
            if (visited[i])
            {
                continue;
            }

            int val = 0;
            for (int st = i; visited[st] == false; st = Edge[st])
            {
                val += st;
                visited[st] = true;
            }
            hold = max(hold, val);
        }
        return hold;
    }
};