class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> rmToChk;
        vector<bool> rmChkTbl(rooms.size());
        rmToChk.push(0);
        
        while(!rmToChk.empty()){
            int currentRoom = rmToChk.front();
            rmToChk.pop();
            if(rmChkTbl[currentRoom] == true) continue;//no need to check anymore
            else rmChkTbl[currentRoom] = true; //visited
            
            for(int i = 0; i < rooms[currentRoom].size(); i++){
                if(rmChkTbl[rooms[currentRoom][i]]) continue;
                else rmToChk.push(rooms[currentRoom][i]);
            }
        }
        
        for(int i = 0; i < rmChkTbl.size(); i++){
            if(!rmChkTbl[i]) return false;
        }
        
        return true;
        
    }
};