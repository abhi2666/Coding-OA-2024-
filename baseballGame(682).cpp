class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        // use stack
        stack<int> s;
        int ans = 0;
        for (auto ops : operations)
        {
            if (ops == "+")
            {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.push(x);
                s.push(x + y);
            }
            else if(ops=="D"){
                s.push(2*s.top());
            }
            else if(ops=="C"){
                s.pop();
            }
            else{
                s.push(stoi(ops));
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};