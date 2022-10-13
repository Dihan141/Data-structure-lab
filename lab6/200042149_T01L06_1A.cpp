#include<iostream>

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

    void inorder(Node* root){
        if(root == NULL)
            return;
        
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
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
        tree.inorder(root);
        cout<<endl;
    }
    
    return 0;
}