#include <bits/stdc++.h>
using namespace std;

int countOnes(string& s){
    int cnt = 0;
    for(auto ch : s){
        if(ch=='1') cnt++;
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        //make a max zero counter
        int cnt = 0;
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ones = countOnes(s);
        int mx = 0;
        for(auto ch : s){
            if(ch=='0'){
                cnt++;
                mx = max(mx, cnt);
            }
            else{
                cnt = 0;
            }
        }
        cout<<mx+ones<<endl;

    }
    return 0;
}
