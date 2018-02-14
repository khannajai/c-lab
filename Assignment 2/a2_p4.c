/*
JTSK-320112
a2_p4.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void set_elements(int ***matrix, int row, int col, int depth);
int*** mallocate(int x, int y, int z);
void print_mat(int ***matrix, int x, int y, int z);
void freemem(int ***matrix, int x, int y, int z);

int main()
{
    int x,y,z;
    int ***matrix;

    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);


    //allocating memory and reading elements
    matrix=mallocate(x,y,z);
    set_elements(matrix,x,y,z);

    print_mat(matrix,x,y,z);

    freemem(matrix,x,y,z);


}


//reads from standard input the elements of a 3d matrix with size row,col,depth
void set_elements(int ***matrix, int row, int col, int depth)
{
    int r=0,c=0,d=0;
    for(r=0;r<row;r++)
    {
        for(c=0;c<col;c++)
        {
            for(d=0;d<depth;d++)
            {
                scanf("%d",&matrix[r][c][d]);
            }
        }
    }
}

//allocates memory for an x*y*z size 3d matrix and returns a pointer
int*** mallocate(int x, int y, int z)
{
    int i=0, j=0;
    int*** matrix;
    matrix=(int***)malloc(sizeof(int**)*x);
    if (matrix==NULL)
    {
        exit(1);
    }
    for(i=0;i<y;i++)
    {
        matrix[i]=(int**)malloc(sizeof(int*)*y);
        if (matrix[i]==NULL)
        {
            exit(1);
        }
        for(j=0;j<z;j++)
        {
            matrix[i][j]=(int*)malloc(sizeof(int)*z);

        }
    }
    return matrix;
}

//prints 2d sections of a 3d matrix of size x*y*z
void print_mat(int ***matrix, int x, int y, int z)
{
    int i=0,j=0,k=0;
    for(i=0;i<y;i++)
    {
        printf("Section %d:\n",i+1);
        for(j=0;j<x;j++)
        {
            for(k=0;k<z;k++)
            {
                printf("%d ",matrix[j][i][k]);
            }
            printf("\n");
        }
    }
}

//free memory allocated
void freemem(int ***matrix, int x, int y, int z)
{
    int i=0,j=0;
    for (i=0;i<y;i++)
    {
        for(j=0;j<z;j++)
        {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}