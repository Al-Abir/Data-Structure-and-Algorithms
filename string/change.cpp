#include <iostream>
using namespace std;
string  getchange(string str){
           int code;
           for(int i =0; i<str.size();i++){
                code = int(str[i]);
                if(code==122){
                    str[i]= char(97);
                }else if(code==90){
                    str[i]=char(65);
                }else if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z'){
                    str[i]= char(code+1);
                }
           }
           return str;
  
}
int main()
{
    
     
      cout<<getchange("hello world")<<endl;


    return 0;
}