#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to sort the array into a wave-like array.
    void convertToWave(vector<int> &arr, int n)
    {

        // Your code here
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 1; i += 2)
        {
            swap(arr[i], arr[i + 1]);
        }

        /*
        for (int i = 0; i < n; i += 2)
        {
            // If current even element is smaller than previous
            if (i > 0 && arr[i - 1] > arr[i])
                swap(&arr[i], &arr[i - 1]);

            // If current even element is smaller than next
            if (i < n - 1 && arr[i] < arr[i + 1])
                swap(&arr[i], &arr[i + 1]);
        }
        */
    }
};

int main()
{
    int t, n;
    cin >> t;   // Input testcases
    while (t--) // While testcases exist
    {
        cin >> n;         // input size of array
        vector<int> a(n); // declare vector of size n
        for (int i = 0; i < n; i++)
            cin >> a[i]; // input elements of array
        Solution ob;
        ob.convertToWave(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " "; // print array

        cout << endl;
    }
}
