// /*
// To do this we can use a pq and an queue to perform the operations..
// Pq to get the task with most freq..so that it can be performed first and queue to put processes that are on cooldown period..
// */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int, vector<int>>pq; //max heap
        unordered_map<char, int>mp;
        for(auto task : tasks) mp[task]++;
        for(auto it : mp) pq.push(it.second);
        queue<pair<int, int>>cooldown; // processFreq, cooldown
        int time = 0;
        while(!pq.empty() || !cooldown.empty()){
            time++;
            if(!pq.empty()){
                int proc = pq.top()-1;
                pq.pop();
                if(proc > 0) cooldown.push({proc, time+n});
            }
            if(!cooldown.empty()){
                if(cooldown.front().second==time){
                    pq.push(cooldown.front().first);
                    cooldown.pop();
                }
            }
        }
        return time;
    }
};

