class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         unordered_set<int>st(nums.begin(),nums.end());
         int ans=0;
         for(int num:nums){
            int streak=0;
            while(st.find(num)!=st.end()){
                  streak++;
                  num++;
            }
            ans=max(ans,streak);
         }
         return ans;
    }
};
