// can furthur be optimised but this will work too
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        //simulate the condition
        // if zero don't count
        int n = tickets.size();
        int i = 0, steps = 0;
        while(tickets[k] != 0){
            if(tickets[i]!=0){
                tickets[i] -= 1;
                step++;
            }
            i = (i + 1)%n;
        }
        return steps;
    }
};