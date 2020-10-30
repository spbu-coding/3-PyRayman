#include <stdio.h>
#include <math.h>

// Func for float

float distance_f(float *p1, float *p2)
{
    return sqrt(pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2));
}


float norm_f(float *mat)
{
    return mat[0] * mat[3] - mat[1] * mat[2];
}



void inverse_f (float *mat, float *inv, float norm)
{
    inv[0] = mat[3]/norm;
    inv[1] = -mat[1]/norm;
    inv[2] = -mat[2]/norm;
    inv[3] = mat[0]/norm;
}


void matmultiplication_f (float *mat1, float *mat2, float *result)
{
    result[0] = mat1[0] * mat2[0] + mat1[1] * mat2[1];
    result[1] = mat1[2] * mat2[0] + mat1[3] * mat2[1];
}


// Func for double

double distance_d(double *p1, double *p2)
{
    return sqrt(pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2));
}


double norm_d(double *mat)
{
    return mat[0] * mat[3] - mat[1] * mat[2];
}

void inverse_d (double *mat, double *inv, double norm)
{
    inv[0] = mat[3]/norm;
    inv[1] = -mat[1]/norm;
    inv[2] = -mat[2]/norm;
    inv[3] = mat[0]/norm;
}

void matmultiplication_d (double *mat1, double *mat2, double *result)
{
    result[0] = mat1[0] * mat2[0] + mat1[1] * mat2[1];
    result[1] = mat1[2] * mat2[0] + mat1[3] * mat2[1];
}

int main()
{
    // variable for float
    float d_f = 0.00001;
    float ds_f, dprev_f, dsprev_f;

    float A_f[4] = {1.0, 1.0, 1.0, 1.00001};
    float b_f[2] = {2.0, 2.00001 + d_f};

    float invA_f[4];
    inverse_f(A_f, invA_f, norm_f(A_f   ));

    float result1_f[2] = {1.0, 1.0}; // Координата  b = {2.0, 2.00001}

    float result2_f[2]; // Координата  b = {2.0, 2.00001 + d}
    matmultiplication_f(invA_f, b_f, result2_f);

    ds_f = distance_f(result1_f, result2_f);

    // variable for double
    double d_db = 0.00001;
    double ds_db, dprev_db, dsprev_db;

    double A_db[4] = {1.0, 1.0, 1.0, 1.00001};
    double b_db[2] = {2.0, 2.00001 + d_db};

    double invA_db[4];
    inverse_d(A_db, invA_db, norm_d(A_db));

    double result1_db[2] = {1.0, 1.0}; // Координата  b = {2.0, 2.00001}

    double result2_db[2]; // Координата  b = {2.0, 2.00001 + d}
    matmultiplication_d(invA_db, b_db, result2_db);

    ds_db = distance_d(result1_db, result2_db);


    while (ds_db > 0.000001)
    {
        dprev_db = d_db;
        dsprev_db = ds_db;

        d_db /= 2;
        b_db[1] = 2.00001 + d_db;

        matmultiplication_d(invA_db, b_db, result2_db);

        ds_db = distance_d(result1_db, result2_db);
    }

    while (ds_f > 0.000001)
    {
        dprev_f = d_f;
        dsprev_f = ds_f;

        d_f /= 2;
        b_f[1] = 2.00001 + d_f;

        matmultiplication_f(invA_f, b_f, result2_f);

        ds_f = distance_f(result1_f, result2_f);
    }
    printf("Result for Double: \n");
    printf("last D =\t%.20f\nDistance =\t\t%.7f\n\nstopping D =\t%.20f\nDistance =\t\t%.7f\n", dprev_db, dsprev_db, d_db, ds_db);

    printf("Result for Float: \n");
    printf("last D =\t%.20f\nDistance =\t\t%.7f\n\nstopping D =\t%.20f\nDistance =\t\t%.7f\n", dprev_f, dsprev_f, d_f, ds_f);

    return 0;
    

}

