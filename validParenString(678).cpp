#include <iostream>
#include <stack>
using namespace std;

//understand first -- very easy solution
class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> open, stars;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                open.push(i);
            }
            else if (s[i] == '*')
            {
                stars.push(i);
            }
            else
            {
                if (!open.empty())
                {
                    open.pop();
                }
                else if (!stars.empty())
                {
                    stars.pop();
                }
                else
                {
                    return false; // No matching open parenthesis or star found
                }
            }
        }

    // handling the casess when we have (  and * left... we have to make sure for every (, a * exist on the right side of it so that we can make a pair of it and remove it. 
        while (!open.empty() && !stars.empty())
        {
            if (open.top() < stars.top())
            {
                open.pop();
                stars.pop();
            }
            else
            {
                break;
            }
        }

        return open.empty();
    }
};
