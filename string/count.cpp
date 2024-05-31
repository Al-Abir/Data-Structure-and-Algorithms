#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    bool flag = false;
    int cnt =0;
    for(char c: s){
        if(isalpha(c)){

            if(flag== false)cnt++;
            flag = true;
        }else{

            flag = false;
        }
    }
    cout<<cnt<<endl;
    
    return 0;
}