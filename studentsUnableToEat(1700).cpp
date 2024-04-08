// as soon as you find a students who cannot eat, you just stop processing further and return the answer
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        // for each sandwhiches, traverse the students and try to match the top element with the student and then mark the student -1
        int eaten = 0;
        for(auto val : sandwiches){
            bool flag = false;
            for(int i = 0; i < students.size(); i++){
                if(students[i] != -1 && students[i]==val) {
                    flag = true;
                    students[i] = -1;
                    eaten++;
                    break;
                }
            }
            if(flag==false){
                //cannot process the current dish
                break;
            }
        }
        int ans = students.size()-eaten;
        return ans;
    }
};
