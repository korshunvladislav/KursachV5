#include <iostream>
#include <fstream>
#include <string.h>
#include <cmath>

using namespace std;

float findAverage(float* Arr, int* C_Arr, int lenarr)
{
    float buf = 0;
    int C_buf = 0;

    for (int i = 0; i < lenarr; i++)
    {
        C_buf += *(C_Arr + i);
        buf += (*(Arr + i)) * (*(C_Arr + i));
    }
    return buf / C_buf;
}

bool ifNum_notBe_inArr(float* arr, int lenarr, float Num)
{
    for (int i = 0; i < lenarr; i++)
    {
        if (*(arr + i) == Num)
            return false;
    }
    return true;
}

int findIndex_inArr(float* arr, int lenarr, float num)
{
    for (int i = 0; i < lenarr; i++)
    {
        if (*(arr + i) == num)
        {
            return i;
        }
    }
    return -1;
}

float getMAX(float a, float b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

float getMIN(float a, float b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void Inp_X_and_Y_arr(float* x, float* y, int* n, FILE* fl)
{
    float buf;

    while (fscanf(fl, "%f", &buf) != EOF)
    {
        *(x + *n) = buf;
        fscanf(fl, "%f", &buf);
        *(y + *n) = buf;
        (*n)++;
    }
}

char singUpTheNode(float* mainArr, float* x, float* y, int* n)
{
    *n = *(mainArr + 1);

    for (int i = 0; i < *n; i += 2)
    {
        *(x + (i / 2)) = *(mainArr + 2 + i);
        *(y + (i / 2)) = *(mainArr + 3 + i);
    }

    if (*mainArr == 1)
    {
        return 'L';
    }
    if (*mainArr == 2)
    {
        return 'S';
    }
    if (*mainArr == 3)
    {
        return 'K';
    }
    return 'E';
}

float find_Av_a(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    float A;

    A = y1 / ((x1 - x2) * (x1 - x3) * (x1 - x4)) + y2 / ((x2 - x1) * (x2 - x3) * (x2 - x4)) + y3 / ((x3 - x2) * (x3 - x1) * (x3 - x4)) + y4 / ((x4 - x2) * (x4 - x3) * (x4 - x1));

    return A;
}

float find_Av_b(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    float B;

    B = y1 * (-x2 - x3 - x4) / ((x1 - x2) * (x1 - x3) * (x1 - x4)) + y2 * (-x1 - x3 - x4) / ((x2 - x1) * (x2 - x3) * (x2 - x4)) + y3 * (-x2 - x1 - x4) / ((x3 - x2) * (x3 - x1) * (x3 - x4)) + y4 * (-x2 - x3 - x1) / ((x4 - x2) * (x4 - x3) * (x4 - x1));

    return B;
}

float find_Av_c(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    float C;

    C = y1 * (x2 * x3 + x2 * x4 + x3 * x4) / ((x1 - x2) * (x1 - x3) * (x1 - x4)) + y2 * (x1 * x3 + x1 * x4 + x3 * x4) / ((x2 - x1) * (x2 - x3) * (x2 - x4)) + y3 * (x1 * x2 + x1 * x4 + x2 * x4) / ((x3 - x2) * (x3 - x1) * (x3 - x4)) + y4 * (x1 * x3 + x1 * x2 + x3 * x2) / ((x4 - x2) * (x4 - x3) * (x4 - x1));

    return C;
}
float find_Av_d(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    float C;

    C = y1 * (-x2 * x3 * x4) / ((x1 - x2) * (x1 - x3) * (x1 - x4)) + y2 * (-x1 * x3 * x4) / ((x2 - x1) * (x2 - x3) * (x2 - x4)) + y3 * (-x2 * x1 * x4) / ((x3 - x2) * (x3 - x1) * (x3 - x4)) + y4 * (-x2 * x3 * x1) / ((x4 - x2) * (x4 - x3) * (x4 - x1));

    return C;
}


void AddInfInAllArr(float* x, float* y, int n, float* A_arr, float* B_arr, float* C_arr, float* D_arr)
{

    for (int i = 0; i < n - 3; i++)
    {
        *(A_arr + i) = find_Av_a(*x, *y, *(x + 1), *(y + 1), *(x + 2), *(y + 2), *(x + 3), *(y + 3));
        *(B_arr + i) = find_Av_b(*x, *y, *(x + 1), *(y + 1), *(x + 2), *(y + 2), *(x + 3), *(y + 3));
        *(C_arr + i) = find_Av_c(*x, *y, *(x + 1), *(y + 1), *(x + 2), *(y + 2), *(x + 3), *(y + 3));
        *(D_arr + i) = find_Av_d(*x, *y, *(x + 1), *(y + 1), *(x + 2), *(y + 2), *(x + 3), *(y + 3));
    }


}

float return_Av_N1(float* N, float n)
{
    float AV_N = 0;

    for (int i = 0; i < n; i++)
    {
        AV_N += *(N + i);
    }
    AV_N / (n);

    return AV_N;
}

float find_K(float x, float x1, float y, float y1)
{
    if ((y - y1) / (x - x1) < 0 && (y1 - y) / (x1 - x) == 0)
    {
        return 0;
    }
    return (y1 - y) / (x1 - x);
}

float find_B(float x, float y, float k)
{
    if ((y - x * k) <= 0 && y - k * x == 0)
    {
        return 0;
    }
    return (y - x * k);
}

void AddInf_in_BarrC_Barr_and_KarrC_Karr(float* x, float* y, int n, float* Barr, int* C_Barr, float* Karr, int* C_Karr, int* C_B, int* C_K)
{
    float bufB, bufK;
    for (int i = 0; i < n - 2; i++)
    {
        bufK = find_K(x[i], x[i + 1], y[i], y[i + 1]);
        bufB = find_B(x[i], y[i], bufK);
        if (ifNum_notBe_inArr(Barr, *C_B + 1, bufB))
        {
            *(Barr + (*C_B)) = bufB;
            *(C_Barr + (*C_B)) += 1;
            (*C_B)++;
        }
        else
        {
            *(C_Barr + findIndex_inArr(Barr, *C_B, bufB)) += 1;
        }
        if (ifNum_notBe_inArr(Karr, *C_K + 1, bufK))
        {
            *(Karr + (*C_K)) = bufK;
            *(C_Karr + (*C_K)) += 1;
            (*C_K)++;
        }
        else
        {
            *(C_Karr + findIndex_inArr(Karr, *C_K, bufK)) += 1;
        }
    }
}
void clear_arr_int(int* arr, int lenarr)
{
    for (int i = 0; i < lenarr; i++)
    {
        *(arr + i) = 0;
    }
}

float Return_N_AV(int N, float* ArrX, float* ArrY, char C)
{
    int C_Barr[1000], C_Karr[1000], C_B = 0, C_K = 0;
    float Barr[1000], Karr[1000];

    clear_arr_int(C_Barr, 1000);
    clear_arr_int(C_Karr, 1000);

    AddInf_in_BarrC_Barr_and_KarrC_Karr(ArrX, ArrY, N, Barr, C_Barr, Karr, C_Karr, &C_B, &C_K);

    if (C == 'B')
        return findAverage(Barr, C_Barr, C_B);
    if (C == 'K')
        return findAverage(Karr, C_Karr, C_K);
    return 9999;
}



//void clear_arr_float(float* arr, int lenarr)
//{
//    for (int i = 0; i < lenarr; i++)
//    {
//        *(arr + i) = 0;
//    }
//}


bool ifSomethingStrange_inArr(float* Arr, int lenarr)
{
    for (int i = 0; i < lenarr - 1; i++)
    {
        for (int j = i + 1; j < lenarr; j++)
        {
            if (getMAX(fabs(*(Arr + i)), fabs(*(Arr + j))) - getMIN(fabs(*(Arr + i)), fabs(*(Arr + j))) > getMIN(fabs(*(Arr + i)), fabs(*(Arr + j))) * 2)
            {
                return true;
            }
        }
    }
    return false;
}

float AddIndx_InArrStrangeIndx_if_SomethingStrange_inArr(float* Arr, int lenarr, int* ArrStrangeIndx, int* lenarr2)
{
    for (int i = 0; i < lenarr - 1; i++)
    {
        for (int j = i + 1; j < lenarr; j++)
        {
            if (getMAX(fabs(*(Arr + i)), fabs(*(Arr + j))) - getMIN(fabs(*(Arr + i)), fabs(*(Arr + j))) > getMIN(fabs(*(Arr + i)), fabs(*(Arr + j))) * 2)
            {
                if (getMAX(fabs(*(Arr + i)), fabs(*(Arr + j))) != getMAX(*(Arr + i), *(Arr + j)))
                {
                    //*(ArrStrangeIndx+ *lenarr2) =
                }
            }
        }
    }
    return 0;

}



int normalization_Arr(float* x, float* y, int n)
{
    int i = 0, j = 0;
    while (i < n - 1)
    {
        if ((*(x + i) - *(x + i + 1)) > *(x + i) * 0.1 || (*(y + i) - *(y + i + 1)) > *(y + i) * 0.1)
        {
            j = i;
            while (j < n - 1)
            {
                *(x + j) = *(x + j + 1);
                *(y + j) = *(y + j + 1);
                j++;
            }
            n -= 1;
        }
        else
            i++;
    }
    return n;
}

float find_Av_b1(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float B;

    B = y1 * (-x2 - x3) / ((x1 - x2) * (x1 - x3)) + y2 * (-x1 - x3) / ((x2 - x1) * (x2 - x3)) + y3 * (-x1 - x2) / ((x3 - x1) * (x3 - x2));

    return B;
}
float find_Av_a1(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float A;

    A = y1 / ((x1 - x2) * (x1 - x3)) + y2 / ((x2 - x1) * (x2 - x3)) + y3 / ((x3 - x1) * (x3 - x2));

    return A;
}

float find_Av_c1(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float C;

    C = y1 * x3 * x2 / ((x1 - x2) * (x1 - x3)) + y2 * x1 * x3 / ((x2 - x1) * (x2 - x3)) + y3 * x1 * x2 / ((x3 - x1) * (x3 - x2));

    return C;
}

void AddInfInAllArr(float* x, float* y, int n, float* A_arr, float* B_arr, float* C_arr)
{

    for (int i = 0; i < n - 2; i++)
    {
        *(A_arr + i) = find_Av_a1(*x, *y, *(x + 1), *(y + 1), *(x + 2), *(y + 2));
        *(B_arr + i) = find_Av_b1(*x, *y, *(x + 1), *(y + 1), *(x + 2), *(y + 2));
        *(C_arr + i) = find_Av_c1(*x, *y, *(x + 1), *(y + 1), *(x + 2), *(y + 2));
    }
}


float return_Av_N(float* N, float n)
{
    float AV_N = 0;

    for (int i = 0; i < n; i++)
    {
        AV_N += *(N + i);
    }
    AV_N / (n);

    return AV_N;
}

void Write_SquareAP_Output_Dots(FILE* fl, float a, float b, float c)
{
    /*float x = -10;
    float y = a * x * x + b * b + c;
    fprintf_s(fl, "%f ", x);
    fprintf_s(fl, "%f\n", y);

    for (int i = -99; i < 100; i++)
    {
        x = x + 0.1;
        y = a * x * x + b * b + c;
        fprintf_s(fl, "%f ", x);
        fprintf_s(fl, "%f\n", y);
    }*/
    fprintf(fl, "%f ", a);
    fprintf(fl, "%f ", b);
    fprintf(fl, "%f ", c);
}

void Write_LineAP_Output_Dots(FILE* fl, float k, float b)
{
    /*float x = -10;
    float y = k * x + b;
    fprintf_s(fl, "%f ", x);
    fprintf_s(fl, "%f\n", y);

    for (int i = -99; i < 100; i++)
    {
        x = x + 0.1;
        y = k * x + b;
        fprintf_s(fl, "%f ", x);
        fprintf_s(fl, "%f\n", y);
    }*/
    fprintf(fl, "%f ", k);
    fprintf(fl, "%f ", b);
}

void Write_KubAP_Output_Dots(FILE* fl, float a, float b, float c, float d)
{
    /*float x = -10;
    float y = a * x * x * x + b * x * x + c * x + d;
    fprintf_s(fl, "%f ", x);
    fprintf_s(fl, "%f\n", y);

    for (int i = -99; i < 100; i++)
    {
        x = x + 0.1;
        y = a * x * x * x + b * x * x + c * x + d;
        fprintf_s(fl, "%f ", x);
        fprintf_s(fl, "%f\n", y);
    }*/
    fprintf(fl, "%f ", a);
    fprintf(fl, "%f ", b);
    fprintf(fl, "%f ", c);
    fprintf(fl, "%f ", d);
}

float* writeOutArr(float a, float b)
{
    float arr[2] = { a, b };

    return arr;
}
float* writeOutArr(float a, float b, float c)
{
    float arr[3] = { a, b, c };

    return arr;
}
float* writeOutArr(float a, float b, float c, float d)
{
    float arr[4] = { a, b, c, d };

    return arr;
}

void strongNormalization(float* x, float* y, int* n, int FLAP){
    if (FLAP == 2)    {
        float A[3], B[3];
        A[0] = x[0];        B[0] = y[0];
        A[2] = x[(*n) - 1];        B[2] = y[(*n) - 1];
        float buf = y[0];
        int ibuf = 0;        for (int i = 0; i < *n; i++)
        {            if (buf > y[i])
            {                buf = y[i];
                ibuf = i;            }
        }        A[1] = x[ibuf];
        B[1] = y[ibuf];
        x[0] = A[0];        y[0] = B[0];
        x[1] = A[1];        y[1] = B[1];
        x[2] = A[2];        y[2] = B[2];
        *(n) = 3;    }
    else if (FLAP == 3)    {
        float A[4], B[4];
        A[0] = x[0];        B[0] = y[0];
        A[3] = x[(*n) - 1];        B[3] = y[(*n) - 1];
        A[1] = x[(*n) / 3];
        B[1] = y[(*n) / 3];        A[2] = x[(*n) * 2 / 3];
        B[2] = y[(*n) * 2 / 3];
        x[0] = A[0];        y[0] = B[0];
        x[1] = A[1];        y[1] = B[1];
        x[2] = A[2];        y[2] = B[2];
        x[3] = A[3];        y[3] = B[3];
        *(n) = 4;    }
}

int main()
{
    float X[1000], Y[1000];
    int n = 0;

    float mainArr[1000];

    //ofstream fl1("Dots.txt", ios::beg);

    FILE* fl = fopen("input.txt", "r");

    int FLAP;
    fscanf(fl, "%d", &FLAP);

    Inp_X_and_Y_arr(X, Y, &n, fl);

    strongNormalization(X, Y, &n, FLAP);

    FILE* fl2 = fopen("output.txt", "w");

    



    if (FLAP == 2)
    {
        float A[1000], B[1000], C[1000];
        AddInfInAllArr(X, Y, n, A, B, C);
        // writeOutArr(return_Av_N(A, n - 2), return_Av_N(B, n - 2), return_Av_N(C, n - 2));
        //cout << A[0];
        Write_SquareAP_Output_Dots(fl2, return_Av_N(A, n - 2), return_Av_N(B, n - 2), return_Av_N(C, n - 2));
    }
    if (FLAP == 1)
    {
        writeOutArr(Return_N_AV(n, X, Y, 'K'), Return_N_AV(n, X, Y, 'B'));
        // cout << "y = " << Return_N_AV(n, X, Y, 'K') << "x + " << Return_N_AV(n, X, Y, 'B') << endl;
        Write_LineAP_Output_Dots(fl2, Return_N_AV(n, X, Y, 'K'), Return_N_AV(n, X, Y, 'B'));
    }
    if (FLAP == 3)
    {
        float A[1000], B[1000], C[1000], D[1000];
        AddInfInAllArr(X, Y, n, A, B, C, D);
        // writeOutArr(return_Av_N1(A, n - 3), return_Av_N1(B, n - 3), return_Av_N1(C, n - 3), return_Av_N1(D, n-3));
        Write_KubAP_Output_Dots(fl2, return_Av_N1(A, n - 3), return_Av_N1(B, n - 3), return_Av_N1(C, n - 3), return_Av_N1(D, n - 3));
    }

    fclose(fl2);
    fclose(fl);

    return 0;
}
