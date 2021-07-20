#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs_topdown(string &X, string &Y, int i, int j, vector<vector<int>> &table)
{
    if(i == 0 || j == 0) return 0;//base case of LCS
    else if(table[i - 1][j - 1] >= 0)//Result already on table!!
        return table[i-1][j-1];//We've already calculated
    else if(X.c_str()[i - 1] == Y.c_str()[j - 1])//i_th value of X and j_th value of Y are same
        return table[i-1][j-1] = 1 + lcs_topdown(X, Y, i-1, j-1, table);//recursively call the function to calculate
    else {//if not same element value on current position
        int left = lcs_topdown(X, Y, i-1, j, table);
        int right = lcs_topdown(X, Y, i, j-1, table);
        return table[i-1][j-1] = (left > right)?left:right;//compare two cases and choose the bigger one
    }
}

int main()
{
    string A, B;
    cin >> A >> B;
    vector<vector<int>> table;

    for(size_t i = 0; i < A.length(); i++)
        table.push_back(vector<int>(B.length(), -1));

    cout << lcs_topdown(A, B, A.length(), B.length(), table);
}
