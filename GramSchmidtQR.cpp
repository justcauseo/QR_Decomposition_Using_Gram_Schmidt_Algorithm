#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

/* void matrix()
{
    int row;
    int col;
    int a[50][50];
    cout << "enter num of rows = ";
    cin >> row;
    cout << "enter num of cols = ";
    cin >> col;
    cout << "\nEnter Matrix Elements: \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "\nEnter [" << i << "][" << j << "]=  ";
            cin >> a[i][j];
        }
    }

    cout << "\nThe Matrix is:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << "\n";
    }
} */

float norm(float a[3])
{
    float sq = 0;
    {
        sq = (a[0] * a[0]) + (a[1] * a[1]) + (a[2] * a[2]);
        sq = sqrt(sq);
    }
    return sq;
}

float dot_pro(float b[3], float c[3])
{
    float pro[3];
    float vecPro[3];
    float ans;
    float d = norm(c);

    for (int i = 0; i < 3; i++)
    {
        pro[i] = b[i] * c[i];
        vecPro[i] = pro[i] / (d);
        ans = vecPro[i];
        return ans;
    }
}
int i;

void gramSchmidt(float a[3][3])
{
    float u1[3], u2[3], u3[3];
    float v1[3], v2[3], v3[3];
    float w2[3], w3[3];
    float d1[3], d2[3];
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

    for (int i = 0; i < 3; i++)
    {
        v2[i] = (u2[i] - ((dot_pro(u2, v1)) * v1[i]));
        cout << " v2 " << v2[i] << "\n";
    }
    n2 = norm(v2);
    for (int i = 0; i < 3; i++)
    {
        w2[i] = v2[i] / n2;
    }


 /*   for (int i = 0; i < 3; i++)
    {
        v3[i] = u3[i] - (((dot_pro(u3, v1)) * v1[i]) - ((dot_pro(u3, v2)) * w2[i]));
        cout << " v3 " << v3[i];
    }  */
  
    for (int i = 0; i < 3; i++)
    {
        v3[i] = dot_pro(u3, v2);
        cout << " v3 " << v3[i];
    }


  /*  n3 = norm(v3);
    for (int i = 0; i < 3; i++)
    {
        w3[i] = v3[i] / n3;
        cout << " w3 " << w3[i];
    }  */
  


}

int main()
{   
    float a[3][3] = {1,2,0 
                    ,2,12,2 
                    ,0,0,0};
    float u3[3] = { 0,2,1 };
    float v2[3] = { 1.6,-0.8,0 };
    float v3[3];
    float g;
    g = norm(v2);
    cout << " v2 " << g;
    for (int i = 0; i < 3; i++)
    {
        v3[i] = u3[i]*(v2[i]/g);
        cout << " v3 " << v3[i];
    }

}


