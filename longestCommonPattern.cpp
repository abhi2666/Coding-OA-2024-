#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin>>a>>b;
        int ans = 0;
        unordered_map<char, int>mp;
        for(auto ch : a) mp[ch]++;
        for(auto ch : b){
            if(mp.find(ch)!=mp.end()){
                ans++;
                mp[ch]--;
                if(mp[ch]==0) mp.erase(ch);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}