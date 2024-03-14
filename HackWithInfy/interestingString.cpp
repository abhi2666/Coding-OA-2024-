#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    unordered_map<char, int>mp;
    for(auto ch : s) mp[ch]++;
    //now get the element with the least freq and that is how many strings we can form after
    // rearranging characters
    int mn = INT_MAX;
    for(auto it : mp){
        mn = min(mn, it.second);
    }
    cout<<mn<<endl;
    return 0;
}