class Solution {
public:
    bool isPalindrome(string s) {
        string pal="";
        for(char c:s){
            if(isalnum(c)) pal+= tolower(c);
        }
        return pal==string(pal.rbegin(),pal.rend());
    }
};
