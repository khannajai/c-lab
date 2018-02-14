/*
a1_p4.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#define INTERMEDIATE

void set_elements(int **matrix, int row, int col);
int** mallocate(int n);
void matrix_mul(int **matrix1, int **matrix2, int **finalmat, int n);
void print_mat(int **matrix, int n);

int main()
{
    int n=0;
    int **matrix1, **matrix2, **finalmat;

    scanf("%d",&n);

    //allocating memory and reading elements
    matrix1=mallocate(n);
    set_elements(matrix1,n,n);
    matrix2=mallocate(n);
    set_elements(matrix2, n, n);
    finalmat=mallocate(n);

    #ifdef INTERMEDIATE
    printf("The intermediate product values are:\n");
    #endif
    matrix_mul(matrix1, matrix2, finalmat, n);
    
    printf("The product of the matrices is:\n");
    print_mat(finalmat, n);
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

//multiplies two matrices of size n*n and places the result into finalmat
void matrix_mul(int **matrix1, int **matrix2, int **finalmat, int n)
{
    int i=0, j=0, k=0, sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum=0;
            for(k=0;k<n;k++)
            {
                #ifdef INTERMEDIATE
                printf("%d\n",matrix1[i][k]*matrix2[k][j]);
                #endif
                sum=sum+matrix1[i][k]*matrix2[k][j];
                finalmat[i][j]=sum;
            }
        }
    }
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