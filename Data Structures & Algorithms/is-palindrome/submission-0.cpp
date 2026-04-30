class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;int j=s.size()-1;
        while(i<j){
            if(!isalnum(s[i])){
                i++;continue;
            }
            if(!isalnum(s[j])){
                j--;;continue;
            }
           if(toupper(s[i]) != toupper(s[j])){//we have used here tolower or to upper because it in question it not return that there is diff between 'a' and "A" hence for this  we have used to lower and toupper case letter,to make there ascll value equal becuase while we campare them there ascll value will us some diff.
                return false;
            }
            i++;j--;
        }
        return true;
    }
};
