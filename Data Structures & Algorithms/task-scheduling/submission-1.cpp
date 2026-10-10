
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        for (char ch : tasks) {
            mp[ch]++;
        }

        priority_queue<int> pq;

        for (auto it : mp) {
            pq.push(it.second);
        }

        int count = 0;

        while (!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;

            while (cycle > 0 && !pq.empty()) {
                int freq = pq.top();
                pq.pop();

                if (freq > 1) {
                    temp.push_back(freq - 1);
                }

                count++;
                cycle--;
            }

            for (int freq : temp) {
                pq.push(freq);
            }

            if (!pq.empty()) {
                count += cycle;
            }
        }

        return count;
    }
};
