class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int n=operations.size();
        for(int i=0;i<n;i++){
            if(operations[i]=="+"){
                 int a=st.top();st.pop();
                 int b=st.top();

                 int sum=a+b;
                 st.push(a);
                 st.push(sum);
            }
            else if(operations[i]=="C"){
                if(!st.empty()) st.pop();
            }
            else if(operations[i]=="D"){
                st.push(2*st.top());
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        int sum2=0;
        while(!st.empty()){
            sum2+=st.top();
            st.pop();
        }
      return sum2;
    }
};