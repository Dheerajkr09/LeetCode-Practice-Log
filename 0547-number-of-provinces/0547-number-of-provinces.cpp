class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, int i,vector<bool> &visited,int n)
    {
        visited[i] = true;

        for(int v = 0;v < n;v++)
        {
            if(!visited[v] && isConnected[i][v] == 1)
            {
                DFS(isConnected,v,visited,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();

        vector<bool> visited(n,false);

        int count = 0;
        for(int i = 0;i < n;i++)
        {
            if(!visited[i])
            {
                DFS(isConnected,i,visited,n);
                count++;
            }
        }
        return count;

        
    }
};