class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> resultFindTbl;
        vector<vector<string>> result;
        
        for(auto it = strs.begin(); it != strs.end(); it++){
            string tmp = *it;
            sort(tmp.begin(), tmp.end());
            if(resultFindTbl.find(tmp) == resultFindTbl.end()){
                resultFindTbl.insert(make_pair(tmp, result.size()));
                result.push_back(vector<string>{});
            }
            result[resultFindTbl.find(tmp)->second].push_back(*it);
        }
        
        return result;
    }
};
