#include <iostream>
#include<list>
using namespace std;
void print(list<int> &ll){
    for(list<int>::iterator it = ll.begin(); it != ll.end(); it++ ){
        cout<<*it <<" ";
    }
    cout<<endl;
}
int main()
{

    list<int> num = {10,20,30,56};

   print(num);
    
     
    return 0;
}