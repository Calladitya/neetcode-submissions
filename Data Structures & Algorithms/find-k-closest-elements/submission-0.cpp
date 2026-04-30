class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int l = 0, r = arr.size() - 1;

        while (r - l + 1 > k) {

            int leftDist = abs(arr[l] - x);
            int rightDist = abs(arr[r] - x);

            // if left is better than right → discard right
            if (leftDist < rightDist || 
               (leftDist == rightDist && arr[l] < arr[r])) {
                r--;
            }
            else {
                l++;
            }
        }

        return vector<int>(arr.begin()+l, arr.begin()+r+1);
    }
};