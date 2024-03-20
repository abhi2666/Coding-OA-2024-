#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>people(n), houses(n);
    for(int i = 0; i < n; i++) cin>>people[i];
    for(int i = 0; i < n; i++) cin>>houses[i];
    //try to provide the most smallest size house possible that can fit a person so that in near future if a larger person arrives there should be bigger houses present to accomodate that person
    int homeless = n;
    for(auto person : people){
        for(int i = 0; i < n; i++){
            if(houses[i] >= person){
                homeless--;
                houses[i] = INT_MIN;
                break;
            }
        }
    }
    cout<<"homeless -> "<<homeless<<endl;
    return 0;
}