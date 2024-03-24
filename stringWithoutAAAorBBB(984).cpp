class Solution
{
public:
    string strWithout3a3b(int a, int b)
    {
        int contA = 0, contB = 0;
        string s = "";
        while (a != 0 && b != 0)
        {
            if (a > b)
            {
                if (contA < 2)
                {
                    s += 'a';
                    a--;
                    contA++;
                    contB = 0;
                }
                else if (b > 0)
                {
                    s += 'b';
                    b--;
                    contA = 0;
                    contB++;
                }
            }
            else
            {
                if (contB < 2)
                {
                    s += 'b';
                    b--;
                    contB++;
                    contA = 0;
                }
                else
                {
                    s += 'a';
                    a--;
                    contA++;
                    contB = 0;
                }
            }
        }
        while(a--) s += 'a';
        while(b--) s += 'b';
        return s;
    }
};