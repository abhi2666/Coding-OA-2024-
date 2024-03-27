/*
You are given an integer N. Now, you need to find if there exists two prime numbers (X,Y) such that X^2+y^2=N. If (X,Y) exists then output the minimum value of X+Y otherwise print -1

Approach -> we can use sieve of eratosthenes to get all the prime numbers from 2 to n/2 and then pick the two smallest prime numbers from it beucase we want to return their sum or else we can return -1 if we cannot get two such prime numbers
*/

#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n, vector<bool> &isPrime)
{
    // start from 2 and mark all the numbers divisible by it
    for (int i = 2; i * i < n; i++)
    {
        if (isPrime[i] == true)
        {
            // means its a prime number...mark all its multiple false
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
    }
}

int solve(vector<bool> isPrime)
{
    int x = -1, y = -1;
    // to be done
}

int main()
{
    int n;
    cin >> n;
    vector<bool> isPrime(n + 1, true); // true -> not prime
    isPrime[0] = false;
    isPrime[1] = false;
    sieveOfEratosthenes(n + 1, isPrime);
    for(int i = 0; i < n+1; i++){
        cout<<i<<" "<<isPrime[i]<<endl;
    }
    cout << solve(isPrime) << endl;
    return 0;
}
