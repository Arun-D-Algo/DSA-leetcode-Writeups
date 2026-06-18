/*
LeetCode 238 - Product of Array Except Self

Given an integer array nums, return an array answer such that
answer[i] is equal to the product of all elements of nums except nums[i].

The solution must run in O(n) time and cannot use division.

Approach:
1. Create three arrays:
   - prefix[i] stores the product of all elements before index i.
   - suffix[i] stores the product of all elements after index i.
   - answer[i] stores the final result.
2. Initialize:
   - prefix[0] = 1 because there are no elements to the left of index 0.
   - suffix[n-1] = 1 because there are no elements to the right of the last index.
3. Build the prefix array:
   - For each index i, multiply the previous prefix product by nums[i-1].
4. Build the suffix array:
   - Traverse from right to left.
   - For each index i, multiply the next suffix product by nums[i+1].
5. Compute the final answer:
   - answer[i] = prefix[i] * suffix[i]
   - This gives the product of all elements except nums[i].
6. Return the answer array.

Example:
nums = [1,2,3,4]

prefix = [1,1,2,6]
suffix = [24,12,4,1]

answer:
[1*24, 1*12, 2*4, 6*1]
= [24,12,8,6]

Time Complexity: O(n)
- One pass to build prefix array.
- One pass to build suffix array.
- One pass to build answer array.

Space Complexity: O(n) (couldnt figure out O(1) at all)
- Three additional arrays of size n are used.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> answer(n);

        prefix[0] = 1;

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        suffix[n-1] = 1;

        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for(int i=0;i<n;i++){
            answer[i] = prefix[i] * suffix[i];
        }

        return answer;
    }
};