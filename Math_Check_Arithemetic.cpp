// User function Template for C++

class Solution
{
public:
    int inSequence(int A, int B, int C)
    {
        // code here
        if (A == B)
        {
            return 1;
        }
        else if (A != B && C == 0)
        {
            return 0;
        }
        if (B < A && C > 0)
        {
            return 0;
        }
        if (B > A && C == 0)
        {
            return 0;
        }
        if ((B - A) % C == 0 && (B - A) / C > 0)
        {
            return 1;
        }
        return 0;
    }
};