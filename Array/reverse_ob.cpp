#include <iostream>
using namespace std;
class Student{
        public:
        string name;
        int roll;
        int marks;
};
int main()
{
    
     int n;
     cin>>n;
     Student s[n];

     for(int i=0; i<n; i++){
        cin>>s[i].name>>s[i].roll>>s[i].marks;
     }
     for(int i=n-1; i>=0; i--){
        cout<<s[i].name<<" "<<s[i].roll<<" "<< s[i].marks<<endl;;
     }
     
         
 

    return 0;
}