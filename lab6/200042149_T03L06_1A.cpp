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
            if(data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else{
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

    int maxHeight(Node* node)
    {
        if(node == nullptr)
            return 0;
        else{
            int leftheight = maxHeight(node->left);
            int rightheight = maxHeight(node->right);

            if(leftheight > rightheight)
                return leftheight+1;
            else
                return rightheight+1;
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
    
    cout<<tree.maxHeight(root)-1<<endl;
    return 0;
}