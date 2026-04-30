class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int longest=0;
        for(auto num:st){
           if(st.find(num-1)==st.end()){
            int currnum=num;
            int count=1;
           
           while(st.find(currnum+1)!=st.end()){
            currnum++;
            count++;
           }
           longest=max(longest,count);
        }
      }
        return longest;
    }
};
