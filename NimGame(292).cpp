// Brain teaser
class Solution {
public:
    bool canWinNim(int n) {
        // upto 3 stones you will win the game
        // but with 4 stones you will lose the game 
        // and same for 8 stones you will lose that game also 
        if(n%4!=0) return true;
        else return false;
    }
};