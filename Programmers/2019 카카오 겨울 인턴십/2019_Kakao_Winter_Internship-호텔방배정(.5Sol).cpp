#include <string>
#include <vector>
#include <map>

using namespace std;

long long find(map<long long, long long>& rmUsed, long long u);
void unify(map<long long, long long>& rmUsed, long long u, long long v);

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    map<long long, long long> rmUsed;//rm#, next rm#

    for (auto roomNum : room_number) {//n
        if (rmUsed.find(roomNum) != rmUsed.end()) {//not empty
            //should find least big num here, but how?
            roomNum = find(rmUsed, roomNum) + 1;//new room number allocation
        }

        rmUsed.insert(pair<long long, long long>(roomNum, roomNum));//logn
        answer.push_back(roomNum);//insert answer

        if (rmUsed.find(roomNum + 1) != rmUsed.end())//next room already used
            unify(rmUsed, roomNum, roomNum + 1);//n

        if (roomNum > 1 && rmUsed.find(roomNum - 1) != rmUsed.end())//prev room already used
            unify(rmUsed, roomNum - 1, roomNum);//n

        //Total O(n^2)
    }

    return answer;
}

long long find(map<long long, long long>& rmUsed, long long u)
{
    if (rmUsed.find(u) == rmUsed.end()) return -1;//not allocated yet
    if (rmUsed.find(u)->second == u) return u;

    int findRes = find(rmUsed, rmUsed.find(u)->second);
    return rmUsed.find(u)->second = (findRes == -1) ? u : findRes;
}

void unify(map<long long, long long>& rmUsed, long long u, long long v)
{
    u = find(rmUsed, u);
    v = find(rmUsed, v);
    if (u == v) return;
    rmUsed.find(u)->second = v;//set new next room
}
