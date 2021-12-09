#include<stdio.h>
//#include "func.h"//引入非初等函数模块 
#include <math.h>
double Gamma(double x);
double Beta(double p ,double q);
double DecimalFactorial(double x);
void main(int argv,const char *argc[]){

    double a,b;
    printf("please input the nummber you want to calculate");
    scanf("%lf,%lf",&a,&b);
    printf("%.4f! = %.4f\n",a,DecimalFactorial(a));
    printf("Γ(%.4f) = %.4f\n",a,Gamma(a));
    printf("B(%.4f,%.4f) = %.15f\n",a,b,Beta(a,b));

}
double Gamma(double x){
	const double pi=3.1415926535;
    int i;
    double y,t,s,u;
    static double a[11]={ 0.0000677106,-0.0003442342,
                          0.0015397681,-0.0024467480, 0.0109736958,
                          -0.0002109075,0.0742379071, 0.0815782188,
                          0.4118402518,0.4227843370,1.0};
    if (x<=0.0){
        printf("err**x<=0!\n");
        return(-1.0);
    }

    y=x;
    if (y<=1.0){
        t=1.0/(y*(y+1.0));
        y=y+2.0;
    }
    else
    if(y<=2.0){
        t=1.0/y;
        y=y+1.0;
    }
    else if(y<=3.0){
        t=1.0;
    }
    else{
        t=1.0;
        while (y>3.0){
            y=y-1.0;
            t=t*y;
        }
    }
    s=a[0];
    u=y-2.0;
    for (i=1; i<=10; i++){
        s=s*u+a[i];
    }
    s=s*t;
    return(s);
}
double DecimalFactorial(double x){
    return Gamma(x+1);
}

double Beta(double p ,double q){
	const double pi = 3.1415926535;
    if (p > 10.0 || q > 10.0){
        return sqrt(2 * pi)*pow(p,p-0.5)*pow(q,q-0.5)/pow(p+q,p+q-0.5);
    }else if (p <= 10.0 && p >= 0.0 && q <= 10.0 && q >= 0.0){
        return Gamma(p)*Gamma(q)/Gamma(p+q);
    }else{
        printf("err**x<=0!\n");
        return 1;
    }
}
