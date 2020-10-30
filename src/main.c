#include <stdio.h>
#include <math.h>


float distance(float *p1, float *p2)
{
    return sqrt(pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2));
}


float norm(float *mat)
{
    return mat[0] * mat[3] - mat[1] * mat[2];
}



void inverse (float *mat, float *inv, float norm)
{
    inv[0] = mat[3]/norm;
    inv[1] = -mat[1]/norm;
    inv[2] = -mat[2]/norm;
    inv[3] = mat[0]/norm;
}


void matmultiplication (float *mat1, float *mat2, float *result)
{
    result[0] = mat1[0] * mat2[0] + mat1[1] * mat2[1];
    result[1] = mat1[2] * mat2[0] + mat1[3] * mat2[1];
}

int main()
{
    float d = 0.00001;
    float ds, dprev, dsprev;

    float A[4] = {1.0, 1.0, 1.0, 1.00001};
    float b[2] = {2.0, 2.00001 + d};

    float invA[4];
    inverse(A, invA, norm(A));

    float result1[2] = {1.0, 1.0}; // Координата  b = {2.0, 2.00001}

    float result2[2]; // Координата  b = {2.0, 2.00001 + d}
    matmultiplication(invA, b, result2);

    ds = distance(result1, result2);

    while (ds > 0.000001)
    {
        dprev = d;
        dsprev = ds;

        d /= 2;
        b[1] = 2.00001 + d;

        matmultiplication(invA, b, result2);

        ds = distance(result1, result2);
    }

    printf("last D =\t%.20f\nDistance =\t\t%.7f\n\nstopping D =\t%.20f\nDistance =\t\t%.7f\n", dprev, dsprev, d, ds);

    return 0;
    

}

