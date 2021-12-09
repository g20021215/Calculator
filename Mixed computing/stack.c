#include "stack.h"
#include<math.h>

//栈的初始化 
LinkStack* InitStack() {
    LinkStack *t = (LinkStack*)malloc(sizeof(LinkStack));
    t->next = NULL;
    return t;
}

//空栈 
int Empty(LinkStack *s) {
    return s->next == NULL;
}

//
void Push(LinkStack *s, dataType x) {
    node *t = (node*)malloc(sizeof(node));
    t->data = x;
    t->next = s->next;
    s->next = t;
}

//删除最后一个 
void Pop(LinkStack *s) {
    if (Empty(s)) exit(1);
    node *p = s->next;
    s->next = p->next;
    free(p);
}

//取顶层元素 
dataType GetTop(LinkStack *s) {
    return s->next->data;
}

//优先级 
int priority(char x) {
    switch (x) {
        case '+':
        case '-':
        case '=': return 1;
        case '*':
        case '/': 
		case '^': return 2;
        case '(': return 3;
    }
}
double compute(double x, double y, char op) {
    switch(op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        case '^': return pow(1.0*x,1.0*y);
    }
}

double Gamma(double x){
	const double pi=3.1415926535;
    int i;
    double s,y,t,u;
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
	
    if (p > 10.0 || q > 10.0){
    	double const pi=3.1415926535897932384626433;
        return sqrt(2*pi)*pow(p,p-0.5)*pow(q,q-0.5)/pow(p+q,p+q-0.5);
    }else if (p <= 10.0 && p >= 0.0 && q <= 10.0 && q >= 0.0){
        return Gamma(p)*Gamma(q)/Gamma(p+q);
    }else{
        printf("err**x<=0!\n");
        return 1;
    }
}

                 
