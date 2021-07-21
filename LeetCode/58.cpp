class Solution {
public:
    int lengthOfLastWord(string s) {
        int lenLast = 0;
        int lenCur = 0;
        
        int prevSpace = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ')
            {
                if(!prevSpace)
                {
                    lenLast = lenCur;
                    lenCur = 0;
                }
                prevSpace = 1;
            }
            else
            {
                lenCur++;
                prevSpace = 0;
            }
        }
        
        if(!prevSpace) lenLast = lenCur;
        return lenLast;
    }
};
