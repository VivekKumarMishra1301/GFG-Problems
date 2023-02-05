
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int intersectPoint(Node *head1, Node *head2)
    {
        // Your Code Here
        unordered_map<Node *, int> first;
        unordered_map<Node *, int> sec;
        Node *temp1 = head1;
        Node *temp2 = head2;
        int num1 = 0;
        int num2 = 0;
        while (temp1 != NULL)
        {
            // first[temp1]++;
            num1++;
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            //  if(first.count(temp2)!=0){
            //     return temp2->data;
            // }
            num2++;
            temp2 = temp2->next;
        }

        // temp1=head1;
        // while(temp1!=NULL){
        //     if(sec.count(temp1)!=0){
        //         return temp1->data;
        //     }
        //     temp1=temp1->next;
        // }

        int d = abs(num1 - num2);
        if (num1 > num2)
        {
            while (d--)
            {
                head1 = head1->next;
            }
        }
        else if (num1 < num2)
        {
            while (d--)
            {
                head2 = head2->next;
            }
        }

        while (head1 != NULL && head2 != NULL)
        {
            if (head1 == head2)
            {
                return head1->data;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        return -1;
    }
};
