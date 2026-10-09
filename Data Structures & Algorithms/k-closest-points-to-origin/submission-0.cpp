
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<int>> result;

        for (int i = 0; i < points.size(); i++) {
            int x1 = points[i][0];
            int x2 = points[i][1];

            int ans = (x1 * x1) + (x2 * x2);
            pq.push({ans, x1, x2});
        }

        while (!pq.empty() && k > 0) {
            auto [ans, x, y] = pq.top();
            pq.pop();

            result.push_back({x, y});
            k--;
        }

        return result;
    }
};

