class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int prev = 0, curr = 0;
        int i = 1;
        while(i <= n){
            curr += i;
            if(curr == (sum-prev)) return i;
            prev = curr;
            i++;
        }
        return -1;
    }
};