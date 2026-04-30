class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int r=0;r<nums.size();r++){
            int l=r+1;
            while(l<nums.size()){
                if(nums[r]==nums[l] && abs(r-l)<=k){
                    return true;
                }
                l++;
            }
        }
        return false;
    }
};