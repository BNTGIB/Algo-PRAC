/*
Problem: 3Sum - Medium(LeetCode)
Links: https://leetcode.com/problems/3sum
Time Complexity: O(N^2) 
Space Complexity: O(logN)
- Performance: "Beats 84.50% in Time on LeetCode :>"

Detail:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 
Example 1:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]

Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
    Input: nums = [0,1,1]   
    Output: []
    Explanation: The only possible triplet does not sum up to 0.

Example 3:
    Input: nums = [0,0,0]
    Output: [[0,0,0]]
    Explanation: The only possible triplet sums up to 0.
 
Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Sort mảng là "bệ phóng" bắt buộc để dùng Two Pointers và gom các số trùng lặp lại gần nhau
        sort(nums.begin(), nums.end());

        // Chốt số thứ nhất 'a'. Trừ đi 2 vì luôn cần chừa lại khoảng trống cho 'b' (left) và 'c' (right)
        for(size_t i = 0; i < nums.size() - 2; i++){
            // Bỏ qua các số 'a' trùng lặp với số trước đó để tránh sinh ra các bộ 3 y chang nhau
            if(i != 0 and nums[i] == nums[i-1]) continue;

            int left, right, current_sec, current_thir;
            left = i + 1;            // Con trỏ trái xuất phát ngay sau 'a'
            right = nums.size() - 1; // Con trỏ phải kẹp từ cuối mảng về

            // Biến lưu vết (state) để nhớ giá trị của 'b' và 'c' ở lần lụm thành công gần nhất
            current_sec = current_thir = nums[i] - 1; 

            while(left < right){
                int val = nums[left] + nums[right]; // Tính tổng b + c

                // Trường hợp 1: Tổng b+c quá lớn (so với mục tiêu là -a) 
                // HOẶC số 'c' hiện tại đang bị trùng với số 'c' vừa lụm ở bước trước -> Dịch con trỏ phải
                if(val > -nums[i] or nums[right] == current_thir)
                    right--;
                
                // Trường hợp 2: Tổng b+c quá bé 
                // HOẶC số 'b' hiện tại trùng với số 'b' vừa lụm ở bước trước -> Dịch con trỏ trái
                else if (val < -nums[i] or nums[left] == current_sec)
                    left++;
                
                // Trường hợp 3: Bắt được bộ 3 hoàn hảo (b + c == -a)
                else{
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Cập nhật lại vết (Lưu lại giá trị b và c vừa lụm)
                    // Nhờ 2 biến này, các vòng lặp while tiếp theo sẽ tự động rơi vào case 1 hoặc 2 để skip trùng lặp
                    current_sec = nums[left];
                    current_thir = nums[right];
                    
                    // Thu hẹp cả 2 đầu để đi tìm tổ hợp 'b' và 'c' mới
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};