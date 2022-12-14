53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
  
  
class Solution {
public:
    //Analyze: dp[i]: the largest sum so far that include nums[i]
    //if the prev dp is positive, must include it; otherwise start over
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1; i < nums.size(); i++){
            if(dp[i-1] < 0) dp[i] = nums[i];
            else dp[i] = dp[i-1] + nums[i];
            res = max(res, dp[i]);
        }
        return res;
    }
};
