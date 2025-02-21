/*
Leetcode-->1980. Find Unique Binary String
Problem Statement:
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 
Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.

Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.

Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

Constraints:
n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.

*/

// Solution 
// -------------------------------------------Approach - 1 : Backtracking (T.L.E) ------------------------------------------------------------
class Solution {
private:
    bool checkString(string& str, vector<string>& nums){
        for(auto s : nums){
            if(s == str){
                return true;
            }
        }
        return false;
    }
    void getStrings(int n ,string &str, vector<string>& nums, string& ans){
        if(str.length() == n ){
            if(checkString(str , nums) == false){
                ans = str;
                return; 
            };
            return;
        }

        for(char c : {'0', '1'}){
            str.push_back(c);
            getStrings(n, str, nums,ans);
            str.pop_back();
        }
    }


public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string str;
        string ans;
        getStrings(n, str, nums, ans);
        return ans;  
    }
};

// -------------------------------------------Approach - 2 : Backtracking (with Controlled recursive calls) -----------------------------------

class Solution {
private:
    bool checkString(string& str, vector<string>& nums){
        for(auto s : nums){
            if(s == str){
                return true;
            }
        }
        return false;
    }
    bool getStrings(int n ,string &str, vector<string>& nums, string& ans){
        if(str.length() == n ){
            if(checkString(str , nums) == false){
                ans = str;
                return true; 
            };
            return false;
        }

        for(char c : {'0', '1'}){
            str.push_back(c);
            if(getStrings(n, str, nums,ans)) return true;
            str.pop_back();
        }
        return false;
    }


public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string str;
        string ans;
        getStrings(n, str, nums, ans);
        return ans;  
    }
};

//--------------------------------------------------------------------Approach 3: Diagonal Flipping ------------------------------------- 
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i][i] == '0') {
                result += '1';
            } else {
                result += '0';
            }
        }
        return result;
    }
};