#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
    while(t--){
        int n, q, ans = 0;
        cin>>n>>q;
        int prev = 0;
        for(int i = 0; i < q; i++){
            int f, d;
            cin>>f>>d;
            ans += abs(f-prev);
            ans += abs(f-d);
            prev = d;

        }
        cout<<ans<<endl;
    }
    return 0;

}
