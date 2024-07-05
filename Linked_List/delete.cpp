#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next = NULL;

    Node(int data){
         this->data = data;
         this->next = NULL;
         
    }

};
void insertAttail(Node* &head, Node* &tail, int data){
         Node* newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }else{

            tail->next = newNode;
            tail = newNode;
        }


}
void deleteatHead(Node* &head, Node*&tail, int pos){
        if(pos ==1){
            Node*temp =head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }else{
              Node* current = head;
              Node* pre = NULL;
              int cnt =1;
              while(cnt<pos){
                pre = current;
                current = current->next;
                cnt++;
              }
          pre->next = current->next;
          current->next = NULL;
          delete current;
            
        }

}
void print(Node* &head){


      Node* temp = head;

      while(temp!=NULL){

         cout<<temp->data<<" ";
         temp = temp->next;
         
}

}

int main()
{   

     Node* head = NULL;
     Node* tail = NULL;

     int data;

     while(true){
        cin>>data;

        if(data ==-1){
            break;
        }

         insertAttail(head, tail, data);
     }
     print(head);
     cout<<endl;
     int pos;
     cin>>pos;
     deleteatHead(head, tail, pos);
     print(head);

    return 0;
}