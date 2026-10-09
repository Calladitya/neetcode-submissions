
// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         priority_queue<int, vector<int>> pq;

//         for (int i = 0; i < stones.size(); i++) {
//             pq.push(stones[i]);
//         }

//         while (pq.size() > 1) {
//             int x = pq.top();
//             pq.pop();

//             int y = pq.top();
//             pq.pop();

//             if (x != y) {
//                 pq.push(x - y);
//             }
//         }

//         if (!pq.empty()) {
//             return pq.top();
//         }

//         return 0;
//     }
// };


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;

        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }

        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            
            if (pq.empty()) {
                return x;
            }

            int y = pq.top();
            pq.pop();

            if (x == y) {
                continue;
            }
            if (x < y) {
                y = y - x;
                pq.push(y);
            }
            else {
                x = x - y;
                pq.push(x);
            }
        }
        return 0;
    }
};


