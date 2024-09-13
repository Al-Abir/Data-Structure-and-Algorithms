#include <iostream>
using namespace std;
int  count_word(string str){

      int count =1;
      for(int i =0; i<str.length();i++){
        if(str[i]==' ' && str[i+1]!=' '){
            count++;
        }
      }
      return count;
}
int main()
{
    cout<<count_word("python")<<endl;
    cout<<count_word("hello how are you")<<endl;
     
    return 0;
}