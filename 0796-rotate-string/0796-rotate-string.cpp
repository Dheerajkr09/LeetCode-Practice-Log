class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;   // length match nahi toh seedha false

        string s1 = s + s;

        for (int i = 0; i < s1.size(); i++)           // har starting point try karo
        {
            if (s1[i] == goal[0])                      // pehla character match mila
            {
                int idx = i;
                int k = 0;
                int check = 1;

                while (k < goal.size())
                {
                    if (goal[k] != s1[idx])             // koi bhi character mismatch
                    {
                        check = 0;
                        break;
                    }
                    k++;
                    idx++;
                }

                if (check == 1)
                {
                    return true;                         // pura match mil gaya
                }
            }
        }

        return false;                                    // kahin bhi match nahi mila
    }
};