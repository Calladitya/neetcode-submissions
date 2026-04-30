class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int range = nums.size() / 3;
        vector<int> result;
        unordered_map<int,int> mpp;

        for(auto it : nums){
            mpp[it]++;

            if(mpp[it] == range + 1){
                result.push_back(it);
            }
        }

        return result;
    }
};
