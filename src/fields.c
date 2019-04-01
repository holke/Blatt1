#include "fields.h"

REAL* create1Dfield(int size)
{
	REAL* field;

	field = (REAL*) malloc(size * sizeof(REAL));

	return field;
}

REAL** create2Dfield(int sizeX, int sizeY)
{
	REAL** field;

	field = (REAL**) malloc(sizeX * sizeof(REAL*));

	for (int i=0;i<sizeX;i++)
	{
		field[i] = (REAL*) malloc(sizeY * sizeof(REAL));
	}
	return field;
}

REAL* createVector(int len)
{
	return create1Dfield(len);
}

REAL** createMatrix(int rows, int cols)
{
	return create2Dfield(rows, cols);
}

void destroy1Dfield(REAL* field)
{
	free(field);
}

void destroy2Dfield(REAL** field, int sizeX)
{
	for (int i=0;i<sizeX;i++)
	{
		free(field[i]);
	}

	free(field);
}

void destroyVector(REAL* vector)
{
	destroy1Dfield(vector);
}

void destroyMatrix(REAL** matrix, int rows)
{
	destroy2Dfield(matrix, rows);
}

void fill1Dfield(REAL value, REAL* field, int size)
{
	for (int i=0;i<size;i++)
	{
		field[i]=value;
	}
}

void fill2Dfield(REAL value, REAL** field, int sizeX, int sizeY)
{
	for (int i=0;i<sizeX;i++)
		for (int j=0;j<sizeY;j++)
		{
			field[i][j]=value;
		}
}

int isEqualScalar(REAL x, REAL y, REAL eps)
{
    if (fabs(x-y)<eps)
        return 1;
    else
        return 0;
}

int isEqual1Dfield(REAL* field1, REAL* field2, int size, REAL eps)
{
	for (int i=0;i<size;i++)
	{
        if (fabs(field1[i]-field2[i])>eps)
		{
            return 0;
		}
	}

    return 1;
}

int isEqual2Dfield(REAL** field1, REAL** field2, int sizeX, int sizeY, REAL eps)
{
	for (int i=0;i<sizeX;i++)
	{
		for (int j=0;j<sizeY;j++)
		{
            if (fabs(field1[i][j]-field2[i][j])>eps)
			{
                return 0;
			}
		}
	}

    return 1;
}

void	applyFunctionTo1Dfield(REAL (*func)(REAL), REAL* field, int size)
{
	for (int i=0;i<size;i++)
	{
		field[i]=func(field[i]);
	}
}

void	applyFunctionTo2Dfield(REAL (*func)(REAL), REAL** field, int sizeX, int sizeY)
{
	for (int i=0;i<sizeX;i++)
	{
		for (int j=0;j<sizeY;j++)
		{
			field[i][j]=func(field[i][j]);
		}
	}
}

void	print1Dfield(REAL* field, int size)
{
	for (int i=0;i<size;i++)
		printf("%f\n", field[i]);
}

void	print2Dfield(REAL** field, int sizeX, int sizeY)
{
	for (int j=0;j<sizeY;j++)
	{
		for (int i=0;i<sizeX;i++)
			printf("%f\t",field[i][j]);
		printf("\n");
	}
}

void	printVector(REAL* vector, int len)
{
	print1Dfield(vector,len);
}

void	printMatrix(REAL** matrix, int rows, int cols)
{
	for (int i=0;i<rows;i++)
	{
		for (int j=0;j<cols;j++)
			printf("%f\t",matrix[i][j]);
		printf("\n");
	}
}

void write1Dfield(const char* fileName, REAL* field, int size)
{
	FILE* outFile=fopen(fileName, "wb");

	fwrite(&size, sizeof(int), 1, outFile);

	fwrite(field, sizeof(REAL), size, outFile);

	fclose(outFile);
}

void write2Dfield(const char* fileName, REAL** field, int sizeX, int sizeY)
{
	FILE* outFile=fopen(fileName, "wb");

	fwrite(&sizeX, sizeof(int), 1, outFile);
	fwrite(&sizeY, sizeof(int), 1, outFile);

	for (int i=0;i<sizeX;i++)
	{
		fwrite(field[i], sizeof(REAL), sizeY, outFile);
	}

	fclose(outFile);
}

REAL* read1Dfield(const char* fileName, int* size)
{
	FILE* inFile=fopen(fileName, "rb");

	fread(size, sizeof(int), 1, inFile);

	REAL* field = create1Dfield(*size);

	fread(field, sizeof(REAL), *size, inFile);

	fclose(inFile);

	return field;
}

REAL** read2Dfield(const char* fileName, int* sizeX, int* sizeY)
{
    FILE* inFile=fopen(fileName, "r");
    if (inFile == NULL) {
        perror("Failed: read2Dfield: Cannot open file for reading.");
    }

	fread(sizeX, sizeof(int), 1, inFile);
	fread(sizeY, sizeof(int), 1, inFile);

	REAL** field = create2Dfield(*sizeX, *sizeY);

	for (int i=0;i<*sizeX;i++)
	{
		fread(field[i], sizeof(REAL), *sizeY, inFile);
	}

	fclose(inFile);

	return field;
}

void writeVTKfileFor2DscalarField(const char* fileName, const char* description, REAL** field, int sizeX, int sizeY, REAL dx, REAL dy)
{
	FILE* vtkFile = fopen(fileName, "w");

	fprintf(vtkFile, "# vtk DataFile Version 3.0\n");
	fprintf(vtkFile, "Scalar Field\n");
	fprintf(vtkFile, "ASCII\n");

	fprintf(vtkFile, "DATASET RECTILINEAR_GRID \n");
	fprintf(vtkFile, "DIMENSIONS %d %d 1 \n", sizeX, sizeY);
	fprintf(vtkFile, "X_COORDINATES %d double\n", sizeX);
	for (int i=0;i<sizeX;i++)
		fprintf(vtkFile, "%lf ", dx*(double)i);
	fprintf(vtkFile, "\n");
	fprintf(vtkFile, "Y_COORDINATES %d double\n", sizeY);
	for (int j=0;j<sizeY;j++)
		fprintf(vtkFile, "%lf ", dy*(double)j);
	fprintf(vtkFile, "\n");
	fprintf(vtkFile, "Z_COORDINATES 1 double\n");
	fprintf(vtkFile, "0.0\n");

	fprintf(vtkFile, "POINT_DATA %d\n", 1 * sizeX * sizeY);
	fprintf(vtkFile, "SCALARS %s double 1\n", description);
	fprintf(vtkFile, "LOOKUP_TABLE default \n");
	for(int j=0;j<sizeY;j++)
	{
		for(int i=0;i<sizeX;i++)
		{
			fprintf(vtkFile, "%e\n", field[i][j]);
		}
	}
	fprintf(vtkFile,"\n");

	fclose(vtkFile);
}

void writeVTKfileFor2DvectorField(const char* fileName, const char* description, REAL** fieldU, REAL** fieldV, int sizeX, int sizeY, REAL dx, REAL dy)
{
	FILE* vtkFile = fopen(fileName, "w");

	fprintf(vtkFile, "# vtk DataFile Version 3.0\n");
	fprintf(vtkFile, "Vector Field\n");
	fprintf(vtkFile, "ASCII\n");

	fprintf(vtkFile, "DATASET RECTILINEAR_GRID \n");
	fprintf(vtkFile, "DIMENSIONS %d %d 1 \n", sizeX, sizeY);
	fprintf(vtkFile, "X_COORDINATES %d double\n", sizeX);
	for (int i=0;i<sizeX;i++)
		fprintf(vtkFile, "%lf ", dx*(double)i);
	fprintf(vtkFile, "\n");
	fprintf(vtkFile, "Y_COORDINATES %d double\n", sizeY);
	for (int j=0;j<sizeY;j++)
		fprintf(vtkFile, "%lf ", dy*(double)j);
	fprintf(vtkFile, "\n");
	fprintf(vtkFile, "Z_COORDINATES 1 double\n");
	fprintf(vtkFile, "0.0\n");


	fprintf(vtkFile, "POINT_DATA %d\n", 1 * sizeX * sizeY);
	fprintf(vtkFile, "VECTORS %s double \n", description);
	for(int j=0;j<sizeY;j++)
	{
		for(int i=0;i<sizeX;i++)
		{
			fprintf(vtkFile, "%e %e 0.0\n", fieldU[i][j], fieldV[i][j]);
		}
	}
	fprintf(vtkFile,"\n");

	fclose(vtkFile);
}
