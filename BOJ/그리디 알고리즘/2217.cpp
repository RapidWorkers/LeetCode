#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main() {

	vector<int> rope;
	int a, t;
	
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> t;
		rope.push_back(t);
	}

	sort(rope.begin(), rope.end(), desc);

	int max = 0;
	for (int i = 0; i < a; i++) {
		max = (max > rope[i] * (i + 1)) ? max : rope[i] * (i + 1);
	}

	cout << max;
}