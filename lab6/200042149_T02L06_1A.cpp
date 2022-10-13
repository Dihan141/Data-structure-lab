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

    tree.levelOrderTraversal(root);
    return 0;
}