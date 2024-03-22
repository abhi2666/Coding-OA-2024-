// number game (Not Working)
class Solution
{
private:
    int solve(long score, int val, int k, int N){
        if(score > N) return;
        // can pick the same element or can move for lower element
        int pick = 1 + solve(score+pow(val, k), val, k, N);
        int notPick = solve(score, val-1, k, N);
        if(score==N) {
            return min(pick, notPick);
        }
        return 0;
    }
public:
    int score(int N, int k)
    {
        int a = sqrt(N);
        return solve(0, a, k, N);
    }
};