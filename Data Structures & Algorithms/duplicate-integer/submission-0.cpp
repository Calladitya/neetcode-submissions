class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
             auto it= find(nums.begin()+i+1,nums.end(),nums[i]);

             if(it!=nums.end()) return true;
        }return false;
    }
};