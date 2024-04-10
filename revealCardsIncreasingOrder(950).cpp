class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int>ans(n, -1); // -1 represents empty space
        // sort it to get increasing order
        sort(deck.begin(), deck.end());
        ans[0] = deck[0];
        int k = 1;
        for(int i = 1; i < n; i++){
            // move k in circular fashion until you find a blank space
            while(ans[k] != -1){
                k = (k + 1)%n;
            }
            // found the first blank space where we will not put our ith element..
            // we will look for next blank space after this blank space and we will
            // go in a circular way
            k = (k + 1)%n;
            while(ans[k] != -1){
                k = (k + 1)%n;
            }
            // put this element in this location
            ans[k] = deck[i];
            k = (k + 1)%n;

        }
        return ans;
    }
};