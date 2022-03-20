#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
       // code here 
       stack<string>st;
       for(int i=0;i<s.length();i++)
       {
           string res = "";
           //iterate till we find the dot(.) and keep adding 
           // characters into the word 
           while(i<s.length()&&s[i]!='.')
           {
               res = res + s[i];
               i++;
           }
           // Push the words into the stack
           st.push(res);
       }
       //printing the words in reverse order using stack
       while(!st.empty())
       {
           cout<<st.top();
           st.pop();
           if(!st.empty())
           {
               cout<<".";
           }
       }
   }
};

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
