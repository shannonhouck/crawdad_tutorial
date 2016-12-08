#include "molecule.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	// create new Molecule
	Molecule ace("input.txt", 0);

	ace.pointGroup ="c2v";

	// print information
	cout << "Number of atoms: " << ace.natoms << endl;
	cout << "Cartesian Coordinates: " << endl;

	// print geometry
	ace.printGeom();

	// print bond lengths
	cout << "Bond Distances (bohr):" << endl;
	ace.printBonds();

	// test translation
	cout << "Testing translation:" << endl;
	ace.translate(5.0, 0.0, 3.0);

	// print geometry
	ace.printGeom();

	return 0;
}

