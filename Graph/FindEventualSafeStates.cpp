class Solution
{
public:
    bool DFSrecur(int s, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &dfsVisited, vector<bool> &cycle_detect)
    {
        visited[s] = true;
        dfsVisited[s] = true;

        vector<int> data = graph[s];

        for (auto x : data)
        {
            if (!visited[x])
            {
                if (DFSrecur(x, graph, visited, dfsVisited, cycle_detect))
                {
                    return cycle_detect[s] = true;
                }
            }
            else if (visited[x] && dfsVisited[x])
            {
                return cycle_detect[s] = true;
            }
        }
        dfsVisited[s] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> ans;

        int n = graph.size();
        vector<bool> visited(n, false), dfsVisited(n, false);
        vector<bool> cycle_detect(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                DFSrecur(i, graph, visited, dfsVisited, cycle_detect);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!cycle_detect[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};