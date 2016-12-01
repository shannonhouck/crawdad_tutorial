#include "molecule.h"

using namespace std;

int main(int argc, char* argv[])
{
	// create new Molecule
	Molecule h2o("input.txt", 0);

	h2o.pointGroup ="c2v";

	// print geometry
	h2o.printGeom();

	// test translation
	h2o.translate(5.0, 0.0, 3.0);

	// print geometry
	h2o.printGeom();

	return 0;
}

