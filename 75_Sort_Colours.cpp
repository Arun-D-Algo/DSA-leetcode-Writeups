/*
LeetCode 75 - Sort Colors

Given an array nums containing n objects colored red, white, or blue, sort them in-place so that
objects of the same color are adjacent, with the colors in the order red, white, and blue.

The integers 0, 1, and 2 represent the colors red, white, and blue respectively.

The array must be modified in-place without using the library's sort function.

Approach:
1. Use Bubble Sort to repeatedly compare adjacent elements.
2. If the current element is greater than the next element, swap them using the XOR Swap technique.
3. After each pass, the largest unsorted element moves to its correct position at the end of the array.
4. Continue until the entire array is sorted.

XOR Swap Steps:
a = a ^ b
b = a ^ b
a = a ^ b

This swaps two numbers without using a temporary variable.

Time Complexity: O(n²)
Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums.size() - i - 1; j++) {
                if(nums[j] > nums[j + 1]) {
                    nums[j] = nums[j] ^ nums[j + 1];
                    nums[j + 1] = nums[j] ^ nums[j + 1];
                    nums[j] = nums[j] ^ nums[j + 1];
                }
            }
        }
    }
};