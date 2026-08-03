class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (valueDiff < 0) return false;
        unordered_map<long, long> buckets;
        long width = (long)valueDiff + 1;
        
        for (int i = 0; i < nums.size(); i++) {
            long bucketId = (long)nums[i] / width;
            if (nums[i] < 0) bucketId--;
            
            if (buckets.count(bucketId)) return true;
            if (buckets.count(bucketId - 1) && abs(nums[i] - buckets[bucketId - 1]) <= valueDiff) return true;
            if (buckets.count(bucketId + 1) && abs(nums[i] - buckets[bucketId + 1]) <= valueDiff) return true;
            
            buckets[bucketId] = nums[i];
            
            if (i >= indexDiff) buckets.erase((long)nums[i - indexDiff] / width - (nums[i-indexDiff] < 0 && nums[i-indexDiff] % width != 0 ? 1 : 0));
        }
        return false;
    }
};