// User function Template for C++

class Solution
{
public:
    int checkCompressed(string s, string t)
    {
        // code here
        // if(s.size()<t.size()){
        //     return 0;
        // }

        int st = 0;
        int st1 = 0;
        while (st < s.size() && st1 < t.size())
        {
            if (isdigit(t[st1]))
            {

                int cnt = 0;
                while (st1 < t.size() && isdigit(t[st1]))
                {
                    cnt = cnt * 10 + (t[st1] - '0');
                    st1++;
                }
                st += cnt;
            }
            else if (s[st] == t[st1])
            {
                st++;
                st1++;
            }
            else if (s[st] != t[st1])
            {
                return 0;
            }
        }
        return st == s.size() && st1 == t.size();
    }
};