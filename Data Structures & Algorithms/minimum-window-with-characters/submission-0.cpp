class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        for( char c:t){
            mpp[c]++;
        }
        int need=mpp.size();
        unordered_map<char,int>window;
        int l=0;
        int start=0;
        int have=0;
        int mini=INT_MAX;
        for(int r=0;r<s.size();r++){
            char c=s[r];
            window[c]++;
            if(mpp.count(c) && window[c]==mpp[c]){
                have++;

                while(need==have){
                    if(r-l+1 < mini){
                        mini=r-l+1;
                        start=l;
                    }
                    window[s[l]]--;
                    if(mpp.count(s[l]) && window[s[l]] < mpp[s[l]]){
                        have--;
                    }
                    l++;
                }
            }
        }
        if(mini == INT_MAX) return "";
        return s.substr(start, mini);
    }
};
