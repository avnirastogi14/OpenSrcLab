#include <stdio.h>

int main()
{
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[100][100], transpose[100][100];

    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; ++i) for (int j = 0; j < cols; ++j) transpose[j][i] = matrix[i][j];

    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j) printf("%d\t", matrix[i][j]);
        printf("\n");
    }

    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j) printf("%d\t", transpose[i][j]);
        printf("\n");
    }

    return 0;
}
