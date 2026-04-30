class Solution {
public:
    string decodeString(string s) {
        
        stack<string> st1;
        stack<int> st2;
        
        string curr = "";
        int num = 0;
        
        for(char c : s){
            
            if(isdigit(c)){
                num = num*10 + (c-'0');
            }
            
            else if(c == '['){
                st2.push(num);
                st1.push(curr);
                num = 0;
                curr = "";
            }
            
            else if(c == ']'){
                
                int k = st2.top();
                st2.pop();
                
                string prev = st1.top();
                st1.pop();
                
                string temp = "";
                for(int i=0;i<k;i++){
                    temp += curr;
                }
                
                curr = prev + temp;
            }
            
            else{
                curr += c;
            }
        }
        
        return curr;
    }
};