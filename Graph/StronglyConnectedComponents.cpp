// Kosaraj's Algorithm
// 1. DFS on the graph and store the finishing time of each node in a stack.
// 2. Transpose the graph.
// 3. DFS on the transpose graph using the finishing time of each node in the stack.

class Solution
{
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited, st);
            }
        }

        st.push(node);
    }

    void dfs3(int node, vector<vector<int>> &adjT, vector<int> &visited)
    {
        visited[node] = 1;
        for (auto it : adjT[node])
        {
            if (!visited[it])
            {
                dfs3(it, adjT, visited);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // code here
        vector<int> visited(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }

        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }

        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!visited[node])
            {
                scc++;
                dfs3(node, adjT, visited);
            }
        }

        return scc;
    }
};