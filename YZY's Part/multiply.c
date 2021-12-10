double multiply(void){
	
	char mulvar;
	int mullb;
	int mulub;
	char mulf[1000];
	int muli;
	double mulsum = 0;
	
	printf("请输入您要求和的变量：");
	scanf("%c",&mulvar);
	printf("请输入求和下限："); 
	scanf("%d",&mullb); 
	printf("请输入求和上限：");
	scanf("%d",&mulub);
	printf("请输入含有该变量的函数：");
	scanf("%s",&mulf);
	for(muli=mullb;muli<=mulub;muli++){
		mulsum += mulf(muli);
	}
	return mulsum;
}
