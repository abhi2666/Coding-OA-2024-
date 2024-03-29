#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int>&a, int l, int m, int h){
    vector<int>temp;
    int first = l, second = m + 1;
    while(first <= m && second <= h){
        if(a[first] < a[second]){
            temp.push_back(a[first]);
            first++;
        }
        else{
            temp.push_back(a[second]);
            second++;
        }
    }
    // now for any remaining elements put them directly at the end of the temp array
    while(first <= m){
        temp.push_back(a[first++]);
    }
    while(second <= h) temp.push_back(a[second++]);
    //put everything back to the original array
    int k = 0;
    for(int i = l; i <= h; i++){
        a[i] = temp[k++];
    }
}
void mergeSort(vector<int>&a, int low, int high){
    // divide the array from low to mid and mid + 1 to high continously
    if(low < high){
        int mid = (low + high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        mergeArrays(a, low, mid, high);
    }
}
int main()
{
    vector<int>a = {5, 4, 3, 2, 1};
    mergeSort(a, 0, 4);
    for(auto ele : a) cout<<ele<<" ";
    return 0;
}