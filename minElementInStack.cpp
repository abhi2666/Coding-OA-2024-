/*
All operations are in O(1) but takes O(2N) space where N -> number of elements in the stack
*/

class Solution{
    int minEle;
    vector<pair<int, int>>st; // ele, currminEle
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           if(st.size()==0) return -1;
           else return st.back().second;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
            if(st.size()==0) return -1; // no element present
            else{
                int ele = st.back().first;
                st.pop_back();
                return ele;
            }
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           // push the element but also keep track of the current min element
           if(st.size()==0){
            // means this is the first element
                st.push_back({x, x});
           }
           else{
            // means there already exists an element
            st.push_back({x, min(st.back().second, x)}); // this will preserve the min element
           }
       }
};