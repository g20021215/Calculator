#include <math.h>
#include <stdio.h>
#define MAXN 30
#define pi 3.1415926535898
#define DEC (pi/180)
double X(double x);
double POW(double x);
double SIN(double x);
double COS(double x);
double TAN(double x);
double LOG(double x);
double SEC(double x);
double COT(double x);
double LNX(double x);
double ARCSIN(double x);
double ARCCOS(double x);
double ARCTAN(double x);
double Definite_integral(double a, double b, double (*p)(double x));
void intergral_menu();
void program();
int main() {
	intergral_menu();
	program();
	return 0;
}

void intergral_menu() {
	printf("#############################################\n");
	printf("1--x\n");
	printf("2--x^3+x^2+x+1\n");
	printf("3--sin(x)\n");
	printf("4--cos(x)\n");
	printf("5--tan(x)\n");
	printf("6--log(x)\n");
	printf("7--ln(x)\n");
	printf("8--sec(x)\n");
	printf("9--cot(x)\n");
	printf("10--arcsin(x)\n");
	printf("11--arccos(x)\n");
	printf("12--arctan(x)\n");
	printf("0--quit\n");
	printf("#############################################\n");
}
void program() {
	double a, b;
	int index;
	while (1) {
		printf("请选择一个数字(函数)："); scanf("%d", &index);
		switch (index) {
		case 1:
			printf("请输入积分下限：");
			scanf("%lf", &a);
			printf("请输入积分上限：");
			scanf("%lf", &b);
			printf("%f\n", Definite_integral(a, b, X));
			break;
		case 2:
			printf("请输入积分下限：");
			scanf("%lf", &a);
			printf("请输入积分上限：");
			scanf("%lf", &b);
			printf("%f\n", Definite_integral(a, b, POW));
			break;
		case 3:
			printf("请输入积分下限：");
			scanf("%lf", &a);
			printf("请输入积分上限：");
			scanf("%lf", &b);
			printf("%f\n", Definite_integral(a, b, SIN));
			break;
		case 4:
			printf("请输入积分下限：");
			scanf("%lf", &a);
			printf("请输入积分上限：");
			scanf("%lf", &b);
			printf("%f\n", Definite_integral(a, b, COS));
			break;
		case 5:
			printf("请输入积分下限：");
			scanf("%lf", &a);
			printf("请输入积分上限：");
			scanf("%lf", &b);
			printf("%f\n", Definite_integral(a, b, TAN));
			break;
		case 6:
			printf("请输入积分下限：");
			scanf("%lf", &a);
			printf("请输入积分上限：");
			scanf("%lf", &b);
			printf("%f\n", Definite_integral(a, b, LOG));
			break;
		case 7:
			printf("请输入积分下限：");
			scanf("%lf", &a);
			printf("请输入积分上限：");
			scanf("%lf", &b);
			printf("%f\n", Definite_integral(a, b, LNX));
			break;
		case 8:
			printf("请输入积分下限：");
			scanf("%lf", &a);
			printf("请输入积分上限：");
			scanf("%lf", &b);
			printf("%f\n", Definite_integral(a, b, SEC));
			break;
		case 9:
			printf("请输入积分下限：");
			scanf("%lf", &a);
			printf("请输入积分上限：");
			scanf("%lf", &b);
			printf("%f\n", Definite_integral(a, b, COT));
			break;
		case 10:
			printf("请输入积分下限：");
			scanf("%lf", &a);
			printf("请输入积分上限：");
			scanf("%lf", &b);
			printf("%f\n", Definite_integral(a, b, ARCSIN));
			break;
		case 11:
			printf("请输入积分下限：");
			scanf("%lf", &a);
			printf("请输入积分上限：");
			scanf("%lf", &b);
			printf("%f\n", Definite_integral(a, b, ARCCOS));
			break;
		case 12:
			printf("请输入积分下限：");
			scanf("%lf", &a);
			printf("请输入积分上限：");
			scanf("%lf", &b);
			printf("%f\n", Definite_integral(a, b, ARCTAN));
			break;
		case 0:
			return;
			break;
		default:
			printf("请再次输入:");
			break;
		}
	}
}
/*梯形法*/ 
double Definite_integral(double a, double b, double (*p)(double x)) {
	int i, n = MAXN;
	double x, y1, y2, deta, f;
	deta = (b - a) / n;
	x = a;
	y1 = (*p)(x);
	f = 0;
	for (i = 0; i < n; i++) {
		x += deta;
		y2 = (*p)(x);
		f += (y1 + y2) * deta / 2;
		y1 = y2;
	}
	return f;
}

double X(double x) {
	return x;
}
double POW(double x) {
	return x * x * x + x * x + x + 1;
}
double SIN(double x) {
	return sin(x);
}
double COS(double x) {
	return cos(x);
}
double TAN(double x) {
	return tan(x);
}
double LOG(double x) {
	return log(x);
}
double SEC(double x) {
	return 1 / cos(x);
}
double COT(double x) {
	return -1 / pow(sin(x), 2);
}
double LNX(double x) {
	return 1 / x;
}
double ARCSIN(double x) {
	return asin(x);
}
double ARCCOS(double x) {
	return acos(x);
}
double ARCTAN(double x) {
	return atan(x);
}
