#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_set<char>st;
        for(int i = 0; i < n-1; i++) st.insert(s[i]);
        char last = s[n-1];
        if(st.find(last)==st.end()) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
