// User function Template for C++
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    Node *find(Node *root, int target)
    {
        if (root == NULL)
        {
            return NULL;
        }
        Node *get = NULL;
        if (root->data < target)
        {
            get = find(root->right, target);
        }
        else if (root->data > target)
        {
            get = find(root->left, target);
        }
        else
        {
            get = root;
        }
        return get;
    }

    long long int sum(Node *root, int dir)
    {
        if (root == NULL)
        {
            return 0;
        }

        int num = 0;
        num += sum(root->left, dir - 1);
        num += sum(root->right, dir + 1);
        if (dir == 0)
        {
            num += root->data;
        }
        return num;
    }

    long long int verticallyDownBST(Node *root, int target)
    {
        // Code here
        Node *tnode = find(root, target);
        if (tnode == NULL)
        {
            return -1;
        }

        return (sum(tnode, 0) - tnode->data);
        // return hold;
    }
};