/*
Input:YXXXYXY
Output: 2
Explanation:
We can obtain XXXYY by:

Delete first Y -> XXXYXY
Delete last occurrence of X -> XXXYY

Approach -> remove the chars that are in lesser number and do this when you find an X from the start
*/

#include<bits/stdc++.h>
using namespace std;

string solve(string &s, unordered_map<string, int>& mp, int k){
    int val = mp[s];
    val = (val + k) % 7;
    for(auto it : mp){
        if(it.second==val) return it.first;
    }
    return "loda behnchod";
}

int main(){
    string s = "Tuesday";
    int k = 101;
    unordered_map<string, int>mp = {{"Monday", 0}, {"Tuesday", 1}, {"Wednesday",2}, {"Thursday",3}, {"Friday",4}, {"Saturday",5}, {"Sunday",6}};
    // for(auto it : mp) cout<<it.first<<endl;
    cout<<solve(s, mp, k)<<endl;
    return 0;
}