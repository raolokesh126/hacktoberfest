/*Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.


Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        int leftmax=0 , rightmax=0, left[height.size()], right[height.size()];
        for(int i = 0 ; i<height.size(); i++ ){
            
                if(height[i]>=leftmax){
                    
                    leftmax = height[i];
                    left[i] = leftmax;
                }else{
                    
                    left[i]= leftmax;
                }
            
            
        }
        for(int i = height.size()-1 ; i>=0; i--){
            
                if(height[i]>=rightmax){
                    
                    rightmax = height[i];
                    right[i] = rightmax;
                }else{
                    
                    right[i]= rightmax;
                }
            
            
        }
        int count=0;
        
        for(int i =0 ; i < height.size(); i++){
            
            count += min(left[i],right[i])-height[i];
        }
        
        return count;
    }
};