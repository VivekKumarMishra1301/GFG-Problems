// User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution
{
public:
    int isPrime(int N)
    {
        if (N < 2 || (!(N & 1) && N != 2))
            return 0;
        for (int i = 3; i * i <= N; i += 2)
        {
            if (!(N % i))
                return 0;
        }
        return 1;
    }

    int findF(int num)
    {
        if (num == 1)
        {
            return 2;
        }

        while (++num)
        {
            bool flag = true;

            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return num;
            }
        }
    }
    int findB(int num)
    {
        if (num == 1)
        {
            return 2;
        }

        while (--num)
        {
            bool flag = true;

            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return num;
            }
        }
    }

    Node *primeList(Node *head)
    {
        Node *temp1 = head;
        Node *temp = NULL;
        Node *head1 = NULL;
        while (temp1 != NULL)
        {
            if (isPrime(temp1->val))
            {
                if (temp == NULL)
                {
                    temp = temp1;
                    head1 = temp1;
                    temp1 = temp1->next;
                }
                else
                {
                    temp->next = temp1;
                    temp = temp->next;
                    temp1 = temp1->next;
                }
            }
            else
            {
                int front = findF(temp1->val);
                int back = findB(temp1->val);

                int diff1 = abs(temp1->val - front);
                int diff2 = abs(temp1->val - back);
                Node *newNode;
                if (diff1 < diff2)
                {
                    newNode = new Node(front);
                }
                else if (diff1 == diff2)
                {

                    newNode = new Node(min(front, back));
                }
                else
                {
                    newNode = new Node(back);
                }

                if (temp == NULL)
                {
                    temp = newNode;
                    head1 = temp;
                    temp1 = temp1->next;
                }
                else
                {
                    temp->next = newNode;
                    temp = temp->next;
                    temp1 = temp1->next;
                }
            }
        }
        return head1;
    }
};