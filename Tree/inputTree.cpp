#include <iostream>
#include<queue>
using namespace std;
class Node{
      public:
      int data;
       Node* left;
       Node* right;


       Node(int data){
         this->data = data;
         this->left= nullptr;
         this->right= nullptr;
       }
};
Node* InputTree(){
      int val;
      cin>>val;
      Node* root;
      if(val==-1){
        root= NULL;
      }else{
        root = new Node(val);
      }

      queue<Node*>q;
      q.push(root);


      while(!q.empty()){

        Node *p = q.front();
        q.pop();


        int l,r;
        cin>>l>>r;
        Node* myLeft;
        Node* myRight;



        if(l==-1){
            myLeft=nullptr;
        }else{
            myLeft= new Node(l);
        }
         if(r==-1){
            myRight=nullptr;
        }else{
            myRight= new Node(r);
        }

        p->left = myLeft;
        p->right = myRight;

          // 3. children gulo ke push koro
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
         
      }
      return root;

}

void level_order(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree nai" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        // 1. ber kore ana
        Node *f = q.front();
        q.pop();

        // 2. jabotiyo ja kaj ache
        cout << f->data << " ";

        // 3. tar children gulo ke rakha
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}
int main()
{
    
      Node* root = InputTree();
     level_order(root);

    return 0;
}