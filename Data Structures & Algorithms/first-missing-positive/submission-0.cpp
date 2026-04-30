class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto num:nums){
            if(num>0){
                st.insert(num);
            }
        }
        int i=1;
        while(true){
            if(st.find(i)==st.end()){
                return i;
            }
            i++;
        }
    }
};