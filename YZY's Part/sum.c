double sum(void){
	
	char sumvar;
	int sumlb; // lb is for lower bound
	int sumub; // ub is for upper bound 
	char sumf[1000];
	int sumi;
	double sumsum = 0;
	
	printf("��������Ҫ��͵ı�����");
	scanf("%c",&sumvar);
	printf("������������ޣ�"); 
	scanf("%d",&sumlb); 
	printf("������������ޣ�");
	scanf("%d",&sumub); 
	printf("�����뺬�иñ����ĺ�����");
	scanf("%s",&sumf);
	for(sumi=sumlb;sumi<=sumub;sumi++){
		sumsum += sumf(sumi);
	}
	return sumsum;
}
