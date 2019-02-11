#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#define PI 3.14159265
using namespace std;

//Makes a file "18rings.txt" that represents an initial condition of 18 concentric circles

int main() {

	ofstream ofs;
	ofs.open("18rings.txt");
	int N;
	double theta,nexttheta, theta_inc, centernorm, angle_tolerance;
	double length_tolerance = 2*3.85;
	int k = 1;
	double x, y;

	for (int i = 0; i <= 17; i++)
	{
		centernorm = length_tolerance*i;
		nexttheta = PI / 2;	
		if (i>0){
			angle_tolerance = acos((2*pow(i,2)-1)/(2*pow(i,2)));
			k = 2;
			do {
				theta_inc = nexttheta;
				k++;
				nexttheta = 2*PI/k;

			} while(nexttheta > angle_tolerance);
			k--;
		}
		for (int j = 0; j < k; j++)
		{

			x = centernorm * cos (j*theta_inc);
			y = centernorm * sin (j*theta_inc);
			ofs << "CellRank:" << N << '\n';
			ofs << "Center:" << x << "," << y << '\n';
			ofs << "Radius:3.75\n";
			ofs << "Layer:1\n";
			ofs << "Boundary:0\n";
			ofs << "End_Cell\n\n";
			N++;
		}
	}
	ofs.close();


	return 0;
}
