class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int> mp;

        for(int i = 0;i < n;i++)
        {
            mp[nums[i]]++;
        }
        vector<vector<int>>bucket(n+1);
        for(auto &it: mp)
        {
            int elem = it.first;
            int freq = it.second;
            bucket[freq].push_back(elem);
        }

        vector<int> result;
        for(int i = bucket.size()-1; i >= 0 && result.size() < k;i--)
        {
            for(int num: bucket[i])
                {
                    result.push_back(num);
                    if(result.size() == k) break;
                }
           
        }
        return result;
       
        
    }
};