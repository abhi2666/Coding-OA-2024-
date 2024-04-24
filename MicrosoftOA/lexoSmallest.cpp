#include<bits/stdc++.h> 
using namespace std;
int main()
{
    string s = "abczd";
    int i;
    for(i = 0; i < s.size()-1; i++){
        if(s[i] > s[i + 1]) break;
    }

    string temp = s.substr(0, i) + s.substr(i+1);
    cout<<temp<<endl;
    return 0;
}