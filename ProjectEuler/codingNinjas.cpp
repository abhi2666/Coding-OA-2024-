#include<bits/stdc++.h>
using namespace std;

int numberOfElement(int n, vector<int> &v) {
    int count = 0;
    // check for corner cases seperately
    //start
    float start = (v[0] + v[1])/3.0;
    cout<<ceil(start)<<endl;
    if(floor(start)==v[0]) count++;
    //end
    float end = (v[n-1] + v[n-2])/3.0;
    cout<<ceil(end)<<endl;
    if(floor(end)==v[n-1]) count++;

    for(int i = 1; i < n-1; i++){
        float val = (v[i-1] + v[i] + v[i+1])/3.0;
        if(ceil(val)==v[i]) count++;
        
    }
   
    return count;
}

int main(){
    vector<int>v = {1, 3, 1};
    cout<<numberOfElement(3, v)<<endl;
}