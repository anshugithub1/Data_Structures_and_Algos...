/*
Leetcode-->17. Letter Combinations of a Phone Number
Problem Statement:
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = ""
Output: []

Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
 
*/


// Solution

#include<bits/stdc++.h>
using namespace std;
// -------------------------------------------------->> Approach : 1 --> Backtracking ------------------------------>> 

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        
        if (digits.empty()) {
            return res;
        }
        
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        backtrack(digits, 0, "", res, digitToLetters);
        
        return res;        
    }

    void backtrack(const string& digits, int idx, string comb, vector<string>& res, const unordered_map<char, string>& digitToLetters) {
        if (idx == digits.length()) {
            res.push_back(comb);
            return;
        }
        
        string letters = digitToLetters.at(digits[idx]);
        for (char letter : letters) {
            backtrack(digits, idx + 1, comb + letter, res, digitToLetters);
        }
    }    
};

// -------------------------------------------------->> Approach : 2 --> Backtracking ------------------------------>> 
class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};

        std::string phone_map[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> combinations = {""};

        for (char digit : digits) {
            std::vector<std::string> new_combinations;
            for (std::string combination : combinations) {
                for (char letter : phone_map[digit - '2']) {
                    new_combinations.push_back(combination + letter);
                }
            }
            combinations = new_combinations;
        }

        return combinations;
    }
};

// -------------------------------------------------->> Approach : 3 --> for LOOP ------------------------------>> 

class Solution {
private:
    void solve(string digit, string output, int i, vector<string>& ans,
               string mapping[]) {
        if (i >= digit.length()) {
            ans.push_back(output);
            return;
        }

        int num = digit[i] - '0';
        string value = mapping[num];

        for (int j = 0; j < value.length(); j++) {
            output.push_back(value[j]);
            solve(digit, output, i + 1, ans, mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digit) {
        vector<string> ans;
        if (digit.length() == 0) {
            return ans;
        }
        int i = 0;
        string output;
        string mapping[10] = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digit, output, i, ans, mapping);
        return ans;
    }
};