#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int CountWays(string str) {
        // Code here
        int n = str.size();
        const int mod = 1e9 + 7;

        // A table to store results of subproblems
        int count[n + 1];
        count[0] = 1;
        count[1] = 1;

        //for base condition "01123" should return 0
        if (str[0] == '0')
            return 0;

        for (int i = 2; i <= n; i++)
        {
            count[i] = 0;

            // If the last digit is not 0, then last digit must add to the number of words
            if (str[i - 1] > '0')
                count[i] = count[i - 1] % mod;


            // If second last digit is smaller than 2 and last digit is smaller than 7, then last two digits form a valid character
            if (str[i - 2] == '1' || (str[i - 2] == '2' && str[i - 1] < '7'))
                count[i] = (count[i] + count[i - 2]) % mod;
        }
        return count[n];
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.CountWays(str);
        cout << ans << "\n";
    }
    return 0;
}
