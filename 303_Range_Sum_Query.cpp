/*
LeetCode 303 - Range Sum Query - Immutable

Given an integer array nums, handle multiple queries of the following type:

- Return the sum of the elements of nums between indices left and right inclusive.

Implement the NumArray class:
- NumArray(int[] nums) initializes the object with the integer array nums.
- int sumRange(int left, int right) returns the sum of the elements between
  indices left and right inclusive.

Approach:
1. Create a prefix sum array where each index stores the cumulative sum
   from index 0 to the current index.
2. Build the prefix sum array once in the constructor.
3. For each query:
   - If left == 0, return prefix[right].
   - Otherwise, return prefix[right] - prefix[left - 1].
4. This allows each range sum query to be answered in constant time.

Example:
nums = [-2, 0, 3, -5, 2, -1]

prefix = [-2, -2, 1, -4, -2, -3]

sumRange(2, 5)
= prefix[5] - prefix[1]
= (-3) - (-2)
= -1

Time Complexity:
- Constructor: O(n)
- sumRange(): O(1)

Space Complexity: O(n)
*/

class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int>& nums) {
        prefix.resize(nums.size());

        prefix[0] = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if(left == 0)
            return prefix[right];

        return prefix[right] - prefix[left - 1];
    }
};