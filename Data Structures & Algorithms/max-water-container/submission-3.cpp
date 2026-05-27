class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;
        int ans=0;
        int area;
        while(l<r){
            int width=r-l;
            int height=min(heights[l], heights[r]);
            area=height*width;
            ans=max(ans,area);
            if(heights[l]<heights[r]) l++;
            else  r--;
        
        }
        return ans;
    }
    
};
