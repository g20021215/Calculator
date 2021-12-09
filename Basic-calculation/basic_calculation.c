#include<stdio.h>
#include<math.h>
void basic_calculation(double x,char A, double y);
int main(int argc, const char* argv[]){
    double a,b;
    char A;
    scanf("%lf%c%lf",&a,&A,&b);
    basic_calculation(a,A,b);
}
void basic_calculation(double x,char A, double y){
    //char A;
    //double x,y;
    double c;

    switch(A){
        case '+':
            c = x+y;
            printf("%f",c);
            break;
        case '-':
            c = x-y;
            printf("%f",c);
            break;
        case '*':
            c = x*y;
            printf("%f",c);
            break;
        case '/':
            c = x/y;
            printf("%f",c);
            break;
        case '^':
            c = pow(x,y);
            printf("%f",c);
            break;
    }
    return c;
}
