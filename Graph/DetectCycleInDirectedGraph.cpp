class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int v, vector<int> adj[], vector<bool> &visited, vector<bool> &recurS)
    {
        visited[v] = true;
        recurS[v] = true;

        for (auto x : adj[v])
        {
            if (!visited[x])
            {
                if (dfs(x, adj, visited, recurS))
                    return true;
            }
            else if (recurS[x])
            {
                return true;
            }
        }

        recurS[v] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<bool> visited(V);
        vector<bool> recurS(V);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, recurS))
                    return true;
            }
        }
        return false;
    }
};