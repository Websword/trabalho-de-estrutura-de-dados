#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Artur Dartagnan de Oliveira Vasconcelos; 20210026643

// Jos� Augusto da Silva Barbosa; 20210094705



void print_matrix(Matrix matrix)
{

    for (int rows = 0; rows < matrix.n_rows ; ++rows)
    {
        for (int cols = 0; cols < matrix.n_cols ; ++cols)
        {
                printf("%5d ",matrix.data[matrix.stride_cols*cols + matrix.stride_rows*rows + matrix.offset]);
        }
        printf("\n");
    }
}



Matrix create_matrix(int *data, int n_rows, int n_cols)
{


    Matrix matrix;
    matrix.data = data;
    matrix.n_rows = n_rows;
    matrix.n_cols = n_cols;
    matrix.stride_rows = n_cols;
    matrix.stride_cols = 1;
    matrix.offset = 0;




return (matrix);
}



Matrix zeros_matrix(int n_rows, int n_cols)
{


    int* arr = (int*)malloc(n_rows * n_cols * sizeof(int));

    for (int i = 0; i < n_rows*n_cols; ++i){

            arr[i] = 0;
    }

    return (create_matrix(arr, n_rows, n_cols));
}


Matrix full_matrix(int n_rows, int n_cols, int valor)
{

    int* arr = (int*)malloc(n_rows * n_cols * sizeof(int));

    for (int i = 0; i < n_rows*n_cols; ++i){

            arr[i] = valor;

    }
    return (create_matrix(arr, n_rows, n_cols));
}


Matrix i_matrix(int n)
{

    int  diagonal = n;

    int* arr = (int*)malloc(n * n *  sizeof(int));

    for (int i = 0; i < n*n; ++i)
    {

        if (diagonal == n)
        {
            arr[i] = 1;
            diagonal = 0;
        }

        else
        {
           arr[i] = 0;
           diagonal++;
        }



    }
    return (create_matrix(arr, n, n));
}

Matrix tile_matrix(Matrix matrix, int reps)
{
    //Matrix matrix;

    int i = 0;
    int tamanho = (matrix.n_rows *  reps) * ( matrix.n_cols * reps) ;
    int* arr = (int*)malloc( tamanho  * sizeof(int));



    for (int vzs = 0; vzs < reps ; ++vzs)
    {
        for (int rows = 0; rows < matrix.n_rows ; ++rows)
        {
            for (int vzs2 = 0; vzs2 < reps ; ++vzs2)
            {
                for (int cols = 0; cols < matrix.n_cols ; ++cols)
                {
                    arr[i] = matrix.data[(cols*matrix.stride_cols) +(rows*matrix.stride_rows) + matrix.offset];
                    i++;
                }
            }
        }
    }

   return (create_matrix(arr,(matrix.n_rows *  reps),( matrix.n_cols * reps)));

}
//funcao

int get_element(Matrix matrix, int ri, int ci)
{

    int *num, valor=0;
    num = matrix.data;

    if (ri  >= matrix.n_rows)
    {
        printf("elemento nao existe");
    }
    else if(ci >= matrix.n_cols)
    {
        printf("elemento nao existe");
    }
    else
    {
        valor = num[ri*matrix.stride_rows + ci*matrix.stride_cols + matrix.offset];


    }


    return(valor);

}

void put_element(Matrix matrix, int ri, int ci, int elem){



    if (ri >= matrix.n_rows)
    {
        printf("elemento nao existe");
    }
    else if(ci >= matrix.n_cols)
    {
        printf("elemento nao existe");
    }
    else
    {
        matrix.data[ri*matrix.stride_rows + ci*matrix.stride_cols + matrix.offset] = elem;
    }




}

Matrix transpose(Matrix matrix)
{

    int guardar=0;
    guardar = matrix.n_rows;
    matrix.n_rows = matrix.n_cols;
    matrix.n_cols = guardar;

    guardar = matrix.stride_rows;
    matrix.stride_rows = matrix.stride_cols;
    matrix.stride_cols = guardar;



return (matrix);
}

Matrix reshape(Matrix matrix, int new_n_rows, int new_n_cols)
{
    if((new_n_rows * new_n_cols)==(matrix.n_rows * matrix.n_cols)){
        matrix.n_rows = new_n_rows;
        matrix.n_cols = new_n_cols;
        if(matrix.stride_cols == 1)
            matrix.stride_rows = new_n_cols;
        else
            matrix.stride_cols = new_n_rows;
    }
return (matrix);
}

Matrix slice(Matrix a_matrix, int rs, int re, int cs, int ce)
{


        if((ce<=a_matrix.n_cols) || (re<=a_matrix.n_rows) || (cs>-1) || (rs>-1) || (ce>=cs) || (re>=rs))
        {

            a_matrix.offset  = rs*a_matrix.stride_rows + cs*a_matrix.stride_cols + a_matrix.offset;
            a_matrix.n_rows = re-rs;
            a_matrix.n_cols = ce-cs;

            //if(a_matrix.stride_cols == 1)
                //a_matrix.stride_rows = ce-cs;
            //else
                //a_matrix.stride_cols = re-rs;


        }

        else
        {
            printf("Intervalo invalido! \n");
        }


        return(a_matrix);



}





int min(Matrix matrix){

   int  comparar = matrix.data[matrix.offset];

    for (int rows = 0; rows < matrix.n_rows ; ++rows)
    {
        for (int cols = 0; cols < matrix.n_cols ; ++cols)
        {
                if (comparar < (matrix.data[matrix.stride_cols*cols + matrix.stride_rows*rows + matrix.offset]))
                    comparar = (matrix.data[matrix.stride_cols*cols + matrix.stride_rows*rows + matrix.offset]);
        }
    }

   return comparar;

}

int max(Matrix matrix)
{
    int  comparar = matrix.data[0];

    for (int i = 0 ; i<matrix.n_rows*matrix.n_cols;i++)

    {
       if(comparar < matrix.data[i])
       {

            comparar = matrix.data[i];
       }

    }

    return comparar;

}

int argmin(Matrix matrix)
{

    int  comparar = matrix.data[0], direcao = 0;

    for (int i = 0 ; i<matrix.n_rows*matrix.n_cols;i++)

    {
       if(comparar > matrix.data[i])
       {

            comparar = matrix.data[i];
            direcao = i;
       }

    }

    return (direcao);

}


int argmax(Matrix matrix)
{

    int  comparar = matrix.data[0], direcao = 0;

    for (int i = 0 ; i<matrix.n_rows*matrix.n_cols;i++)

    {
       if(comparar < matrix.data[i])
       {

            comparar = matrix.data[i];
            direcao = i;
       }

    }

    return (direcao);




}


Matrix add(Matrix matrix_1, Matrix matrix_2)
{

    if((matrix_1.n_rows == matrix_2.n_rows)||(matrix_1.n_cols == matrix_2.n_cols))
    {
        int* arr = (int*)malloc(matrix_1.n_rows * matrix_1.n_cols * sizeof(int));
        int i = 0;

        for (int rows = 0; rows < matrix_1.n_rows ; ++rows)
        {
            for (int cols = 0; cols < matrix_1.n_cols ; ++cols)
            {
                arr[i] = (matrix_1.data[matrix_1.stride_cols*cols + matrix_1.stride_rows*rows + matrix_1.offset] + matrix_2.data[matrix_2.stride_cols*cols + matrix_2.stride_rows*rows + matrix_2.offset]);
                i++;
            }
        }
        return(create_matrix(arr,matrix_1.n_rows,matrix_1.n_cols));
    }
    else
    {
        printf("Valor inv�lido");
        return matrix_1;

    }

}


Matrix sub(Matrix matrix_1, Matrix matrix_2)
{

    if((matrix_1.n_rows * matrix_1.n_cols)==(matrix_2.n_rows * matrix_2.n_cols))
    {
        int* arr = (int*)malloc(matrix_1.n_rows * matrix_1.n_cols * sizeof(int));
        int i = 0, j = 1 , i2 = 0;


        for (int m = 0; m < matrix_1.n_cols ; ++m)
        {
            for (int k = 0; k < matrix_1.n_rows ; ++k)
            {
                    arr[k+m*matrix_1.n_rows]= matrix_1.data[i+matrix_1.offset] - matrix_2.data[i2+matrix_2.offset];
                    i+=matrix_1.stride_cols;
                    i2+=matrix_2.stride_cols;
            }
            i = matrix_1.stride_rows*j;
            i2 = matrix_2.stride_rows*j;
            j++;
        }
        return(create_matrix(arr,matrix_1.n_rows,matrix_1.n_cols));
    }
    else
    {
        printf("Valor inv�lido");
        return matrix_1;


    }

}

Matrix division(Matrix matrix_1, Matrix matrix_2)
{

    if((matrix_1.n_rows * matrix_1.n_cols)==(matrix_2.n_rows * matrix_2.n_cols))
    {
        int* arr = (int*)malloc(matrix_1.n_rows * matrix_1.n_cols * sizeof(int));
        int i = 0, j = 1 , i2 = 0;


        for (int m = 0; m < matrix_1.n_cols ; ++m)
        {
            for (int k = 0; k < matrix_1.n_rows ; ++k)
            {
                    arr[k+m*matrix_1.n_rows]= matrix_1.data[i+matrix_1.offset] / matrix_2.data[i2+matrix_2.offset];
                    i+=matrix_1.stride_cols;
                    i2+=matrix_2.stride_cols;
            }
            i = matrix_1.stride_rows*j;
            i2 = matrix_2.stride_rows*j;
            j++;
        }
        return(create_matrix(arr,matrix_1.n_rows,matrix_1.n_cols));
    }
    else
    {
        printf("Valor inv�lido");
        return matrix_1;


    }

}


Matrix mul(Matrix matrix_1, Matrix matrix_2)
{

    if((matrix_1.n_rows * matrix_1.n_cols)==(matrix_2.n_rows * matrix_2.n_cols))
    {
        int* arr = (int*)malloc(matrix_1.n_rows * matrix_1.n_cols * sizeof(int));
        int i = 0, j = 1 , i2 = 0;


        for (int m = 0; m < matrix_1.n_cols ; ++m)
        {
            for (int k = 0; k < matrix_1.n_rows ; ++k)
            {
                    arr[k+m*matrix_1.n_rows]= matrix_1.data[i+matrix_1.offset] * matrix_2.data[i2+matrix_2.offset];
                    i+=matrix_1.stride_cols;
                    i2+=matrix_2.stride_cols;
            }
            i = matrix_1.stride_rows*j;
            i2 = matrix_2.stride_rows*j;
            j++;
        }
        return(create_matrix(arr,matrix_1.n_rows,matrix_1.n_cols));
    }

    else
    {
        printf("Valor inv�lido");
        return matrix_1;


    }

}
