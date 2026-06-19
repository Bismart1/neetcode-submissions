class Solution {
public:
    bool checkValidString(string s) {
        int mini=0;
        int maxi=0;
        for(char n:s){
            if(n=='('){
                mini++;
                maxi++;
            }
            else if(n==')'){
                mini--;
                maxi--;
            }
            else{
                mini--;
                maxi++;
            }
            mini=max(mini,0);
            if(maxi<0) return false;
        }
        return mini==0;
    }
};
