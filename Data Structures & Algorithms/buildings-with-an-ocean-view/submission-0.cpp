class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int>ans;
        int n = heights.size();
        int maxi=heights[n-1];
        ans.push_back(n-1);
        for(int i=n-2;i>=0;i--){
            if(heights[i]>maxi){
                maxi=heights[i];
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};