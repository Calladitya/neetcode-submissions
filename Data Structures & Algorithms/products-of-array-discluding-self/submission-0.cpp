class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     int n=nums.size();
     vector<int>result(n,1);

     int left_product=1;
     int right_product=1;
     int k=0;
     int j=nums.size()-1;
     while(k<n && j>=0){
        result[k]*=left_product;
        left_product*=nums[k];

        result[j]*=right_product;
        right_product*=nums[j];

        j--;
        k++;
     }
     return result;
    }
};
