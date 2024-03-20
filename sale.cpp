#include <bits/stdc++.h>
using namespace std;

// void solve(int idx, int n, bool close, int curr, int &score, vector<int> &a)
// {
//     if (idx == n)
//     {
//         score = max(score, curr);
//         return;
//     }
//     if(close==true) {
//         score = max(score, curr);
//         return;
//     }
//     //at any index we can close sale at that day
//     solve(idx+1, n, false, curr+a[idx], score, a);
//     solve(idx, n, true, curr+(2*a[idx]), score, a);

// }

// working
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long ans = 2 * a[0], addScore = a[0];
        for(int i = 1; i < n; i++){
            long sum = 2*a[i] + addScore;
            if(sum > ans){
                ans = sum;
            }
            addScore += a[i];
        }
        cout << maxScore << endl;
    }
    return 0;
}
