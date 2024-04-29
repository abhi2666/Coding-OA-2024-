string fairRations(vector<int> B) {
    // just go through each element and check for potential changing elements
    int cnt = 0;
    for(int i = 0; i < B.size()-1; i++){
        if(B[i]%2!=0){
            if(i==0){
                //check only left and increase the value
                B[i]++;
                B[i+1]++;
                cnt+=2;
            }else{
                B[i]++;
                if(B[i-1]%2) B[i-1]++;
                else if(B[i+1]%2) B[i+1]++;
                else B[i+1]++;
                cnt+=2;
            }
        }
    }
    // now check 
    for(int i = 0; i < B.size(); i++){
        if(B[i]%2) return "NO";
    }
    return to_string(cnt);
}