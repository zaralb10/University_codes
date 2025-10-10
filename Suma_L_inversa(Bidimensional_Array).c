#include <stdio.h>

int main() {
    int A[3][3] = {
        {4, 6, 5},
        {3, 2, 2},
        {5, 4, 4}
    };
    int res[3];
    sumar_areas(3, 3, A, res);

    for (int i = 0; i < 3; i++)
    {
        printf("res[%d] = %d\n", i, res[i]);
    }

    return 0;
}


void sumar_areas(int n, int m, int A[n][m], int res[]) 
{
    int K;
    if (n < m)
    {
        K = n;
    } else 
    {
        K = m;
    }

    for (int k = 0; k < K; k++) 
    {
        int suma = 0;

        // tramo horizontal
        for (int j = 0; j <= k; j++)
        {
            suma += A[k][j];
        }

        //  tramo superior
        for (int r = 0; r < k; r++) 
        {
            int c = (m - 1) - r;
            if (c >= 0 && c < m)
            {
                suma += A[r][c];
            }
        }

        res[k] = suma;
    }
}
