class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        unordered_map<int, bool> mp;

        dfs(0, adj, mp, ans);
        return ans;
    }

    void dfs(int v, vector<int> adj[], unordered_map<int, bool> &mp, vector<int> &ans)
    {
        mp[v] = true;
        ans.push_back(v);

        for (auto n : adj[v])
        {
            if (!mp[n])
            {
                dfs(n, adj, mp, ans);
            }
        }
    }
};