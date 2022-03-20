#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.

    int dp[201][201];

    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDropDp(int egg, int floor)
    {
        // your code here
        // If there are no floors,
        // then no trials needed.
        // OR if there is one floor,
        // one trial needed.
        if (floor == 1 || floor == 0)
            return floor;
        // We need floor trials for one
        // egg and floor floors
        if (egg == 1)
            return floor;

        if (dp[egg][floor] != -1)
            return (dp[egg][floor]);

        int min = INT_MAX, k, res;

        // Consider all droppings from
        // 1st floor to kth floor and
        // return the minimum of these
        // values plus 1.
        for (k = 1; k <= floor; k++)
        {
            res = 1 + max(
                          eggDropDp(egg - 1, k - 1),
                          eggDropDp(egg, floor - k));
            if (res < min)
                min = res;
        }

        dp[egg][floor] = min;

        return min;
    }

    int eggDrop(int egg, int floor)
    {
        memset(dp, -1, sizeof(dp));
        return (eggDropDp(egg, floor));
    }
};

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}
