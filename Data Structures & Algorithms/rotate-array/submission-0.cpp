class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        int a=n-k;

        reverse(nums.begin()+a,nums.end());
        reverse(nums.begin(),nums.begin()+a);
        reverse(nums.begin(),nums.end());
    }
};