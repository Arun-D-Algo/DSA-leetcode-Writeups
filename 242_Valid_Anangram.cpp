/*
LeetCode 242 - Valid Anagram

Given two strings s and t, return true if t is an anagram of s,
and false otherwise.`

An anagram is formed by rearranging the letters of a word or phrase,
using all the original letters exactly once.

Approach:
1. If the lengths of the two strings are different, they cannot be anagrams,
   so return false immediately.
2. Create a frequency array of size 26 to store the count of each lowercase letter.
3. Traverse string s and increment the count of each character.
4. Traverse string t and decrement the count of each character.
5. If the strings are anagrams, every count in the frequency array should be zero.
6. Check the frequency array:
   - If any value is not zero, return false.
   - Otherwise, return true.

Time Complexity: O(n)
Space Complexity: O(1)
(Only a fixed-size array of 26 elements is used.)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        int frequency[26] = {0};

        for (char c : s) {
            frequency[c - 'a']++;
        }

        for (char c : t) {
            frequency[c - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (frequency[i] != 0)
                return false;
        }

        return true;
    }
};