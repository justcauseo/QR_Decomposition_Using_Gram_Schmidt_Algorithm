#include <cstdlib>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

std::vector<std::vector<float>> matrix_x() 
{
    std::vector<std::vector<float>> x(3, std::vector<float>(3));

    std::cout << "Enter matrix values:" << "\n" << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "Enter (" << i << ", " << j << ") th element: ";
            std::cin >> x[i][j];
        }
    }
    std::cout << "\n";
    return x;
}


float norm(float a[3])
{
    float sq = 0;
    {
        sq = (a[0] * a[0]) + (a[1] * a[1]) + (a[2] * a[2]);
        sq = sqrt(sq);
    }
    return sq;
}


float pro;
double dot_pro(float A[3], float B[3]) {
    for (int i = 0; i < 3; i++)
    {
        pro += A[i] * B[i];
    }
    return pro;
}


float proo;
float dot_proo(float A[3], float B[3]) {
    proo = (A[0] * B[0]) + (A[1] * B[1]) + (A[2] * B[2]);
    return proo;
}


void gramSchmidt(float a[3][3])
{
    float u1[3], u2[3], u3[3];
    float v1[3], v2[3], v3[3];
    float w2[3], w3[3];
    float n2, n3;

    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 3; i++)
        {

            if (j == 0)
            {
                u1[i] = a[i][j];
            }
            else if (j == 1)
            {
                u2[i] = a[i][j];
            }
            else if (j == 2)
            {
                u3[i] = a[i][j];
            }
        }

    for (int i = 0; i < 3; i++)
    {
        v1[i] = u1[i] / norm(u1);
    }

    float r1 = dot_pro(u2, v1);
    for (int i = 0; i < 3; i++)
    {
        v2[i] = u2[i] - r1 * v1[i];
    }
    n2 = norm(v2);
    for (int i = 0; i < 3; i++)
    {
        w2[i] = v2[i] / n2;
    }

    double r2 = dot_proo(u3, v1);
    double r3 = dot_proo(u3, w2);
    for (int i = 0; i < 3; i++)
    {
        v3[i] = u3[i] - (r2 * v1[i]) - (r3 * w2[i]);
    }
    n3 = norm(v3);
    for (int i = 0; i < 3; i++)
    {
        w3[i] = v3[i] / n3;
    }  

    std::cout << "\n" << "\n" << "Q matrix is: " << "\n" << "\n";
    float matrixQ[3][3];
    for (int i = 0; i < 3; i++)
    {
        matrixQ[i][0] = v1[i];
        matrixQ[i][1] = w2[i];
        matrixQ[i][2] = w3[i];
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << matrixQ[i][j] << " ";
        }
        std::cout << endl;
    }

    std::cout << "\n" << "\n" "R matrix is: " << "\n" << "\n";
    float matrixR[3][3] = { norm(u1),r1,r2,
                           0,n2,r3,
                           0,0,n3};
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j <3; ++j)
        {
            std::cout << matrixR[i][j] << " ";
        }
        std::cout << endl;
    }

    float matrixA[3][3] = { 0,0,0, 0,0,0, 0,0,0 };
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            float sum1 = 0;
            for (int k = 0; k < 3; ++k)
            {
                sum1 = matrixQ[i][k] * matrixR[k][j];
                matrixA[i][j] = matrixA[i][j] + sum1;
            }
        }
    }
    
    std::cout << "\n" << "\n" "Q x R = A matrix is: " << "\n" << "\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrixA[i][j] << " ";
        }
        std::cout << endl;
    } 
}

int main()
{   
    float a[3][3];
    std::vector<std::vector<float>> x = matrix_x();
    std::cout << "The matrix";
    std::cout << "\n" << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            a[i][j] = x[i][j];
            std::cout << x[i][j] << " ";
        }
        std::cout << "\n";
    }
    gramSchmidt(a);
}


