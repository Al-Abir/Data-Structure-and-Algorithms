#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int len = s.size();
        int sum =0;
        int sum2 =0;
        for(char c =0; c<len/2; c++) {
            sum = sum + int(s[c]-'0') ;    // 5 eqaul 53 - 48 = 5;
        }
          for(char c =len/2; c<len; c++) {
            sum2 = sum2 + int(s[c]-'0') ; 
        }
        if(sum==sum2){
            cout<<"YES"<<endl;
        }else{
            cout<<"No"<<endl;
        }


    }
        
       
        return 0;
}