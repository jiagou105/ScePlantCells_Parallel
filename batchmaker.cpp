#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#define PI 3.14159265
using namespace std;

//Makes a file "18rings.txt" that represents an initial condition of 18 concentric circles

int main() {

	ofstream ofs;
	ofs.open("AUTO_BATCH.txt");
	int test;
	int cores;
	char p[100]; 
	char hours[100];
	char mins[100];
	cout << "Test #: ";
	cin >> test; 
	if (cin.fail()) { 
		cout << "Integer only." << endl;
		ofs.close();
		return 1;
	}
	cin.clear();
	cout << "Number of cores: ";
	cin >> cores; 
	if (cin.fail()) { 
		cout << "Integer only." << endl;
		ofs.close();
		return 1;
	}
	cout << "Hours: ##";
	cin >> hours; 
	if (cin.fail()) { 
		ofs.close();
		return 1;
	}
	cout << "Minutes: ##";
	cin >> mins; 
	if (cin.fail()) { 
		ofs.close();
		return 1;
	}
	cout << "Batch: ";
	cin >> p; 
	if (cin.fail()) { 
		ofs.close();
		return 1;
	}
	ofs << "#!/bin/bash -l\n";
	ofs << "#SBATCH --nodes=1\n";
	ofs << "#SBATCH --ntasks=1\n";
	ofs << "#SBATCH --cpus-per-task=" << cores << "\n";
	ofs << "#SBATCH --mem-per-cpu=2G\n";
	ofs << "#SBATCH --time=0-" << hours << ":" << mins << ":00\n";
	ofs << "#SBATCH --output=my"<< test << ".stdout\n";
	ofs << "#SBATCH --job-name=\"test_" << test << "\"\n";
	ofs << "#SBATCH -p " << p << " \n";

	ofs << "export OMP_NUM_THREADS " << cores << "\n";
	ofs << "mkdir Animate_test_" << test << "\n";
	ofs << "mkdir Nematic_test_1 \n";
	ofs << "mkdir Locations_test_1\n";
	ofs << "./program Animate_test_" << test << " Locations_test_1 Nematic_test_1 \n";
	ofs.close();


	return 0;
}
