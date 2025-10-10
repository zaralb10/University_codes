#include <stdio.h>

void sumar_areas(int n, int m, int A[n][m], int res[]); 

int main() {
    int A[3][3] = {
        {4, 6, 5},
        {3, 1, 2},
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
    int suma, k = 0;

    for (int i = 0; i < n; i++)
    {
        suma = 0;
        for (int j = 0; j < i; j++)
        {
            suma += A[i][j] + A[j][i]; 
        }
        suma += A[i][i];               
        res[k++] = suma;              
    }
}

