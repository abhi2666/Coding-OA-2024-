#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int val = n%2 ? (n/2)+1 : n/2; //even odd case
        int ones = n-val;
        long score = 0;
        if(n%2==1){
            score += ((2*6*(val-1)) + ones*1);
            score += 6;
        }
        else{
            score += ((2*6*val) + ones*1);
        }
        cout<<score<<endl;
    }
    return 0;
}