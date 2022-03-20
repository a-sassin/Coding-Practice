// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insert(stack<int> &s, int x){
    // Base case: Either stack is empty or newly inserted
    // item is greater than top (more than all existing)
    if(s.size() == 0 || s.top() <=x){
        s.push(x);
        return;
    }

    // If top is greater, remove the top item and recur
    int temp = s.top();
    s.pop();
    insert(s,x);

    // Put back the top item removed earlier
    s.push(temp);
    return;
}

void SortedStack :: sort()
{
   //Your code here
   // If stack has only one value
   if(s.size() == 1){
       return;
   }
   
   // Remove the top item
   int temp = s.top();
   s.pop();

   // Sort remaining stack
   sort();

   // Push the top item back in sorted stack
   insert(s,temp);
   return;
}