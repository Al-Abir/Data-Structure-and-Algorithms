#include <iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin>>n;
    queue<int>q1;
    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        q1.push(val);
    }

     stack<int>s1;
     while(!q1.empty()){
           s1.push(q1.front());
           q1.pop();
     }
      queue<int> q2;
     while(!s1.empty()){
        q2.push(s1.top());
        s1.pop();
     }
     while(!q2.empty()){
        cout<<q2.front()<<" ";
        q2.pop();
     }
     
    return 0;
}