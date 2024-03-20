#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int i = 0, j = n - 1;
        int ans = 0;
        while (i < j)
        {
            while (i < j && a[i] != i + 1)
                i++;
            while (j > i && a[j] != j + 1)
                j--;
            ans++;
            i++;
            j--;
        }
        cout << ans << endl;
    }
    return 0;
}

// working code
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &it : v)
        cin >> it;

    int cluster = 0;
    int individual = 0;

    int i = 0;
    int ans = 0;

    while (i < n)
    {

        // move i until you hit a number placed at wrong index.
        while (i < n && v[i] != i + 1)
        {
            i++;
        }

        int count = 0;
        // move i until elements are at wrong index. increment the count as you move.
        while (i < n && v[i] == i + 1)
        {
            count++;
            i++;
        }

        // Take the ceil of (count/2).
        // Below is the equivalent to ceil(count/2)
        ans += (count + 2 - 1) / 2;
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
    return 0;
}