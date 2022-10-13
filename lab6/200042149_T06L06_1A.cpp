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

    int maxNum(Node* root, int h)
    {
        int ans = 0;
        if(h <= root->data) ans = h;

        if(h > root->data)
        {
            ans = h;
            while (root->data != h)
            {
                if(root->data > ans)
                    ans = root->data;
                if(root->data < h)
                    root = root->left;
                else
                    root = root->right;
            }
        }
        return ans;
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

    int x, y;
    cin>>x>>y;

    cout<<tree.maxNum(root, y)<<endl;
    return 0;
}