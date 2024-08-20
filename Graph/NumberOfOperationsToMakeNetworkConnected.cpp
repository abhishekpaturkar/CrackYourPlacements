class DisjointSet
{
public:
    vector<int> rank, par, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        par.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }
    int findpar(int n)
    {
        if (n == par[n])
            return n;
        return par[n] = findpar(par[n]);
    }
    void unionsize(int u, int v)
    {
        int upar = findpar(u);
        int vpar = findpar(v);
        if (upar == vpar)
            return;
        if (size[upar] < size[vpar])
        {
            par[upar] = vpar;
            size[vpar] += size[upar];
        }
        else
        {
            par[vpar] = upar;
            size[upar] += size[vpar];
        }
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {

        DisjointSet st(n);
        int extra = 0;
        for (auto e : connections)
        {
            if (st.findpar(e[0]) == st.findpar(e[1]))
                extra++;
            else
                st.unionsize(e[0], e[1]);
        }
        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.par[i] == i)
                components++;
        }
        if (extra >= components - 1)
            return components - 1;
        return -1;
    }
};