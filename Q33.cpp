
/*
Leetcode-->151. Reverse Words in a String
Problem Statement : 
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.


Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 
Constraints:
1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

*/

//Solution 

// -------------------------------------------->>Approach-1: use of stringstream, extra-space used <<------------------------------------
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        string res;
        for (int i = words.size() - 1; i >= 0; i--) {
            res += words[i];
            if (i != 0) {
                res += " ";
            }
        }

        return res;
    }
};

// -------------------------------------------->>Approach-2: Time - O(n), space - O(1) <<------------------------------------

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans{""}, temp{""};
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && temp!=""){
                reverse(temp.begin(),temp.end());
                if(ans=="")
                    ans=ans+temp;
                else
                    ans=ans+' '+temp;
                temp="";
            }
            else if(s[i]!=' ')
                temp+=s[i];
        }
        if(temp!=""){
        reverse(temp.begin(),temp.end());
        if(ans=="")
            ans=ans+temp;
        else
            ans=ans+' '+temp;
        }
        return ans;
    }
};