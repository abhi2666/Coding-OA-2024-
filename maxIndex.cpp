// TLE for just one test case..
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        int mxLen = 0;
        int right, lmt = -1;
        for(int left = 0; left < n; left++){
            // for each element from the start...look for a greater element from the end
            right = n-1;
            while(a[right] < a[i] && right > lmt) right--; // check for such a element
            lmt = right;
            mxLen = max(mxLen, right-i);
        }
        return mxLen;
    }
};