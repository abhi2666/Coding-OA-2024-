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

int solve(string &s){
    int ans = 0;
    int x = 0, y = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='X'){
            x++;
            ans = min(x, y);
        }
        else y++; // no need to compare in case of y because it is not necessary
    }
    return ans;
}

int main(){
    string s = "XXYYYY";
    cout<<solve(s)<<endl;
    return 0;
}