class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        int longest = 1;

        unordered_set<int> st;

        for(int i = 0;i < n;i++)
        {
            st.insert(nums[i]);
        }

        for(auto it: st)
        {
            int x = it;
            int count = 1;
            if(st.find(it-1) == st.end())
            { 
                while(st.find(x + 1) != st.end())
                {
                    count+= 1;
                    x++;

                }
            }
            longest = max(longest,count);
        }
        return longest;


        
    }
};