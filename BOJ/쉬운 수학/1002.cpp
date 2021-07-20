#include <iostream>

using namespace std;

int main() {

	//declare var
	int count;

	//get count from user
	cin >> count;
	
	//dynamically allocate array
	int **pos = new int*[count];

	//repeat by count
	for (int i = 0; i < count; i++) {
		pos[i] = new int[6];//create new position array
		cin >> pos[i][0] >> pos[i][1] >> pos[i][2] >> pos[i][3] >> pos[i][4] >> pos[i][5];//get input from user
	}

	for (int i = 0; i < count; i++) {
		int distance_sq = (pos[i][0] - pos[i][3])*(pos[i][0] - pos[i][3]) + (pos[i][1] - pos[i][4])*(pos[i][1] - pos[i][4]);//distance between points
		int rad_sum_sq = (pos[i][2] + pos[i][5]) * (pos[i][2] + pos[i][5]);//(r1 + r2)^2
		int rad_minus_sq = (pos[i][2] - pos[i][5]) * (pos[i][2] - pos[i][5]);//(r1 - r2)^2

		if (distance_sq == 0 && pos[i][2] == 0 && pos[i][5] == 0)
			cout << 1 << endl;
		else if (distance_sq == 0 && pos[i][2] == pos[i][5]) //the circle is same
			cout << -1 << endl;
		else if (distance_sq == rad_sum_sq)//external contact at one point
			cout << 1 << endl;
		else if (distance_sq == rad_minus_sq)//inner contact at one point
			cout << 1 << endl;
		else if (distance_sq > rad_minus_sq && distance_sq < rad_sum_sq) //meet at two points
			cout << 2 << endl;
		else //does not meet
			cout << 0 << endl;
	}

	//deallocate dynamically created array
	for (int i = 0; i < count; i++) {
		delete[] pos[i];
	}
	delete[] pos;

	return 0;

}