#include <iostream>
using namespace std;
string firstletter(string text){
    
       for(int i =0; i<text.size();i++){
            
              if (i == 0 || text[i - 1] == ' '){
                 text[i]=toupper(text[i]);
            }
       }

       return text;
       

}
int main()
{
    
     cout<<firstletter("i lobe you")<<endl;
    return 0;
}