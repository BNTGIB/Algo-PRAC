/*
Problem: Sort Colors - Medium (LeetCode)\
Links: https://leetcode.com/problems/sort-colors
Time Complexity: O(NLogN)

Detail:

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

Example 2:

    Input: nums = [2,0,1]
    Output: [0,1,2]
 
Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 
Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/
#include <vector>
using namespace std;

void quickSort(vector<int>& nums, int left, int right){
    if(left >= right) return;
    int i=left, j=right;
    int pivot = nums[(left+right)/2];
    while(i<j){
        while(nums[i]<pivot) i++;
        while(nums[j]>pivot) j--;

        if(i<=j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }   
    }
    quickSort(nums,left,j);
    quickSort(nums,i,right);
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
    }
};