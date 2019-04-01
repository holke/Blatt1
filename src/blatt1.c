#include <stdlib.h>
#include <stdio.h>

#include "fields.h"
#include "blas.h"
#include "real.h"

#include <math.h>

int main(int argc, char* argv[])
{
	/*------------------------------------------------------------------------*/


	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------*/
//	REAL** field = create2Dfield(60,40);

//	for (int i=0;i<60;i++)
//	{
//		for (int j=0;j<40;j++)
//		{
//			field[i][j]=M_PI * 1.0/60.0 * (REAL)i;
//		}
//	}

//	writeVTKfileFor2DscalarField("gradientField.vtk", "gradientfield", field, 60, 40, 0.1, 0.1);

//	applyFunctionTo2Dfield(sin, field, 60, 40);

//	writeVTKfileFor2DscalarField("sinusField.vtk", "sinusfield", field, 60, 40, 0.1, 0.1);

//	destroy2Dfield(field, 60);
//	/*------------------------------------------------------------------------*/


//	/*------------------------------------------------------------------------*/
//	int sizeX, sizeY;

//	REAL** fieldU = read2Dfield("fieldU.dat", &sizeX, &sizeY);
//	REAL** fieldV = read2Dfield("fieldV.dat", &sizeX, &sizeY);

//	writeVTKfileFor2DvectorField("vectorField.vtk", "vectorfield", fieldU, fieldV, sizeX, sizeY, 0.1, 0.1);

//	destroy2Dfield(fieldU, sizeX);
//	destroy2Dfield(fieldV, sizeX);
//	/*------------------------------------------------------------------------*/

	return 0;
}
