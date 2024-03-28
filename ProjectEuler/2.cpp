#include <iostream>
using namespace std;
int main()
{
    long mx = 4*1e6;
    long first = 0, second = 1, next = 0;
    long sum = 0;
    while(next < mx){
        next = first + second;
        first = second;
        second = next;
        if(second%2==0) sum += second;
    }
    cout<<sum<<endl;
    return 0;
}