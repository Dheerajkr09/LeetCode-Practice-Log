class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // sort for two-pointer + dup skip
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip dup 1st num

            for (int j = i+1; j < n; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue; // skip dup 2nd num

                long long two = (long long)nums[i] + nums[j]; // first two fixed
                int left = j+1, right = n-1;

                while (left < right) {
                    long long sum = two + nums[left] + nums[right]; // total sum

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]}); // found
                        left++; right--;
                        while (left < right && nums[left] == nums[left-1]) left++; // skip dup 3rd
                        while (left < right && nums[right] == nums[right+1]) right--; // skip dup 4th
                    } 
                    else if (sum < target) left++; // increase sum
                    else right--; // decrease sum
                }
            }
        }
        return res;
    }
};