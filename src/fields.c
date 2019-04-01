#include "fields.h"
//Remove these comments to implement the function bodies
//REAL* create1Dfield(int size)
//{

//}

//REAL** create2Dfield(int sizeX, int sizeY)
//{

//}

//REAL* createVector(int len)
//{
//	return create1Dfield(len);
//}

//REAL** createMatrix(int rows, int cols)
//{
//	return create2Dfield(rows, cols);
//}

//void destroy1Dfield(REAL* field)
//{
//}

//void destroy2Dfield(REAL** field, int sizeX)
//{

//}

//void destroyVector(REAL* vector)
//{

//}

//void destroyMatrix(REAL** matrix, int rows)
//{

//}

//void fill1Dfield(REAL value, REAL* field, int size)
//{

//}

//void fill2Dfield(REAL value, REAL** field, int sizeX, int sizeY)
//{

//}

//int isEqualScalar(REAL x, REAL y, REAL eps)
//{

//}

//int isEqual1Dfield(REAL* field1, REAL* field2, int size, REAL eps)
//{

//}

//int isEqual2Dfield(REAL** field1, REAL** field2, int sizeX, int sizeY, REAL eps)
//{

//}

//void	applyFunctionTo1Dfield(REAL (*func)(REAL), REAL* field, int size)
//{

//}

//void	applyFunctionTo2Dfield(REAL (*func)(REAL), REAL** field, int sizeX, int sizeY)
//{

//}

//void	print1Dfield(REAL* field, int size)
//{

//}

//void	print2Dfield(REAL** field, int sizeX, int sizeY)
//{

//}

//void	printVector(REAL* vector, int len)
//{
//	print1Dfield(vector,len);
//}

//void	printMatrix(REAL** matrix, int rows, int cols)
//{

//}

//void write1Dfield(const char* fileName, REAL* field, int size)
//{

//}

//void write2Dfield(const char* fileName, REAL** field, int sizeX, int sizeY)
//{

//}

//REAL* read1Dfield(const char* fileName, int* size)
//{

//}

//REAL** read2Dfield(const char* fileName, int* sizeX, int* sizeY)
//{

//}


//void writeVTKfileFor2DscalarField(const char* fileName, const char* description, REAL** field, int sizeX, int sizeY, REAL dx, REAL dy)
//{
//	FILE* vtkFile = fopen(fileName, "w");

//	fprintf(vtkFile, "# vtk DataFile Version 3.0\n");
//	fprintf(vtkFile, "Scalar Field\n");
//	fprintf(vtkFile, "ASCII\n");

//	fprintf(vtkFile, "DATASET RECTILINEAR_GRID \n");
//	fprintf(vtkFile, "DIMENSIONS %d %d 1 \n", sizeX, sizeY);
//	fprintf(vtkFile, "X_COORDINATES %d double\n", sizeX);
//	for (int i=0;i<sizeX;i++)
//		fprintf(vtkFile, "%lf ", dx*(double)i);
//	fprintf(vtkFile, "\n");
//	fprintf(vtkFile, "Y_COORDINATES %d double\n", sizeY);
//	for (int j=0;j<sizeY;j++)
//		fprintf(vtkFile, "%lf ", dy*(double)j);
//	fprintf(vtkFile, "\n");
//	fprintf(vtkFile, "Z_COORDINATES 1 double\n");
//	fprintf(vtkFile, "0.0\n");

//	fprintf(vtkFile, "POINT_DATA %d\n", 1 * sizeX * sizeY);
//	fprintf(vtkFile, "SCALARS %s double 1\n", description);
//	fprintf(vtkFile, "LOOKUP_TABLE default \n");
//	for(int j=0;j<sizeY;j++)
//	{
//		for(int i=0;i<sizeX;i++)
//		{
//			fprintf(vtkFile, "%e\n", field[i][j]);
//		}
//	}
//	fprintf(vtkFile,"\n");

//	fclose(vtkFile);
//}

//void writeVTKfileFor2DvectorField(const char* fileName, const char* description, REAL** fieldU, REAL** fieldV, int sizeX, int sizeY, REAL dx, REAL dy)
//{
//	FILE* vtkFile = fopen(fileName, "w");

//	fprintf(vtkFile, "# vtk DataFile Version 3.0\n");
//	fprintf(vtkFile, "Vector Field\n");
//	fprintf(vtkFile, "ASCII\n");

//	fprintf(vtkFile, "DATASET RECTILINEAR_GRID \n");
//	fprintf(vtkFile, "DIMENSIONS %d %d 1 \n", sizeX, sizeY);
//	fprintf(vtkFile, "X_COORDINATES %d double\n", sizeX);
//	for (int i=0;i<sizeX;i++)
//		fprintf(vtkFile, "%lf ", dx*(double)i);
//	fprintf(vtkFile, "\n");
//	fprintf(vtkFile, "Y_COORDINATES %d double\n", sizeY);
//	for (int j=0;j<sizeY;j++)
//		fprintf(vtkFile, "%lf ", dy*(double)j);
//	fprintf(vtkFile, "\n");
//	fprintf(vtkFile, "Z_COORDINATES 1 double\n");
//	fprintf(vtkFile, "0.0\n");


//	fprintf(vtkFile, "POINT_DATA %d\n", 1 * sizeX * sizeY);
//	fprintf(vtkFile, "VECTORS %s double \n", description);
//	for(int j=0;j<sizeY;j++)
//	{
//		for(int i=0;i<sizeX;i++)
//		{
//			fprintf(vtkFile, "%e %e 0.0\n", fieldU[i][j], fieldV[i][j]);
//		}
//	}
//	fprintf(vtkFile,"\n");

//	fclose(vtkFile);
//}
