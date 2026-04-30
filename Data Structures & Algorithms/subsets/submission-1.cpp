class Solution {
    private:
     void solve(vector<int>& nums,int i,vector<int>currSubset,vector<vector<int>>&subsets){
        if(i==nums.size()){
            subsets.push_back(currSubset);
            return;
        }
        currSubset.push_back(nums[i]);
        solve(nums,i+1,currSubset,subsets);
        currSubset.pop_back();
        solve(nums,i+1,currSubset,subsets);
     }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>subsets;
        vector<int>currSubset;

        solve(nums,0,currSubset,subsets);

        return subsets;
    }
};
