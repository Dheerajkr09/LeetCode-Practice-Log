class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int> mp;

        for(int i = 0;i < n;i++)
        {
            int ele = nums[i];

            if(mp.find(ele) != mp.end())
            {
                return true;
            }

            mp[nums[i]] = i;
        }

        return false;
        
    }
};