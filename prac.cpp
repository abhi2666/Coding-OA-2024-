#include<bits/stdc++.h>
using namespace std;

int minimiseZ(vector<int> &a)
{
    sort(a.begin(), a.end());
    for(auto ele : a) cout<<ele<<" ";
    cout<<endl;
    // for negative multiply with max ele
    int ans = a[0], n = a.size();
    // now pick smallest number from left
    if (ans < 0)
    {
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] > 0)
                return a[i] * ans;
        }
        return ans * a[1];
    }
    else
    {
        return ans * a[1];
    }
}

int main(){
    vector<int>a = {-1, -2, -3, -4, -5};
    cout<<minimiseZ(a)<<endl;
    return 0;
}