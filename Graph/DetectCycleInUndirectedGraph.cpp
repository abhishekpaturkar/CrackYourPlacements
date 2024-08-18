class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int v, vector<int> adj[], vector<bool> &visited, int parent)
    {
        visited[v] = true;
        for (auto x : adj[v])
        {
            if (!visited[x])
            {
                if (dfs(x, adj, visited, v))
                {
                    return true;
                }
            }
            else if (parent != x)
            {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, -1))
                    return true;
            }
        }
        return false;
    }
};