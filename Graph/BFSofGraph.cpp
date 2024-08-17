class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        queue<int> q;
        int src = 0;
        q.push(src);

        unordered_map<int, bool> visited;
        visited[src] = true;

        vector<int> ans;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto n : adj[front])
            {
                if (!visited[n])
                {
                    q.push(n);
                    visited[n] = true;
                }
            }
        }
        return ans;
    }
};