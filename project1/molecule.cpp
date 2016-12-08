#include "molecule.h"
#include <cstdio>
#include <cassert>
#include <fstream>
#include <iostream>
#include <cmath>

/********************************************************
 printGeom()
  Prints Cartesian coordinates of the molecule.
 Params:
  none
 Returns:
  Returns void
  Prints coordinates of Molecule object
 ********************************************************/
void Molecule::printGeom()
{
	// for each atom, print the z-value and coordinates
	for(int i=0; i<natoms; i++)
	{
		printf("%d %8.5f %8.5f %8.5f\n",
		 zvals[i], geom[i][0], geom[i][1], geom[i][2]);
	}
}

/********************************************************
 printBonds()
  Prints Cartesian coordinates of the molecule.
 Params:
  none
 Returns:
  Returns void
  Prints bond lengths of Molecule object
 ********************************************************/
void Molecule::printBonds()
{
        // for each atom, print the z-value and coordinates
        for(int i=0; i<natoms; i++)
        {
		for(int j=0; j<i; j++)
		{
                	printf("%d %d %8.5f\n", i, j, bondLengths[i][j]);
		}
        }
}


/********************************************************
 rotate(double phi)
  Rotates molecule about z-axis.
 Params:
  double phi - roation amount (in degrees)
 Returns:
  Returns void
  Changes coordinates of Molecule object
 ********************************************************/
void Molecule::rotate(double phi)
{
	// fill out later
}

/********************************************************
 translate(double x, double y, double z)
  Translates molecule by a given amount.
 Params:
  double x - amount to translate along x-axis (A)
  double y - amount to translate along y-axis (A)
  double z - amount to translate along z-axis (A)
 Returns:
  Returns void
  Changes coordinates of Molecule object
 ********************************************************/
void Molecule::translate(double x, double y, double z)
{
	for(int i=0; i<natoms; i++)
	{
		geom[i][0] += x;
		geom[i][1] += y;
		geom[i][2] += z;
	}
}

/********************************************************
 bond(int a1, int a2)
  Returns the bond length between two atoms.
 Params:
  int a1 - atom #1
  int a2 - atom #2
 Returns:
  Returns a double representing the bond length (in A)
 ********************************************************/
double Molecule::bond(int a1, int a2)
{
	double xDist = geom[a1][0] - geom[a2][0];
	double yDist = geom[a1][1] - geom[a2][1];
	double zDist = geom[a1][2] - geom[a2][2];
	return sqrt(pow(xDist, 2.0) + pow(yDist, 2.0) + pow(zDist, 2.0));
}


/********************************************************
 angle(int a1, int a2, int a3)
  Returns the bond angle between three atoms.
 Params:
  int a1 - atom #1
  int a2 - atom #2
  int a3 - atom #3
 Returns:
  Returns a double representing the bond angle (degrees)
 ********************************************************/
double Molecule::angle(int a1, int a2, int a3)
{
	// fill in later
	printf("The bond angle function doesn't work yet!\n");
	return 0.0;
}


/********************************************************
 bond(int a1, int a2, int a3, int a4)
  Returns the torsion angle between four atoms.
 Params:
  int a1 - atom #1
  int a2 - atom #2
  int a3 - atom #3
  int a4 - atom #4
 Returns:
  Returns a double representing the bond torsion (degrees)
 ********************************************************/
double Molecule::torsion(int a1, int a2, int a3, int a4)
{
	// fill in later
	printf("The torsion function doesn't work yet!\n");
	return 0.0;
}


/********************************************************
 Molecule();
  Default constructor. Constructs an object of type Molecule.
 Params:
  None
 Returns:
  N/A
  Creates a new object of type Molecule
 ********************************************************/
Molecule::Molecule(){}

/********************************************************
 Molecule(string filename, int q);
  Default constructor. Constructs an object of type Molecule.
 Params:
  string filename - name of file
  int q - charge
 Returns:
  N/A
  Creates a new object of type Molecule
 ********************************************************/
Molecule::Molecule(string filename, int q)
{
	// open file
	ifstream ifstream(filename);
	assert(ifstream.good());

	// setting variables
	charge = q;
	ifstream >> natoms;

	// allocating memory for matrices
        zvals = new int[natoms];
        geom = new double*[natoms];
	bondLengths = new double*[natoms];
        for(int i=0; i<natoms; i++)
        {
                geom[i] = new double[3];
		bondLengths[i] = new double[natoms];
        }

	// setting values in zval and geom matrices
	for(int i=0; i<natoms; i++)
	{
		ifstream >> zvals[i] >> geom[i][0] >> geom[i][1] >> geom[i][2];
	}

	// setting values in other matrices
	for(int i=0; i<natoms; i++)
	{
		for(int j=0; j<natoms; j++)
		{
			bondLengths[i][j] = bond(i, j);
		}
	}

}

/********************************************************
 translate(double x, double y, double z)
  Deconstructor. Deconstructs an object of type Molecule.
 Params:
  None
 Returns:
  N/A
  Deconstructs a Molecule object
 ********************************************************/
Molecule::~Molecule()
{
        // delete matrices
        delete[] zvals;
        for(int i=0; i<natoms; i++)
        {
                delete[] geom[i];
		delete[] bondLengths[i];
        }
        delete[] geom;
	delete[] bondLengths;
}


