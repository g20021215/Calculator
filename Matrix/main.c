#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

double value[100][100] ;
double value2[100][100] ;

typedef struct
{
    int row,line;
    double *data;
}Matrix;

Matrix* InitMatrix(Matrix *matrix,int row,int line);		//初始化矩阵
void ValueMatrix(Matrix *matrix,double *array);				//给一个矩阵赋值
int SizeMatrix(Matrix *matrix);								//获得一个矩阵的大小
void CopyMatrix(Matrix *matrix_A, Matrix *matrix_B);		//复制一个矩阵的值
void PrintMatrix(Matrix *matrix);							//打印一个矩阵

//矩阵的基本运算
Matrix* AddMatrix(Matrix *matrix_A,Matrix *matrix_B);		//矩阵的加法
Matrix* MulMatrix(Matrix *matrix_A,Matrix *matrix_B);		//矩阵的乘法
void TransMatrix(Matrix *matrix);			                //矩阵转置(条件为方阵)
double DerMatrix(Matrix *matrix);                             //矩阵的行列式

int main()
{
    int m1,m2,n1,n2,n,m,l;
    printf("Enter the number of matrix ( up to 2).\n");
    scanf("%d",&n);
    if (n == 1){
        printf("input the value of row in matrix\n");
        scanf("%d",&m1);
        printf("input the value of line in matrix\n");
        scanf("%d",&n1);
        printf("input the value of matrix :\n");
        for(int i = 0; i < m1; i++)
        {
            for(int j = 0; j < n1;j++){scanf("%lf",&value[i][j]);}
        }
        Matrix *matrix = InitMatrix(matrix,m1,n1);
        printf("Enter your choice\n");
        printf("1.Transformation\n");
        scanf("%d",&m);


        if( m == 1){
            ValueMatrix(matrix,value);
            printf("矩阵1进行转置: \n");
            TransMatrix(matrix);
            PrintMatrix(matrix);
        }
    }
    else if(n == 2){
        printf("input the value of row in matrix 1\n");
        scanf("%d",&m1);
        printf("input the value of line in matrix 1\n");
        scanf("%d",&n1);
        printf("input the value of matrix 1:\n");
        for(int i = 0; i < m1; i++)
        {
            for(int j = 0; j < n1;j++){scanf("%lf",&value[i][j]);}
        }
        Matrix *matrix1 = InitMatrix(matrix1,m1,n1);

        printf("input the value of row in matrix 2\n");
        scanf("%d",&m2);
        printf("input the value of line in matrix 2\n");
        scanf("%d",&n2);
        printf("input the value of matrix 2:\n");
        for(int i = 0; i < m2; i++)
        {
            for(int j = 0; j < n2;j++){scanf("%lf",&value[i][j]);}
        }
        Matrix *matrix2 = InitMatrix(matrix2,m2,n2);
        printf("Enter your choice\n");
        printf("1.multiply\n 2.add\n");
        scanf("%d",&l);
        switch (l) {
            case 1:
                ValueMatrix(matrix1,value);
                CopyMatrix(matrix1,matrix2);	//复制赋值
                ValueMatrix(matrix2,value2);
                printf("The multiply of matrix1 and matrix2 is : \n");
                Matrix *matrix3 = MulMatrix(matrix1,matrix2);
                PrintMatrix(matrix3);
                break;
            case 2:
                ValueMatrix(matrix1,value);
                CopyMatrix(matrix1,matrix2);	//复制赋值
                ValueMatrix(matrix2,value2);
                PrintMatrix(matrix2);
                Matrix *matrix4 = AddMatrix(matrix1,matrix2);	//加法
                PrintMatrix(matrix4);
                break;
        }

    }





    return 0;
}

Matrix* InitMatrix(Matrix *matrix,int row,int line)				//初始化一个矩阵
{
    if (row>0 && line>0)
    {
        matrix = (Matrix*)malloc(sizeof(Matrix));
        matrix->row = row;
        matrix->line = line;
        matrix->data = (double*)malloc(sizeof(double)*row*line);
        memset(matrix->data,0,sizeof(double)*row*line);
        return matrix;
    }
    else
        return NULL;
}

void ValueMatrix(Matrix *matrix,double *array) 		//给矩阵赋值
{
    if (matrix->data != NULL)
    {
        memcpy(matrix->data, array, matrix->row*matrix->line*sizeof(double));
    }
}

int SizeMatrix(Matrix *matrix)
{
    return matrix->row*matrix->line;
}



void CopyMatrix(Matrix *matrix_A, Matrix *matrix_B)
{
    matrix_B->row = matrix_A->row;
    matrix_B->line = matrix_A->line;
    memcpy(matrix_B->data, matrix_A->data, SizeMatrix(matrix_A)*sizeof(double));
}

void PrintMatrix(Matrix *matrix)
{
    for (int i=0;i<SizeMatrix(matrix);i++)
    {
        printf("%lf\t", matrix->data[i]);
        if ((i+1)%matrix->line == 0)
            printf("\n");
    }

}
//加法
Matrix* AddMatrix(Matrix *matrix_A,Matrix *matrix_B)
{
    if (matrix_A->row == matrix_B->row && matrix_A->line == matrix_B->line)
    {
        Matrix *matrix_C = InitMatrix(matrix_C,matrix_A->row,matrix_A->line);
        for (int i=0;i<matrix_A->line;i++)
        {
            for (int j=0;j<matrix_A->row;j++)
            {
                matrix_C->data[i*matrix_C->row + i] = \
				matrix_A->data[i*matrix_A->row + j] + matrix_B->data[i*matrix_A->row + j];
            }
        }
        return matrix_C;
    }
    else
    {
        printf("Error input\n");
        return NULL;
    }
}

//乘法
Matrix* MulMatrix(Matrix *matrix_A,Matrix *matrix_B)
{
    if (matrix_A->row == matrix_B->line)		//列==行
    {
        Matrix *matrix_C = InitMatrix(matrix_C,matrix_B->row,matrix_A->line);
        // matrix_C->line = matrix_A->line;		//A行
        // matrix_C->row = matrix_B->row;			//B列
        for (int i=0;i<matrix_A->row;i++)
        {
            for (int j=0;j<matrix_B->line;j++)
            {
                for (int k=0;k<matrix_A->line;k++)
                {
                    matrix_C->data[i*matrix_C->line + j] += \
					matrix_A->data[i*matrix_A->line + k] * matrix_B->data[k*matrix_B->row + j];
                }
            }
        }
        return matrix_C;
    }
    else
    {
        printf("Error input\n");
        return NULL;
    }
}

//矩阵转置
void TransMatrix(Matrix *matrix)			//条件为方阵
{
    if (matrix->row == matrix->line)
    {
        Matrix *matrixTemp = InitMatrix(matrixTemp, matrix->row,matrix->line);       	//创建一个临时矩阵
        CopyMatrix(matrix,matrixTemp);	//将目标矩阵的data复制给临时矩阵

        for (int i=0;i<matrix->row;i++)
        {
            for (int j=0;j<matrix->line;j++)
            {
                matrix->data[i*matrix->row + j] = matrixTemp->data[j*matrix->row + i];
            }
        }
    }
    else
    {
        printf("Error input\n");
    }
}

double DerMatrix(Matrix *matrix)
{
    for (int i = 0; i < matrix->row;i++ )
    {
        for (int j = 0; j < matrix->line;j++)
        {
            value[i][j] = value[i][j]/value[i][1];

        }
    }
}


