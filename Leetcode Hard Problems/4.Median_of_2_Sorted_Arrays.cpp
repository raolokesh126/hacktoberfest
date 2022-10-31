/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106*/
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        int gap = ceil((float)(nums1.size()+nums2.size())/2);   
            for(int i = 0; i < nums2.size() ; i++){

                nums1.push_back(nums2[i]);
            }
        
        
       
        do{
            
            vector<int>::iterator it1 = nums1.begin();
            vector<int>::iterator it2 = it1 + gap;
            while(it2!= nums1.end()){

                    if(*it1 > *it2){

                        int t = *it1;
                        *it1 = *it2;
                        *it2 = t;
                    }
                    it1++;
                    it2++;
            }
            
            if((float)gap/2 <1) break;
            gap = ceil((float)gap/2);
            
        }while(gap>=1);

        if(nums1.size()%2!=0){

            return nums1[nums1.size() / 2];
        }else{

            return (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2.0;
        }
        
        
            
    }
};