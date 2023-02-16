// User function Template for C++

class Solution
{

public:
    int n, m;

    vector<vector<int>> lab;

    void dfs(int i, int j, vector<vector<int>> &mat, int prevval, int label)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || lab[i][j] & label) // if the current(i,j) is already visited so it will give label as outputnon doing and operation with the the value of the index which can act as sign of already visited current place with the given label to stop;
            return;

        int currentval = mat[i][j];

        if (currentval >= prevval) // we are going from shore to inside the land mass so we will check if the current point on which we are standing has been achieved by us from a lesser previous point
        {
            lab[i][j] = lab[i][j] | label;

            dfs(i + 1, j, mat, currentval, label);
            dfs(i - 1, j, mat, currentval, label);
            dfs(i, j - 1, mat, currentval, label);
            dfs(i, j + 1, mat, currentval, label);
        }
    }

    int water_flow(vector<vector<int>> &mat, int N, int M)
    {
        // Write your code here.
        n = N;
        m = M;

        int count = 0;

        lab.resize(n, vector<int>(m, 0));

        // label:1 for arabian sea (left and top)
        // label:2 for indian ocean (right and bottom)
        // label:3 for both arabian and indian ocean(both the oceans can be visited using this index(i,j))

        for (int i = 0; i < n; i++)
        {
            dfs(i, 0, mat, mat[i][0], 1);
            dfs(i, M - 1, mat, mat[i][M - 1], 2);
        }

        for (int j = 0; j < m; j++)
        {
            dfs(0, j, mat, mat[0][j], 1);
            dfs(N - 1, j, mat, mat[N - 1][j], 2);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (lab[i][j] == 3)
                {
                    count++;
                }
            }
        }

        return count;
    }
    // public:

    // bool valid(int i,int j,vector<vector<bool>>&vis,int prev,vector<vector<int>>&mat){
    //     int n=vis.size();
    //     int m=vis[0].size();
    //     return i>=0&&j>=0&&i<n&&j<m!vis[i][j]&&prev<=mat[i][j];
    // }

    //     int water_flow(vector<vector<int>> &mat,int n,int m){
    //     // Write your code here.

    //     queue<pair<int,int>>q;
    //     vector<vector<bool>>vis(n,vector<bool>(m,false));
    //     for(int i=0;i<m;i++){
    //         q.push({0,i});
    //         vis[0][i]=1;

    //     }

    //     for(int i=1;i<n;i++){
    //         q.push({i,0});
    //         vis[i][0]=1;
    //     }
    //     map<pair<int,int>,int>indian;
    //     while(!q.empty()){
    //         pair<int,int>p=q.front();
    //         int i=p.first,j=p.second;
    //         q.pop();
    //         indian[{i,j}]=true;
    //         vis[i][j]=true;
    //         if(valid(i+1,j,vis,mat[i][j],mat)){
    //             vis[i+1][j]=true;
    //             q.push({i+1,j});

    //         }
    //          if(valid(i-1,j,vis,mat[i][j],mat)){
    //             vis[i-1][j]=true;
    //             q.push({i-1,j});

    //         }

    //     }
    //     vector<vector<bool>>vi(n,vector<bool>(m,false));
    //     for(int i=0;i<n;i++){
    //         q.push({i,m-1});
    //         vi[i][m-1]=true;
    //     }
    //     for(int j=0;j<m-1;j++){
    //         q.push({n-1,j});
    //         vi[n-1][j]=1;

    //     }
    //     int hold=0;
    //     while(!q.empty()){
    //         pair<int,int>p=q.front();
    //         int i=p.first;
    //         int j=p.second;
    //         q.pop();
    //         if(indian[{i,j}]){
    //             hold++;
    //         }
    //         v[i][j]=true;
    //         if(valid(i+1,j,vi,mat[i][j],mat)){
    //             vi[i+1][j]=true;
    //             q.push({i+1,j});

    //         }
    //     }

    //     // vector<int>row;
    //     // vector<int>col;
    //     // vector<vector<bool>>trans(n,vector<bool>(m,false));
    //     // for(int i=0;i<m;i++){
    //     //     vector<int>k;
    //     //     // trans.push_back(m);
    //     //     int num=mat[0][i];
    //     //     for(int j=0;j<n;j++){
    //     //       num=max(num,mat[j][i]);
    //     //     }
    //     //     // trans.push_back(k);
    //     //     col.push_back(num);
    //     // }

    //     // for(int i=0;i<n;i++){
    //     //     int k=*max(mat[i].begin(),mat[i].end());
    //     //     row.push_back(k);
    //     // }

    //     // // for(int i=0;i<m;i++){
    //     // //     row.push_back(*max(trans[i].begin(),trans[i].end()));
    //     // // }

    //     // int hold=0;
    //     //  for(int i=0;i<n;i++){
    //     //     for(int j=0;j<m;j++){
    //     //       if(mat[i][j]==row[i]||mat[i][j]==col[j]||(j>0&&trans[i][j-1]&&mat[i][j]==mat[i][j-1])||(i==n-1&&j==0)){
    //     //           trans[i][j]=true;
    //     //           hold++;
    //     //       }
    //     //     }
    //     // }
    //     // return hold;

    //     }
};
