class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        long long sum;
        for(int i=0;i<nums.size();i++){
            sum=0;
            for(int j=i+1;j<nums.size();j++){
                int k=j+1;
                int l=nums.size()-1;
                while(k<l){
                sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                if(sum==target){
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                   st.insert(temp);
                   k++;
                   l--;
                }
                else if(sum>target){
                    l--;
                }else{
                    k++;
                }
              } 
            }
        }
         vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};