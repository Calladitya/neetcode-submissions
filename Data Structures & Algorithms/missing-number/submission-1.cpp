class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // for (int i = 0; i < nums.size() + 1; i++) {
        //     if (find(nums.begin(), nums.end(), i) == nums.end()) {
        //         return i;
        //     }
        // }
        // return -1;
       int ans=0;
       int ans1=0;
        for(int i=0;i<nums.size();i++){
           ans^=nums[i];
           ans1^=i;
        }
        return ans ^ ans1 ^ nums.size();
    }
};
