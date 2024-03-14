#include <bits/stdc++.h>
using namespace std;
int main()
{
    int villans, heroes, healthHeroEach;
    cin>>villans>>heroes>>healthHeroEach;
    vector<int>v(villans);
    long vhealth = 0, hhealth = heroes*healthHeroEach;
    for(int i = 0; i < villans; i++){
        cin>>v[i];
        vhealth+= v[i];
    }

    int ans = 0;
    if(hhealth >= vhealth) cout<<ans<<endl;
    else {
        // some villans need to be removed from the front
        for(auto villan : v){
            vhealth -= villan;
            ans++;
            if(vhealth <= hhealth) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
