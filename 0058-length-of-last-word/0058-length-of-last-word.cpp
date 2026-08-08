class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        int idx = n-1; //n-1
        int newidx = 0;

       if(s[idx] == ' ')
       {
              while(s[idx] == ' ')
            {
               newidx++; //spaces count stored
               idx--;
            }

       }
          
            int updated_idx = n-1-newidx;
       
             while(updated_idx >= 0 && s[updated_idx] != ' ')
             {
                count++;
                updated_idx--;
             }

            return count;
    

       
       
        
    }
};