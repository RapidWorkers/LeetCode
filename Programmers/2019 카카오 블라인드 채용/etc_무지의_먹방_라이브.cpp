#include <string>
#include <vector>

using namespace std;

/*
* 2019 카카오 블라인드 채용
* 무지의 먹방 
*/

int solution(vector<int> food_times, long long k) {
    long long min_cycle = k / food_times.size();
    long long left = k - min_cycle * food_times.size();

    while (min_cycle) {
        for (int i = 0; i < food_times.size(); i++) {
            if (food_times[i] > 0) food_times[i] -= min_cycle;
            if (food_times[i] < 0) {
                left = left - food_times[i];
                food_times[i] = 0;
            }
        }

        int nonzeros = 0;
        for (int i = 0; i < food_times.size(); i++) {
            if (food_times[i] != 0) nonzeros++;
        }
        
        if(!nonzeros) break;

        min_cycle = left / nonzeros;
        left = left - min_cycle * nonzeros;
    }

    int nonzeros = 0;
    for (int i = 0; i < food_times.size(); i++) {
        if (food_times[i] != 0) nonzeros++;
    }
    if(!nonzeros) return -1;
    
    int idx = 0;
    for (long long i = 0; i <= left; i++) {
        if (food_times[idx++] == 0) i--;
    }

    return idx;
}
