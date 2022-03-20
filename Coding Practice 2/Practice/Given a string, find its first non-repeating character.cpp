#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       int freq[256];
       for(int i=0;i<256;i++){
           freq[i] = -1;
       }
       for(int i=0;i<S.length();i++){
           if(freq[S[i]] == -1)
                freq[S[i]] = i;
            else
                freq[S[i]] = -2;
       }
       int res = INT_MAX;
       for(int i=0;i<256;i++){
           if(freq[i] >= 0)
                res = min(res,freq[i]);
       }
       if(res == INT_MAX)
            return '$';
        else
            return S[res];
    }

};

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}
