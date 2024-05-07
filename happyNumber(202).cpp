class Solution {
public:
    bool isHappy(int n) {
        while(n > 1){
            if(n!=1 && n!=4){
                int s = 0;
                while(n > 0){
                    int dig = n%10;
                    s += (dig*dig);
                    n/=10;
                }
                n = s;
            }
            else return false;
        }

        return true;
    }
};