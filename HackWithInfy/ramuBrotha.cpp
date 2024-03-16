#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i = 0; i < n; i++) cin>>a[i];
        set<int>st(a.begin(), a.end());
        int dish = 0, cnt, mxCnt = INT_MIN;
        for(auto ele : st){
            int i = 0;
            cnt = 0;
            while(i < n){
                if(a[i]==ele){
                    cnt++;
                    i += 2;
                }
                else {
                    i++;
                }
            }
            if(cnt > mxCnt) {
                mxCnt = cnt;
                dish = ele;
            }
        }
        cout<<dish<<endl;
    }
    return 0;
}