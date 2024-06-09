class Solution {
public:
    int findKthPositive(vector<int>& a, int k) { //already sorted array
        // use binary search in the array to find the element with >= k missing elements before it
        int low = 0, high = a.size()-1;
        while(low<=high){
            int mid = (low + high)/2;
            //find the missing elements before a[mid]
            int missing_element_before = a[mid] - (mid+1);
            if(missing_element_before < k) low = mid + 1;
            else high = mid - 1;
        }
        // at end your high will point to the element that is before the kth missing element
        // use below formula to find the missing element
        return high+k+1;
    }
};