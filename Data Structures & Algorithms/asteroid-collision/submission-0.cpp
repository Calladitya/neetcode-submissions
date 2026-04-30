class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];
            bool destroy = false;

            while(!st.empty() && st.top() > 0 && curr < 0) {

                if(abs(st.top()) < abs(curr)) {
                    st.pop();   // stack wala destroy
                }
                else if(abs(st.top()) == abs(curr)) {
                    st.pop();   // dono destroy
                    destroy = true;
                    break;
                }
                else {
                    destroy = true;   // curr destroy
                    break;
                }
            }

            if(!destroy) {
                st.push(curr);
            }
        }

        vector<int> result(st.size());
        for(int i = st.size()-1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};