//program not giving any output
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // to check for mountain logic start from the middle element
    int i, j, cnt;
    cnt = 0;
    if (n % 2 == 0)
    {
        j = n / 2;
        i = j - 1;
        if(a[i]!=a[j]) cnt++;
    }
    else
    {
        i = n / 2;
        j = n / 2;
    }


    while(i > 0 && j < n-1){
        //check if the order is maintained or not
        if(a[i] <= a[i-1]){
            cnt++;
        }
        if(a[j] <= a[j+1]){
            cnt++;
        }
        i--;
        j++;
    }
    cout<<cnt<<endl;
    return 0;
}