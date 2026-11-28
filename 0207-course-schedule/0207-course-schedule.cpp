class Solution {
public:
    bool topological_sort_courses(unordered_map<int,vector<int>> &adj,vector<int> &indegree,int n)
    {
        queue<int> q;
        vector<int> result;
        for(int i = 0;i < n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                result.push_back(i);
            }
        }

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(int v : adj[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                {
                    q.push(v);
                    result.push_back(v);
                }
            }
            
        }

        if(int(result.size() == n))
        {
            return true;
        }

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);

        for(auto &vec : prerequisites)
        {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return topological_sort_courses(adj,indegree,n);
        
    }

};