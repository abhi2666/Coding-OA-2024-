/*
Given a string str containing only a and b, find the longest substring of str such that it does not contain more than two contiguous occurrences of a and b.
*/
#include<bits/stdc++.h> 
using namespace std;

string solve(string s){
    string ans = "";
    int mx_len = 0, a_count = 0, b_count = 0;
    int i = 0, j = 0;
    while(j < s.size()){
        if(s[j]=='a'){
            a_count++;
            b_count = 0;
        }
        else{
            a_count = 0;
            b_count++;
        }
        // check for consecutive a's and b's and move i accordingly
        if(a_count > 2){
            i = j - 2;
            a_count--;
        }
        if(b_count > 2){
            i = j - 2;
            b_count--;
        }
        int curr_len = j-i+1;
        if(curr_len > mx_len){
            mx_len = curr_len;
            ans = s.substr(i, mx_len);
        }
        j++;
    }

    return ans;
}

int main()
{
    string s = "aabbaabbaabbaaa";
    // keep track of max len and keep string that exceeds that
    cout<<solve(s)<<endl;
    return 0;
}