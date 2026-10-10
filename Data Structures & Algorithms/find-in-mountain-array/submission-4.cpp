/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

// class Solution {
// public:
//     int findInMountainArray(int target, MountainArray &mountainArr) {
// //         int n = mountainArr.length() - 1;
// //         int low = 0;
// //         int high = n;
// //         int mid = 0;

// //         while (low <= high) {
// //             mid = (low + high) / 2;

// //             if (mountainArr.get(mid) == target) {
// //                 return mid;
// //             }

// //             if (mountainArr.get(low) <= mountainArr.get(mid)) {
// //                 if (target >= mountainArr.get(low) &&
// //                     target <= mountainArr.get(mid)) {
// //                     high=mid-1;
// //                 } else {
// //                      low=mid+1;
// //                 }
// //             } else {
// //                 if (target >= mountainArr.get(mid) &&
// //                     target <= mountainArr.get(high)) {
// //                    low=mid+1;
// //                 } else {
// //                      high=mid-1;
// //                 }
// //             }
// //         }

// //         return -1;//ye jo uper kiya h solve ye tb lagta h jb array sorted rotated ho samjha kuch;
//     }
// };

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0, high1 = n - 1;
        int high2 = 0, low2 = 0;
        int peak = 0;

        while(low < high1){
            int mid=low+(high1-low)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                low=mid+1;
            }
            else{
                high1=mid;
            }
        }
        peak=low;
        low=0;

        int ans = mountainArr.get(peak);

        if (ans == target) {
            return peak;
        }

        low = 0;
        high2 = peak - 1;

        while (low <= high2) {
            int mid = (low + high2) / 2;

            if (mountainArr.get(mid) == target) {
                return mid;
            }

            if (mountainArr.get(mid) < target) {
                low = mid + 1;
            } else {
                high2 = mid - 1;
            }
        }

        low2 = peak + 1;
        high1 = n - 1;

        while (low2 <= high1) {
            int mid = (low2 + high1) / 2;

            if (mountainArr.get(mid) == target) {
                return mid;
            }

            if (mountainArr.get(mid) > target) {
                low2 = mid + 1;
            } else {
                high1 = mid - 1;
            }
        }

        return -1;
    }
};