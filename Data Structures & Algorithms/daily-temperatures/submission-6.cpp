class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
     
        int s= temperatures.size();
        vector<int>ans(s,0);
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                if(temperatures[j]>temperatures[i]){
                    ans[i]=j-i;
                    break;
                }
            }

        }
        return ans;
    }
};
