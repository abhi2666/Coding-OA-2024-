#include <bits/stdc++.h>
using namespace std;
// to be done
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    // start from the middle and look for min and max possible elements and keep their index
    //  maintain the difference to be at max k only between their index
    int i = 0, j = n - 1;
    int mnIdx = -1, mn = INT_MAX;
    while (i < n / 2)
    {
        // find min element from last
        while(j > i){
            if(a[j] < a[i] && a[j] < mn && j-i <= k){
                mnIdx = j;
                mn = a[j];
            }
            j--;
        }
        if(mnIdx!=-1){
            swap(a[mnIdx], a[i]);
            break;
        }
        i++;
    }
    // printing output
    for (auto ele : a)
        cout << ele << " ";
    cout << endl;
    return 0;
}
