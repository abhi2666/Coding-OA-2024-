//not working on all the test cases
// class Solution {
// public:
//     bool isLongPressedName(string name, string typed) {
//         if(typed.size() < name.size()) return false;
//         int j = 0;
//         for(int i = 0; i < name.size(); i++){
//             if(typed[j]==name[i]){
//                 j++;
//             }
//             else{
//                 bool flag = false;
//                 while(j < typed.size()){
//                     if(typed[j]==name[i]){
//                         flag=true;
//                         break;
//                     }
//                     j++;
//                 }
//                 if(flag) j++;
//                 else return false; 
//             }
//         }
//         return true;
    
//     }
// };

// working approach
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n=name.size();
        int m=typed.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(name[i]==typed[j]){
                i++;
                j++;
            }
            //To handle the multiple characters
            else if(i>0 && name[i-1]==typed[j]){
                j++;
            }
            else return false;
        }
        //To handle the ending repited characters
        while(j<m && name[n-1]==typed[j])  j++;
        return i==n && j==m;
    }
};