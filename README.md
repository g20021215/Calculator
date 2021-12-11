# Calculator
## 1.Introduction: 
  This Calculator will be constructed by several parts: Mixed computing, integration, derivative, sum, prod, non-elementary function, trignomatric, matrix. Due to time constraints, we may not be able to update all the modules listed in the near future. 
## 2.Details:
### Part1: mixed computing.
You can use Dev C++ to open the whole project. Run the code to get the value for any two double computation. Also, you can input them for many times as long as you are not input q to the console. This part is mainly accomplished by stack. we need to get the value and notation from the string. And we also set the computation priorities and the detection of the parentheses.
### Part 2: Integral:
We use the trapezoid method to get the integral value for certain kinds of function. But the antiderivative we didn't realize. It is constructed by different kinds of notations, which is vary hard to realize by C language.
### Part 3: Matrix:
By running this modules, we can get the transpose of matrix and the multiplication of the matrix. First, we need to input the dimension of the matrix, and we input the value to the first matrix.Also, we input the second matrix in the same method. Then, we choose the calculation we need to do later. We use the pointer to take the first matrix row by row and take the second matrix column by column. Multiply the items in order, and we get the result of matrix multiplication.For matrix addition, we use the pointer to add the elements in the matrix.Since the matrices can be defined in rows and columns, use typedef can easily describe all matrices. That means each rows and columns will be the units in compute for transformation，plus, and  multiple in matrices.
