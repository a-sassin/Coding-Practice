#include <iostream>
using namespace std;

int minJumps(int arr[], int len)
{
    if (len <= 1)
        return 0;

    if (arr[0] == 0)
        return -1;

    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1;

    for (int i = 1; i < len; i++)
    {
        if (i == len - 1)
            return jump;

        maxReach = max(maxReach, i + arr[i]);

        step--;

        if (step == 0)
        {
            jump++;
            if (i >= maxReach)
                return -1;

            step = maxReach - i;
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << minJumps(arr, n);
    }
    return 0;
}
