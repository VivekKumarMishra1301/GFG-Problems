// User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    Node *reversal(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *hold = reversal(head->next);
        head->next->next = head;
        head->next = NULL;
        return hold;
    }

    Node *reverse(Node *head, int k)
    {
        // code here
        Node *temp = head;
        Node *link = head;
        while (--k)
        {
            temp = temp->next;
        }
        Node *secondpart = temp->next;
        temp->next = NULL;
        Node *newHead = reversal(head);
        head->next = reversal(secondpart);
        return newHead;
    }
};