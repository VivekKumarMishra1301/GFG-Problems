/* struct Node {
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};*/

class Solution
{
public:
    void connect(Node *root)
    {
        // Code Here
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            if (front == NULL)
            {
                if (q.size() == 0)
                {
                    return;
                }
                q.push(NULL);
                continue;
            }
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }

            front->nextRight = q.front();
        }
    }
};
