class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        char* ptr = new char[s.length()+1];
        ptr[s.length()] = 0;
        
        for(int i = 0; i < s.size(); i++){
            ptr[indices[i]] = s[i];
        }
        
        string restored = ptr;
        delete[] ptr;
        
        return restored;
    }
};
