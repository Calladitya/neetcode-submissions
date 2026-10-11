class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int ans=w;
        int maxi=-1;
        int index=-1;
        unordered_map<int,int>check;

        while(k > 0){
            maxi=-1;
            index=-1;

            for(int i=0;i<capital.size();i++){
                if(check.find(i) == check.end() && capital[i] <= ans && profits[i] > maxi){
                    maxi=profits[i];
                    index=i;
                }
            }
            if(index== -1){
                break;
            }
            ans+=profits[index];
            check[index]++;
            k--;
        }
        return ans;
    }
};