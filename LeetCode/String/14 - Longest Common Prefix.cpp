class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pbl;
        
        int min = -1;
        for(int i = 0; i < strs.size(); i++)
        {
            min = (min < strs[i].length())?min:strs[i].length();
        }
        //cout << min << endl;
        
        for(int i = 0; i < min; i++)
        {
            for(int j = 1; j < strs.size(); j++)
            {
                //cout << strs[j-1][i] << ' ' << strs[j][i] << endl;
                if(strs[j-1][i] != strs[j][i]) return pbl;
            }
            pbl += strs[0][i];
        }
        
        return pbl;
    }
};
