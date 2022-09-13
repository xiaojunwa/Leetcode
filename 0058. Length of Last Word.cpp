58. Length of Last Word
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 
Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
  
class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx = s.length()-1;
        while(s[idx] == ' ') idx--;
        if(idx < 0) return 0;
        
        int count = 0;
        while(s[idx] != ' '){
            count++;
            idx--;
            if(idx < 0) break;
        }
        
        return count;
    }
};
