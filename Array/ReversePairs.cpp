class Solution
{
    int mergSort(vector<int> &num, int l, int h)
    {
        if (l >= h)
            return 0;
        int m = (l + h) / 2;
        int ans = 0;
        ans += mergSort(num, l, m);
        ans += mergSort(num, m + 1, h);
        ans += merg(num, l, m, h);
        return ans;
    }
    int merg(vector<int> &num, int l, int m, int r)
    {
        int left = l, right = m + 1, ans = 0;
        while (left <= m && right <= r)
            if (num[left] > (1ll * 2 * num[right]))
            {
                ans += m - left + 1;
                right++;
            }
            else
                left++;
        sort(num.begin() + l, num.begin() + r + 1);
        return ans;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        return mergSort(nums, 0, nums.size() - 1);
    }
};