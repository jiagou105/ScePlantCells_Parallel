//tissue.h
//=================
//Include Guards
#ifndef _TISSUE_H_INCLUDED_
#define _TISSUE_H_INCLUDED_
//=========================
//forward declarations

//=======================
//Include dependencies
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include "phys.h"
#include "coord.h"
#include "node.h"
#include "cell.h"
//=========================
// Tissue Class Declaration

//class Tissue: public enable_shared_from_this<Tissue> {
class Tissue {
	private:
		// We'll need a better data structure for later
		vector<shared_ptr<Cell>> cells;
		//Division information data structure.  
		//Holds the form (Timestep, Dividing cell ancestry, CenterX, CenterY, DivplaneX, DivplaneY).
		vector<vector<double>> div_info;
		int numDivs;
		int num_cells;
		//This is the cutoff 
		double R_eff;
		//average value of all cell centers;
		Coord tissue_center;

	public:
		Tissue(string filename);
		void get_Cells(vector<shared_ptr<Cell>>& cells);
		//set/get the number of cells in the tissue
		void update_Num_Cells(shared_ptr<Cell>& new_Cell);
		int  get_num_cells() {return num_cells;}
		void update_Neighbor_Cells();
		void add_Wall(int Ti);
		void delete_Wall(int Ti);
		//not in use
		void update_Linear_Bending_Springs();
		void update_Cell_Cycle(int Ti);
		bool division_check(double time);
		int get_Num_Divisions() { return numDivs; };
		void calc_New_Forces(int Ti);
		void update_Cell_Locations();

		//Adhesion 
		void peel();
		void update_Adhesion();

		//Growth rate dropoff
		void update_R_eff();
		
		//Tissue center functions
		void update_Tissue_Center();
		Coord get_Tissue_Center() {return tissue_center;};
		double get_R_eff() {return R_eff;};
		
		//stuff for data output
		void plot_direction_vec(ofstream& ofs);
		void print_Data_Output(ofstream& ofs);
		void locations_output(ofstream& ofs);
		int update_VTK_Indices();
		void print_VTK_File(ofstream& ofs);
		void print_VTK_Direction_File(ofstream& ofs);	
		
		void print_Div_Info(ofstream& ofs);
		//Destructor
		~Tissue();
};


//===========================
//End of file

#endif
