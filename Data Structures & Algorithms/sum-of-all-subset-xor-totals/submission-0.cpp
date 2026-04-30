class Solution {
private:

    void solve(vector<int>& nums, int i, vector<int> currSubset, vector<vector<int>>& subsets){

        if(i == nums.size()){
            subsets.push_back(currSubset);
            return;
        }

        // include element
        currSubset.push_back(nums[i]);
        solve(nums, i+1, currSubset, subsets);

        // backtrack
        currSubset.pop_back();

        // exclude element
        solve(nums, i+1, currSubset, subsets);
    }

public:
    int subsetXORSum(vector<int>& nums) {

        vector<vector<int>> subsets;
        vector<int> currSubset;

        solve(nums, 0, currSubset, subsets);

        int result = 0;

        for(vector<int> subset : subsets){
            int Xor = 0;

            for(int num : subset){
                Xor ^= num;
            }

            result += Xor;
        }

        return result;
    }
};