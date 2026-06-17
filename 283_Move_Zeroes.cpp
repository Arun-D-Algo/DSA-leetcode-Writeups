/*
LeetCode 283 - Move Zeroes

Given an integer array nums, move all 0's to the end of it
while maintaining the relative order of the non-zero elements.

The operation must be performed in-place without making a copy
of the array.

Approach:
1. Use a pointer j to track the position where the next non-zero
   element should be placed.
2. Traverse the array using pointer i.
3. Whenever a non-zero element is found:
   - Place it at index j.
   - Increment j.
4. After all non-zero elements have been moved to the front,
   fill the remaining positions in the array with 0's.
5. This preserves the relative order of non-zero elements
   while moving all zeroes to the end.

Example:
Input: [0,1,0,3,12]

First Pass:
j = 0

i = 1 -> nums[j] = 1
[1,1,0,3,12]
j = 1

i = 3 -> nums[j] = 3
[1,3,0,3,12]
j = 2

i = 4 -> nums[j] = 12
[1,3,12,3,12]
j = 3

Second Pass:
Fill remaining positions with 0

[1,3,12,0,0]

Output: [1,3,12,0,0]

Time Complexity: O(n)
(Each element is visited at most once.)

Space Complexity: O(1)
(No extra data structures are used.)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }

        while(j < nums.size()) {
            nums[j] = 0;
            j++;
        }
    }
};