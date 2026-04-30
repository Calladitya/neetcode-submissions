class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi=INT_MIN;
        int i=0;int j=heights.size()-1;
        int width;
        int ans;
        while(i<j){
            int mmin=min(heights[i],heights[j]);
            width=j-i;
            ans=mmin*width;
            maxi=max(maxi,ans);
            if(heights[i]<heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxi;
    }
};
