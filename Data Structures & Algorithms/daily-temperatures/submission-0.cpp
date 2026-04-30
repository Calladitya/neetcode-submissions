class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>res(temperatures.size(),0);
        stack<pair<int,int>>st;

        for(int i=0;i<temperatures.size();i++){
            int curr=temperatures[i];

            while(!st.empty() && curr > st.top().first){
                auto pair=st.top();
                st.pop();

                res[pair.second]=i-pair.second;
            }
            st.push({curr,i});
        }
        return res;
    }
};
