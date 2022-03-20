#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string res="";
        while(n>0){
            char ch = 'A' + (n-1)%26;
            res = ch+res;
            n = (n-1)/26;
        }
        return res;
    }
};

int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
