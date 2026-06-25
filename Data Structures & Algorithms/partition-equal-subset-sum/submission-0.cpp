class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums){
            sum=sum+num;
        }
        if(sum % 2==1) return false;
        int target=sum/2;
        int n=nums.size();
        vector<bool>dp(target+1,false);
        dp[0]=true;
        for(int num:nums){
            for(int i=target;i>=num;i--){
                if(dp[i-num]){
                    dp[i]=true;
                }
            }
        }
        if(dp[target]) return true;
        else return false;
    }
};