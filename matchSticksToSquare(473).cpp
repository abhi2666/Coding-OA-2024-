class Solution
{
private:
    int a, b, c, d;

    bool solve(int i, vector<int> &match)
    {
        if (i == match.size())
        {
            if (a == 0 && b == 0 && c == 0 && d == 0)
                return true;
            else
                return false;
        }

        // try to put current match in any of the 4 groups
        if (match[i] <= a)
        {
            a -= match[i];
            if (solve(i + 1, match))
                return true;
            // once bactracking is done return the match to the matchbox
            a += match[i];
        }
        if (match[i] <= b)
        {
            b -= match[i];
            if (solve(i + 1, match))
                return true;
            // once bactracking is done return the match to the matchbox
            b += match[i];
        }
        if (match[i] <= c)
        {
            c -= match[i];
            if (solve(i + 1, match))
                return true;
            // once bactracking is done return the match to the matchbox
            c += match[i];
        }
        if (match[i] <= d)
        {
            d -= match[i];
            if (solve(i + 1, match))
                return true;
            // once bactracking is done return the match to the matchbox
            d += match[i];
        }
        return false;
    }

public:
    bool makesquare(vector<int> &match)
    {
        sort(match.begin(), match.end());
        int sum = accumulate(match.begin(), match.end(), 0);
        if (sum % 4)
            return false;  // cannot divide the array in 4 equal parts
        int val = sum / 4; // sum that each side should hold
        a = b = c = d = val;
        // When you are sorting in decreasing order then largest elements that is greater than sum/4=sideLength is begin discarded(function call is being returned immediately) that's why less function call is happening.
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(0, match);
    }
};