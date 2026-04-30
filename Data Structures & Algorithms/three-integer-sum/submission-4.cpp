class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // set<vector<int>> st;
        // int n = nums.size();

        // for(int i=0;i<n;i++){

        //     set<int> hashset;

        //     for(int j=i+1;j<n;j++){

        //         int third = -(nums[i] + nums[j]);

        //         if(hashset.find(third) != hashset.end()){

        //             vector<int> temp = {nums[i], nums[j], third};
        //             sort(temp.begin(), temp.end());
        //             st.insert(temp);
        //         }

        //         hashset.insert(nums[j]);
        //     }
        // }

        // vector<vector<int>> result(st.begin(), st.end());
        // return result;

        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                   j++;
                }
                else if(sum>0){
                 k--;
                }
                else{
                   vector<int>temp={nums[i],nums[j],nums[k]};
                   ans.push_back(temp);
                   j++;k--;

                   while(nums[j]==nums[j-1]) j++;
                   while(nums[k]==nums[k+1]) k++;
                }
            }
        }
        return ans;
    }
};
