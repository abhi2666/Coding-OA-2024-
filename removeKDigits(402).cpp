class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        // use a vector of char to keep track of chars and remove them if you can 
        vector<char>temp;
        for(int i = 0; i < num.size(); i++){
            while(temp.size() > 0 && k > 0 && temp.back() > num[i]) {
                temp.pop_back();
                k--;
            }
            //now put the current character in temp
            temp.push_back(num[i]);
        }
        //in case there are 
        while(k > 0){
            // means we can still remove elements
            temp.pop_back();
            k--;
        }

        // now check for any leading zeroes in your vector 
        string ans = "";
        for(auto ch : temp) {
            if(ans.empty() && ch=='0') continue;
            ans+=ch;
        }
        return ans.empty() ? "0" : ans; // this condition can only arise if there are only zeroes available to use
    }
};