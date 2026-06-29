class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
     int n = nums.size();
     vector<int>arr(n);
     int i = 0;
     int j = n-1;
     int k = n-1;
     while(i<=j){
        if(nums[i]*nums[i] < nums[j]*nums[j]){
            arr[k] = nums[j]*nums[j] ;
            j--;

        }
        else{
            arr[k] = nums[i]* nums[i] ;
            i++;
        }
        k--;
     }
     return arr;


    }
};