#include <stdio.h>
#include <stdlib.h>
#include<math.h> 
#include "stack.h"
//#include "basic_calculation.h"
//#include "func.h"//����ǳ��Ⱥ���ģ�� 
double Gamma(double x);
//ȫ�ֱ������� 
int main() {
	//const double pi = 3.1415926535897932384626433;
	char A;
	char B;
    //printf("����������Ҫ���е���������\n");
	printf("a:�����(�Ӝp�˳��������)\t q:�˳�\n");
	do{
		scanf("%c",&A);
		char s2[500],op,t[1001];
	    double s1[500];
	    int top1=-1, top2=-1;
	    double x,y;
		double p,q,s;
			switch (A){
				case 'a':
					printf("��������ʽ(�ɰ����Ӽ��˳�������):");
		    		scanf("%s",t);
		    		for (int i=0; i<strlen(t); i++) {
		        		if (t[i]>='0' && t[i]<='9') {
		            		double value = 0;
		            		while (t[i]>='0' && t[i]<='9') {
		                		value = 10*value + t[i] - '0';
		                		i++;
		            		}
		            		if (t[i] == '.') {
		                		int r = 10;
		                		i++;
		                		while (t[i]>='0' && t[i]<='9') {
		                    		value += (double)(t[i]-'0')/r;
		                    		r = 10 * r;
		                    		i++;
		                		}
		            		}
		            		s1[++top1] = value;
		        		}
		        		if (t[i] == ')') {
		            		while (s2[top2] !='(') {
		                		y = s1[top1--]; 
		                		x = s1[top1--];
		                		op = s2[top2--];
		                		s1[++top1] = compute(x,y, op);
		            		}
		            		top2--;
		        		} else {
		            		while (top2!=-1 && s2[top2]!='('
		                		    && priority(t[i])<=priority(s2[top2])) {
		                		y = s1[top1--];
		                		x = s1[top1--];
		                		op = s2[top2--];
		                		s1[++top1] = compute(x, y, op);
		            		}
		            		s2[++top2] = t[i];
		        		}
		    		}
		    		printf("%.2f\n", s1[top1]);
					break;
				case 'q':
					break;
				default:
					printf("Please inout the next formular\n");
			}
		}while(A != 'q'); 
	//return 0; 
}
//Class f:
