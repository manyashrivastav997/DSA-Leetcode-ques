class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0;
        int j = 1;
        int k = 1;
        int n = nums.size();

        

        int count = 1;

        while(j < n)
        {
            if(nums[j] == nums[j-1])
            {
                count++;

                if(count <= 2)
                {
                    nums[i+1] = nums[j];
                    i++;
                    k++;
                }

                j++;
            }
            else
            {
                count = 1;
                nums[i+1] = nums[j];
                i++;
                j++;
                k++;
            }
        }

        return k;
    }
};