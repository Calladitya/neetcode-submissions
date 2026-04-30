class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int profit = 0;

        for(int i=0;i<prices.size();i++){
            mini = min(mini, prices[i]);          // best buy so far
            profit = max(profit, prices[i]-mini); // sell today
        }
        return profit;
    }
};
