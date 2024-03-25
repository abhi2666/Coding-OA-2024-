/*
It is optimal to perform all the addition operations first and then duplication operations.
*/
class Solution
{
public:
    int minOperations(int k)
    {
        if(k==1) return 0; // no operations needed
        int ans = INT_MAX, i = 1;
        while (i < k)
        {
            int operations = i - 1;
            if (k % i == 0)
            {
                operations = operations + (k / i) - 1;
            }
            else
            {
                operations = operations + (k / i);
            }
            if (ans > operations)
            {
                ans = operations;
            }

            i++;
        }
        return ans;
    }
};