#include <iostream>

#include "gtest/gtest.h"

extern "C" {
  // Fieldlib is a C library and requires C linkage
  #include "blas.h"
  #include "fields.h"
  #include "real.h"
}


TEST(Aufgabe_4, Teil_a)
{
    REAL** A = createMatrix(10,10);

    REAL* x = createVector(10);
    REAL* y = createVector(10);

    fill1Dfield(1.0,x,10);
    fill1Dfield(0.0,y,10);

    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
            A[i][j]=(REAL)((i+1)*(j+1));

    printf("A:\n");
    printMatrix(A, 10, 10);

    gemv(1.0, A, x, 1.0, y, 10, 10);


    printf("\nnrm2(A*x): %f\n\n", nrm2(y,10));

    EXPECT_TRUE(isEqualScalar(nrm2(y,10),1079.177928,1e-06));

    axpy(5.0,x,y,10);

    scal(1.5,x,10);

    printf("(5*x + A*x) * (1.5*x): %f\n", dot(x,y,10));

    EXPECT_TRUE(isEqualScalar(dot(x,y,10),4612.500000,1e-06));

    destroyMatrix(A,10);
    destroyVector(x);
    destroyVector(y);
}

TEST(Aufgabe_4, Teil_b){
    REAL** field = create2Dfield(60,40);

    for (int i=0;i<60;i++)
    {
        for (int j=0;j<40;j++)
        {
            field[i][j]=M_PI * 1.0/60.0 * (REAL)i;
        }
    }

    writeVTKfileFor2DscalarField("gradientField.vtk", "gradientfield", field, 60, 40, 0.1, 0.1);

    applyFunctionTo2Dfield(sin, field, 60, 40);

    writeVTKfileFor2DscalarField("sinusField.vtk", "sinusfield", field, 60, 40, 0.1, 0.1);

    destroy2Dfield(field, 60);

}

TEST(Aufgabe_4,Teil_c){
    int sizeX, sizeY;

    REAL** fieldU = read2Dfield("fieldU.dat", &sizeX, &sizeY);
    REAL** fieldV = read2Dfield("fieldV.dat", &sizeX, &sizeY);

    EXPECT_EQ(sizeX,60);
    EXPECT_EQ(sizeY,60);

    writeVTKfileFor2DvectorField("vectorField.vtk", "vectorfield", fieldU, fieldV, sizeX, sizeY, 0.1, 0.1);

    destroy2Dfield(fieldU, sizeX);
    destroy2Dfield(fieldV, sizeX);
}

