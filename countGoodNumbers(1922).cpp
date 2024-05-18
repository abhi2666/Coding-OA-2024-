/*
You have to form different numbers of length n from 0-9 and then check for the condition
even indices - even value, odd indices - prime number

Approach - for every even places there are only 5 items you can put and for odd places you have only 4 items,
so find the numbers of even and odd places and then use custom power function to calcute the final result.
*/
class Solution {
private:
    int mod = 1e9+7;
    long long power(long long val, long long pow){
        if(pow==0) return 1;
        long long res = power(val, pow/2);
        // once result is calculated multiply the ans with itself
        res *= res;
        res %=mod;
        if(pow%2){
            // means power is odd additional val should be multiplyed
            res*=val;
        }
        res%=mod;
        return res;
    }
    
public:
    int countGoodNumbers(long long n) {
       long long odd = n/2;
       long long even = n/2 + n%2;
       return (power(5, even) * power(4, odd)) %mod;
    }
};