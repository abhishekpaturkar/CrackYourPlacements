/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        // Your code here

        // Your code here
        long long int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += (p[i].petrol - p[i].distance);
        }
        if (s < 0)
            return -1;

        // kadane's
        int index = 0;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            c += (p[i].petrol - p[i].distance);
            if (c < 0)
            {
                c = 0;
                index = i + 1;
            }
        }
        return index;
    }
};