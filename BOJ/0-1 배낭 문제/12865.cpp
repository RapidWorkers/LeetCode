#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;

int knap_btmup(int weight, vector<pair<int, int>>item, vector<vector<int>>& table)//0-1 배낭 문제를 bottom-up으로 계산
{
    //Assume table is 0 initialized. (if i = 0 or w = 0 then table value is 0)
    for (int i = 1; i <= item.size(); i++) {//for all items
        for (int W = 1; W <= weight; W++) {//for all weights
            if (item[i - 1].first <= W) {//W_i is smaller or equal to W
                table[i][W] = max(item[i - 1].second + table[i - 1][W - item[i - 1].first], table[i - 1][W]);//compare which is big, hold or trash
            }
            else {//cannot hold that item
                table[i][W] = table[i - 1][W];//use prev value
            }

        }
    }

    return table[item.size()][weight];//return value
}

int main()
{
    vector<pair<int, int>> items;
    vector<vector<int>> table;

    int N, K;
    cin >> N >> K;

    int itm_v, itm_w;
    for (size_t i = 0; i < N; i++) {
        cin >> itm_w >> itm_v;
        items.push_back(make_pair(itm_w, itm_v));
    }

    for (size_t i = 0; i < N + 1; i++) {//길이보다 행렬 각각 1칸씩 크게 테이블 생성
        table.push_back(vector<int>(K + 1));//무게보다 1칸 길게
    }

    int value = knap_btmup(K, items, table);
    cout << value;

    return 0;
}
