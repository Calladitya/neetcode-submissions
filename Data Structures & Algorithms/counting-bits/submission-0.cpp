class Solution {
public:
    vector<int> countBits(int n) {
        int count=0;
        vector<int>result;
        for(int i=0;i<=n;i++){
             count=0;
             int temp=i;
             while(temp > 0){
                if(temp & 1){
                    count++;
                }
                temp = temp>>1;
             }
            result.push_back(count);
        }
        return result;
    }
};
