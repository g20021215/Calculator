double sum(void){
	
	char sumvar;
	int sumlb; // lb is for lower bound
	int sumub; // ub is for upper bound 
	char sumf[1000];
	int sumi;
	double sumsum = 0;
	
	printf("请输入您要求和的变量：");
	scanf("%c",&sumvar);
	printf("请输入求和下限："); 
	scanf("%d",&sumlb); 
	printf("请输入求和上限：");
	scanf("%d",&sumub); 
	printf("请输入含有该变量的函数：");
	scanf("%s",&sumf);
	for(sumi=sumlb;sumi<=sumub;sumi++){
		sumsum += sumf(sumi);
	}
	return sumsum;
}
