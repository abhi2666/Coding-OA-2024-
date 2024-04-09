class Solution {
public:
    string getSmallestString(string s, int k) {
        // try to convert every character to 'a' from both left and right side (circular arrangement) and pick the min of both and min <= k else replace the ch with ch - k which implies the nearest charcter from left size becuase that is your char
        for(auto &ch : s){ /// to change it in original string also
            if(ch!='a'){
                int left = ch-'a'; // to reach a 
                int right = 'z'-ch+1; // to reach a
                int val  = min(left, right);
                if(val <= k){
                    ch = 'a'; // can successfully convert it to a 
                    k-=val;
                }
                else{
                    // can cannot reach 'a', so reach the k element on your left becuase that will generate the smallest lexo string
                    ch = ch - k;
                    k = 0;
                }
            }
        }
        return ch;
    }
};