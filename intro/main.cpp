#include "molecule.h"

using namespace std;

int main(int argc, char* argv[])
{
	// create new Molecule
	Molecule h2o;

	// set up variables
	int numAtoms = 3;
	h2o.natoms = numAtoms;
	h2o.charge = 0;
	h2o.pointGroup ="c2v";

	// set up matrices
	h2o.zvals = new int[numAtoms];
	h2o.geom = new double*[numAtoms];
	for(int i=0; i<numAtoms; i++)
	{
		h2o.geom[i] = new double[3];
	}

	// set z-vals of Molecule
	h2o.zvals[0] = 1;
	h2o.zvals[1] = 8;
	h2o.zvals[2] = 1;

	// set coordinates of Molecule
	h2o.geom[0][0] = 0.00000;
	h2o.geom[0][1] = 1.41500;
	h2o.geom[0][2] = 0.97104;

	h2o.geom[1][0] = 0.00000;
	h2o.geom[1][1] = 0.00000;
	h2o.geom[1][2] = -0.12237;

	h2o.geom[2][0] = 0.00000;
        h2o.geom[2][1] = -1.41500;
        h2o.geom[2][2] = 0.97104;

	// print geometry
	h2o.printGeom();

	// test translation
	h2o.translate(5.0, 0.0, 3.0);

	// print geometry
	h2o.printGeom();

	// delete matrices
	delete[] h2o.zvals;
	for(int i=0; i<numAtoms; i++)
	{
		delete[] h2o.geom[i];
	}
	delete[] h2o.geom;

	return 0;
}

