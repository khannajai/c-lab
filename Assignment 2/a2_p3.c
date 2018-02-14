/*
a2_p3.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>


void set_elements(int **matrix, int row, int col);
int** mallocate(int n);
void print_mat(int **matrix, int n);
int compare(int **m1, int **m2, int n);

int main()
{
    int n=0, i=0;
    int **matrix1, **matrix2;

    scanf("%d",&n);

    //allocating memory and reading elements
    matrix1=mallocate(n);
    set_elements(matrix1,n,n);
    matrix2=mallocate(n);
    set_elements(matrix2, n, n);
    
    printf("Matrix A:\n");
    print_mat(matrix1, n);
    printf("Matrix B:\n");
    print_mat(matrix2, n);

    printf("The comparison result: ");
    if(compare(matrix1,matrix2,n)==1)
    {
        printf("identical\n");
    }
    else
    {
        printf("NOT identical\n");
    }

    for ( i = 0; i < n ; i ++)
    {
        free (matrix1[i]);
    }
    free(matrix1);
    i=0;
    for ( i = 0; i < n ; i ++)
    {
        free (matrix2[i]);
    }
    free(matrix2);

    return 0;


}


//reads from standard input the elements of a matrix with size row,col
void set_elements(int **matrix, int row, int col)
{
    int r=0,c=0;
    for(r=0;r<row;r++)
    {
        for(c=0;c<col;c++)
        {
            scanf("%d",&matrix[r][c]);
        }
    }
}

//allocates memory for an n*n integer matrix and returns a pointer
int** mallocate(int n)
{
    int i=0;
    int** matrix;
    matrix=(int**)malloc(sizeof(int*)*n);
    if (matrix==NULL)
    {
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        matrix[i]=(int*)malloc(sizeof(int)*n);
        if (matrix[i]==NULL)
        {
            exit(1);
        }
    }
    return matrix;
}

//compares the diagonal elements of two matrices m1 and m2 of size n*n and returns whether they are identical or not
int compare(int **m1, int **m2, int n)
{
    int i=0,identical=1;
    for(i=0;i<n;i++)
    {
        if(m1[i][i]!=m2[i][i])
        {
            identical=0;
            break;
        }
    }
    return identical;
}

//prints a matrix of size n*n in a row by row format
void print_mat(int **matrix, int n)
{
    int i=0, j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}