class Solution
{
public:
    unordered_map<int, int> mp;
    vector<vector<int>> ans;
    void solve(vector<int> arr, set<int> se, int i, vector<int> v)
    {
        if (i >= arr.size())
        {
            ans.push_back(v);
            return;
        }

        for (int element : se)
        {
            if (mp[element] > 0)
            {
                mp[element]--;
                v.push_back(element);
                solve(arr, se, i + 1, v);
                mp[element]++;
                v.pop_back();
            }
        }
    }

    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());
        set<int> se;

        for (auto val : arr)
        {
            se.insert(val);
            mp[val]++;
        }

        vector<int> v;
        solve(arr, se, 0, v);

        return ans;
    }
};

// -------- Using next_permutation --------
class Solution
{
public:
    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr);
        while (next_permutation(arr.begin(), arr.end()))
        {
            ans.push_back(arr);
        }
        return ans;
    }
};