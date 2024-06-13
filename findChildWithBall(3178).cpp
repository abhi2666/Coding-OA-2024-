class Solution {
public:
    int numberOfChild(int n, int k) {
        int ans = 0;
        bool flag = true;
        while(k--){
            if(flag) ++ans;
            else --ans;
            
            if(ans==n-1) flag = false;
            else if(ans==0) flag = true;
        }
        return ans;
    }
};