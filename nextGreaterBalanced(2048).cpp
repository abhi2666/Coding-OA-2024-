/*
An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.

Given an integer n, return the smallest numerically balanced number strictly greater than n.

Approach -> brute force your way from n + 1 till you didn't find such number
TC will fall in the right category..
*/
class Solution {
private:
    bool isBeautiful(int n){
        /// create freq map for each element
        int freq[10] = {0}; // because we are keeping the freq of digits
        while(n > 0){
            int dig = n%10;
            // if its a zero exit
            if(dig == 0) return false; // because it is invalid becuase zero should not come at all..
            freq[dig]++;
            n /= 10;
        }
        // now check the frequency
        for(int i = 1; i < 10; i++){
            if(freq[i] != 0 && freq[i] != i) return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        while(true){
            if(isBeautiful(++n)) return n;
        }
        return -1; //will not execute ever
    }
};