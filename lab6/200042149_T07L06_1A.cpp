#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    /* data */
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }

    Node* insert(Node* root, int data) {
        if(root == NULL){
            return new Node(data);
        }
        else{
            Node* cur;
            if(data <= root->data && (root->data - data) > 3) {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else if(data > root->data && (data - root->data) > 3){
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    Node* deletenode(Node* root, int k) 
    { 
        // Base case 
        if (root == NULL) 
            return root; 
        //If root->data is greater than k then we delete the root's subtree
        if(root->data > k){ 
            root->left = deletenode(root->left, k); 
            return root; 
        } 
        else if(root->data < k){ 
            root->right = deletenode(root->right, k); 
            return root; 
        } 
  

        // If one of the children is empty 
        if (root->left == NULL) { 
            Node* temp = root->right;
            delete root; 
            return temp; 
        } 
        else if (root->right == NULL) { 
            Node* temp = root->left; 
            delete root; 
            return temp; 
        }

        else {
          Node* Parent = root;
          // Find successor of the node
          Node *succ = root->right; 
          while (succ->left != NULL) { 
              Parent = succ; 
              succ = succ->left; 
        } 

          if (Parent != root) 
              Parent->left = succ->right; 
          else
              Parent->right = succ->right; 

          // Copy Successor Data  
          root->data = succ->data; 

          // Delete Successor and return root 
          delete succ;          
          return root; 
        } 
    } 
 

    void levelOrderTraversal(Node* root){
        queue<Node*> que;
        que.push(root);
        cout<<root->data<<" ";
        Node* curr = nullptr;

        while(que.size())
        {
            curr = que.front();
            que.pop();

            if(curr->left)
            {
                que.push(curr->left);
                cout<<(curr->left)->data<<" ";
            }

            if(curr->right)
            {
                que.push(curr->right);
                cout<<(curr->right)->data<<" ";
            }
        }
    }
};

int main()
{
    Node tree(0);
    Node* root = nullptr; 
    int n;
    cin>>n;
    while (n--)
    {
        int data;
        cin>>data;
        root = tree.insert(root, data);
    }

    int x;
    cin>>x;

    while(x--)
    {
        int y;
        cin>>y;
        tree.deletenode(root, y);
        tree.levelOrderTraversal(root);
    }
    return 0;
}