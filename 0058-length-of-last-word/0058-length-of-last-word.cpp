
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        int idx = n-1;        // last character se start
        int spaceCount = 0;   // trailing spaces ginne ke liye

       if(s[idx] == ' ')
       {
              while(s[idx] == ' ')
            {
               spaceCount++;  // spaces count stored
               idx--;
            }

       }
          
            int wordEndIdx = n-1-spaceCount;   // last word ka actual end index
       
             while(wordEndIdx >= 0 && s[wordEndIdx] != ' ')  // bounds check + space na aaye tab tak
             {
                count++;
                wordEndIdx--;
             }

            return count;
    }
};