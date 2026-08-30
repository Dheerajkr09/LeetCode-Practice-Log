class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int nums1 = INT_MAX;
        int nums2 = INT_MAX;
       
        int i = 0;
        while(i < n)
        {
            if(nums1 >= nums[i])
            {
                nums1 = nums[i];
            }
            else if(nums2 >= nums[i])
            {
                nums2 = nums[i];
            }
            else{
                return true;
            }
            i++;
        }

        return false;
        
    }
};