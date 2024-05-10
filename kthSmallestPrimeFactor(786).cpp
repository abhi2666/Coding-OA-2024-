// pure brute force approach
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<float> vp;
        for(int i =0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                vp.push_back(((float)arr[i]/(float)arr[j]));
            }
        }
        sort(vp.begin(),vp.end());
        for(int i =0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(vp[k-1]==(((float)arr[i]/(float)arr[j]))){
                    return {arr[i],arr[j]};
                }
            }
        }
        return {0,1};
    }
};