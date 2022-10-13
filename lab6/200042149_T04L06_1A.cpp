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
            if(data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else if(data > root->data){
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    int inorder(Node* root, int data)
    {
        stack<Node*> stck;
        Node* curr = root;
        int cnt = 0;

        while (!stck.empty() || curr != nullptr)
        {
            if(curr != nullptr)
            {
                stck.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = stck.top();
                stck.pop();

                if(curr->data == data)
                {
                    break;
                }
                cnt++;
                curr = curr->right;
            }
        }
        return cnt;
    }


    int leftNodeCount = 0;
    void calculateLeftSubTreeNodes(Node* root)
    {   
        if(root == nullptr)
            return;
        else
        {
            calculateLeftSubTreeNodes(root->left);
            leftNodeCount++;
            calculateLeftSubTreeNodes(root->right);
        }
    }
};

int main()
{
    Node tree(0);
    Node* root = nullptr; 
    int n;
    //cin>>n;
    while (1)
    {
        int data;
        cin>>data;
        if(data < 0) break;
        root = tree.insert(root, data);
    }

    int t;
    tree.calculateLeftSubTreeNodes(root->left);
    int leftnodes = tree.leftNodeCount;
    cin>>t;
    while (t--)
    {
        int x;
        cin>>x;

        if(x <= root->data)
        {
            cout<<tree.inorder(root->left, x)<<endl;
        }
        else
        {
            cout<<tree.inorder(root->right, x) + leftnodes + 1<<endl;
        }
    }
    

    return 0;
}