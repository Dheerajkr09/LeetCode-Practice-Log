class Solution {
public:

    string generate(string& word)
    {
        int hash[26] = {0};
        
        for(char& ch:word)
        {
            hash[ch-'a']++;
        }
        string new_word = "";
        for(int i = 0;i < 26;i++)
        {
            int count = hash[i];
            new_word += string(count, i+'a');
        }
        return new_word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        unordered_map<string, vector<string>> mp;

        vector<vector<string>> result;

        for(int i = 0;i < n;i++)
        {
            string word = strs[i];

            string new_word = generate(word);

            mp[new_word].push_back(strs[i]);

        }

        for(auto it:mp)
        {
            result.push_back(it.second);
        }

        return result;

        





       
        
    }
};