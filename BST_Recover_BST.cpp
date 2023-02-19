// User function Template for C++

/*struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution
{
public:
    void traverse(struct Node *root, vector<int> &hold1, vector<struct Node *> &hold2)
    {
        if (root == NULL)
        {
            return;
        }

        traverse(root->left, hold1, hold2);
        hold1.push_back(root->data);
        hold2.push_back(root);
        traverse(root->right, hold1, hold2);
    }

    struct Node *correctBST(struct Node *root)
    {
        // code here
        vector<int> hold1;
        vector<struct Node *> hold2;

        traverse(root, hold1, hold2);
        sort(hold1.begin(), hold1.end());

        for (int i = 0; i < hold2.size(); i++)
        {
            hold2[i]->data = hold1[i];
        }
        return root;
    }
};