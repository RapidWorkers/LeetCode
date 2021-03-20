class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> table;
        string tmp;
        
        for(auto it = paragraph.begin(); it != paragraph.end(); it++){
            if(!isalpha(*it)) *it = ' ';
            else *it = tolower(*it);
        }
        
        stringstream ss(paragraph);
        
        while(ss >> tmp){            
            bool validStr = 1;
            for(auto it = banned.begin(); it != banned.end(); it++)
                if(*it == tmp) {validStr = 0; break;}
            if(!validStr) continue;
            
            if(table.find(tmp) == table.end()) table.insert(make_pair(tmp, 1));
            else table[tmp]++;
        };
            int max;
            string maxStr;
            
            max = table.begin()->second;
            maxStr = table.begin()->first;
            for(auto it = table.begin(); it != table.end(); it++)
                if(max < it->second) {max = it->second; maxStr = it->first;}
                
            return maxStr;
    };
};
