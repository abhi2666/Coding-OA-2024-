#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>a(n);
	    for(int i = 0; i < n; i++) cin>>a[i];
	    int two = count(a.begin(), a.end(), 2);
        int one = count(a.begin(), a.end(), 1);
	    // main part are the conditions 
        // either all should be one or there should have two in combo of 8, 16, 24, 32,..
        if(one==n || two%8==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
	    
	}
    return 0;
}
