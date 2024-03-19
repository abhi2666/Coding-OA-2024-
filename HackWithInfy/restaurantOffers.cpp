#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    unordered_map<int, int>mp; // element, frequency
    for(auto ele : a) mp[ele]++;
    map<int, int>freqFirst; // frequency, element
    for(auto it : mp){
        freqFirst.insert({it.second, it.first});
    }
    // Debugging
    // cout<<"frequency map"<<endl;
    // for(auto it : freqFirst){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    int A = -1, ans = 0;
    for(auto it : freqFirst){
        //pick the minimum first 
        if(A == -1){
            // this is first time....pick the smallest value
            // cout<<"first value"<<it.first<<endl;
            A = it.first;
            ans+=it.first;
        }
        else{
            // check for 2*A in map
            for(auto it : freqFirst){
                if(it.first >= (2*A)){
                    ans += (2*A);
                    A = 2*A;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}