class Solution
{
public:
    void sortColors(vector<int> &arr)
    {
        int l = 0, m = 0;
        int h = arr.size() - 1;

        while (m <= h)
        {
            if (arr[m] == 0)
            {
                swap(arr[m], arr[l]);
                l++;
                m++;
            }
            else if (arr[m] == 2)
            {
                swap(arr[m], arr[h]);
                h--;
            }
            else
            {
                m++;
            }
        }
    }
};