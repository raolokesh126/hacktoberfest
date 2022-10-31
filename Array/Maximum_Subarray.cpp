// link to question :https://leetcode.com/problems/maximum-subarray/

// Question ::Given an integer array nums, find the subarray which has the largest sum and return its sum.

// Solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=nums[0];
        int maxsum=nums[0];
        int i=1;
        while(i<nums.size()){
            if(cursum<0) {
                cursum=nums[i];
            }
            else{
               cursum+=nums[i]; 
            }
             if(cursum>maxsum){
                maxsum=cursum;
            }
            i++;
        }
        return(maxsum);
        
    }
};
