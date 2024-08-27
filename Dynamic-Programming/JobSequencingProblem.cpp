/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // comparator for sorting on basis of comparator
        sort(arr, arr + n, [](Job a, Job b)
             { return a.profit > b.profit; });

        int maxDeadline = 0;

        for (int job = 0; job < n; job++)
        {
            maxDeadline = max(maxDeadline, arr[job].dead);
        }

        vector<int> timeSlots(maxDeadline + 1, -1);
        int jobCount = 0;
        int totalProfit = 0;

        for (int job = 0; job < n; job++)
        {
            int slot = arr[job].dead;

            while (slot-- >= 1)
            {
                if (timeSlots[slot] == -1)
                {
                    timeSlots[slot] = 1;
                    jobCount++;
                    totalProfit += arr[job].profit;
                    break;
                }
            }
        }
        return {jobCount, totalProfit};
    }
};