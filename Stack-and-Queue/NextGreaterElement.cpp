class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> mp;

        for (int i = 0; i < nums1.size(); ++i)
        {
            mp[nums1[i]] = i;
        }

        stack<int> st;
        st.push(-1);

        for (int i = nums2.size() - 1; i >= 0; i--)
        {

            if (mp.find(nums2[i]) == mp.end())
            {
                st.push(nums2[i]);
                continue;
            }

            if (st.top() >= nums2[i])
            {
                int index = mp[nums2[i]];
                nums1[index] = st.top();
                st.push(nums2[i]);
            }
            else
            {
                while (st.top() != -1 and st.top() <= nums2[i])
                {
                    st.pop();
                }
                int index = mp[nums2[i]];
                nums1[index] = st.top();
                st.push(nums2[i]);
            }
        }

        return nums1;
    }
};