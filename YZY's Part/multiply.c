double multiply(void){
	
	char mulvar;
	int mullb;
	int mulub;
	char mulf[1000];
	int muli;
	double mulsum = 0;
	
	printf("��������Ҫ��͵ı�����");
	scanf("%c",&mulvar);
	printf("������������ޣ�"); 
	scanf("%d",&mullb); 
	printf("������������ޣ�");
	scanf("%d",&mulub);
	printf("�����뺬�иñ����ĺ�����");
	scanf("%s",&mulf);
	for(muli=mullb;muli<=mulub;muli++){
		mulsum += mulf(muli);
	}
	return mulsum;
}
