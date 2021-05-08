class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> dupTable;
        for(auto n : nums){
            if(dupTable.find(n) != dupTable.end()) return true;
            dupTable.insert(pair<int, bool>(n, true));
        }
        return false;
    }
};
