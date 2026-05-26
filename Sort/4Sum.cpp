/*
Problem: 4Sum - Medium(LeetCode)
Links: https://leetcode.com/problems/4sum
Time Complexity: O(N^3) 
Space Complexity: O(logN)

Detail:

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.

nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Example 1:
    Input: nums = [1,0,-1,0,-2,2], target = 0
    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
    Input: nums = [2,2,2,2,2], target = 8
    Output: [[2,2,2,2]]

Constraints:

    1 <= nums.length <= 200
    -109 <= nums[i] <= 109
    -109 <= target <= 109
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
    
        // Sort to enable two-pointers and group duplicates | Sắp xếp để dùng 2 con trỏ và gom số trùng
        sort(nums.begin(), nums.end());
        
        // 1st number (k) | Chốt số thứ 1
        for(int k = 0; k < (int)nums.size() - 3; k++){
            // Skip duplicates for the 1st number | Bỏ qua số thứ 1 nếu trùng lặp
            if(k != 0 and nums[k] == nums[k-1]) continue;
            
            // Cast to long long to prevent integer overflow | Ép kiểu tránh tràn số
            long long target1 = target - nums[k];  

            // 2nd number (i) | Chốt số thứ 2
            for(int i = k + 1; i < (int)nums.size() - 2; i++){
                // Skip duplicates for the 2nd number | Bỏ qua số thứ 2 nếu trùng lặp
                if(i != k + 1 and nums[i] == nums[i-1]) continue;

                // The required sum for the remaining 2 numbers | Tổng cần tìm cho 2 số còn lại
                long long target2 = target1 - nums[i];

                int left, right, current_thir, current_four;
                left = i + 1;            
                right = nums.size() - 1; 
                
                // State tracker to skip duplicates later | Biến lưu vết để skip số trùng ở vòng while
                current_four = current_thir = nums[i] - 1; 

                // Two-pointers for the 3rd and 4th numbers | Kẹp 2 con trỏ tìm số thứ 3 và 4
                while(left < right){
                    int val = nums[left] + nums[right];

                    // Sum too large OR 4th number is a duplicate | Tổng lớn quá HOẶC số thứ 4 bị trùng
                    if(val > target2 or nums[right] == current_four)
                        right--;

                    // Sum too small OR 3rd number is a duplicate | Tổng nhỏ quá HOẶC số thứ 3 bị trùng
                    else if (val < target2 or nums[left] == current_thir)
                        left++;

                    // Found a valid quadruplet | Bắt được bộ 4 số hợp lệ
                    else{
                        result.push_back({nums[k], nums[i], nums[left], nums[right]});

                        // Update state to current valid numbers | Lưu lại vết của số thứ 3 và 4 vừa lụm
                        current_thir = nums[left];
                        current_four = nums[right];

                        // Move both pointers inward | Thu hẹp cả 2 đầu
                        left++;
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};