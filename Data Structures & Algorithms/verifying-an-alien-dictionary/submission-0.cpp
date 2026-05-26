class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        unordered_map<char,int> mp;
        for(int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }
        for(int i = 0; i < words.size() - 1; i++) {

            string word1 = words[i];
            string word2 = words[i + 1];

            int len = min(word1.size(), word2.size());

            bool foundDifference = false;
            for(int j = 0; j < len; j++) {

                if(word1[j] != word2[j]) {

                    if(mp[word1[j]] > mp[word2[j]]) {
                        return false;
                    }

                    foundDifference = true;
                    break;
                }
            }
            if(!foundDifference && word1.size() > word2.size()) {
                return false;
            }
        }

        return true;
    }
};