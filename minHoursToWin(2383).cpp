class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int totalHours = 0;
        int totalEnery = accumulate(energy.begin(), energy.end(), 0);
        if(totalEnery >= initialEnergy){
            totalHours += (totalEnery - initialEnergy + 1);
        }
        cout<<"After Enery: "<<totalHours<<endl;
        // for experience
        for(auto exp : experience){
            if(exp >= initialExperience){
                totalHours += (exp-initialExperience + 1);
                initialExperience += (exp-initialExperience + 1);
            }
            initialExperience += exp;
        }
        cout<<"Final : "<<totalHours<<endl;
        return totalHours;
    }   
};