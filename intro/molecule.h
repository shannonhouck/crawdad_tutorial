#include <string>

using namespace std;

/********************************************************
 Author: Shannon Houck (based on Crawford tutorial)
 Date Edited: November 18, 2016

 The Molecule class is responsible for holding data
 about a molecule. This is the header for that class.

 Stores coordinates, the "z values" (atomic numbers),
 overall charge, and symmetry.
 Also contains functions for transforming the Molecule
 and printing information about it.
 ********************************************************/

class Molecule
{
 public:
	// variables
	int natoms; // number of atoms
	int charge; // overall charge of molecule
	int* zvals; // atomic numbers of atoms
	double** geom; // coordinates of atoms
	string pointGroup; // point group of molecule
	
	// functions
	void printGeom();
	void translate(double x, double y, double z);
	void rotate(double phi);
	double bond(int a1, int a2);
	double angle(int a1, int a2, int a3);
	double torsion(int a1, int a2, int a3, int a4);
	
	// default constructor
	Molecule();

	// read-from-file constructor
	Molecule(string filename, int q);

	~Molecule();
};
