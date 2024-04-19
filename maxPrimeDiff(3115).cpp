class Solution
{
private:
    bool isPrime(int n)
    if(n<=1) return false;
    {
        for (int i = 2; i < sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

public:
    int maximumPrimeDifference(vector<int> &nums)
    {
        int i = 0, n = nums.size();
        int j = n - 1;
        while (i < n)
        {
            if (isPrime(nums[i]))
                break;
            i++;
        }
        // second prime from the back
        while (j >= i)
        {
            if (isPrime(nums[j]))
                break;
            j--;
        }

        return j - i;
    }
};