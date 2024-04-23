// not working
// class Solution {
// public:
//     vector<string> findOcurrences(string text, string first, string second) {
//         vector<string>ans;
//         // take two words at a time
//         int i = 0, n = text.size();
//         while(i < n){
//             int j = i;
//             while(j < n && text[j]!=' ') j++;
//             //now extract the string
//             string a = text.substr(i, j-i);
//             if(a==first){
//                 // then look for second string
//                 int k = j + 1;
//                 while(k < n && text[k]!=' ') k++;
//                 string b = text.substr(j, k-j);
//                 if(b==second){
//                     int l = k + 1;
//                     while(l < n && text[l]!=' ') l++;
//                     string t = text.substr(k, l-k);
//                     ans.push_back(t);
//                     i = l + 1;
//                 }
//                 else{
//                     i = j + 1;
//                 }
//             }
//             else {
//                 i = j + 1; // move i to check the next word in the text
//             }
//         }
//         return ans;
//     }
// };

// new code - no bakchodi
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second)
{
    vector<string> ans;
    vector<string> temp; // vector to store words of text string
    string s = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
            s += text[i];
        else
        {
            temp.push_back(s);
            s = "";
        }
    }
    temp.push_back(s); // to store last word of text string

    for (int i = 0; i < temp.size(); i++)
    {
        if (i + 2 < temp.size()) // to check if iterator does not go out of bound
            if (temp[i] == first and temp[i + 1] == second)
                ans.push_back(temp[i + 2]);
    }

    return ans;
}
};s