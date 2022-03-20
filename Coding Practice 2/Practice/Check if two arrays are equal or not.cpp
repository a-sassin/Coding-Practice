#include<bits/stdc++.h>
using namespace std;
#define ll long long 

class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        
        unordered_map<int,int> ump;
        
        for(int i=0;i<N;i++){
            ump[A[i]]++;
        }
        
        for(int i=0;i<N;i++){
            if(ump.find(B[i]) == ump.end())
                return false;
                
            if(ump[B[i]] == 0)
                return false;
            
            ump[B[i]]--;
            
        }
        
        return true;
    }
};

//
class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        for(int i=0;i<N;i++){
            if(A[i]!=B[i])
                return false;
        }
        return true;
    }
};
//

int main()
 {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        vector<ll> arr(n,0),brr(n,0);
        
        // increase the count of elements in first array
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        
        
        // iterate through another array
        // and decrement the count of elements
        // in the map in which frequency of elements
        // is stored for first array
        for(ll i=0;i<n;i++)
            cin >> brr[i];
        Solution ob;
        cout << ob.check(arr,brr,n) << "\n";
    }
	return 0;
}
