#include <stdio.h>
int LOOK(int a){
	if(a>=10)
		printf("�����ҵ�Ǯ������%dԪǮ��Ǯ̫����\n",a);
	else 
		printf("�����ҵ�Ǯ������%dԪǮ����̫����\n",a); 
	return 0; 
}
int main(){
	int wallet=0,s=0,h=0;
	printf("��1�·��������£�\n");
	wallet=wallet+4;
	LOOK(wallet);
	printf("��1�·ݿ�����\n") ;
	wallet=wallet-4; 
	LOOK(wallet);
	printf("���ڿ�ʼ��¼2�·ݵ������֧����\n"); 
	for(int i=1;i<=28;i++)
	{
		scanf("%d",&s);
		printf("����2��%d��������%dԪǮ",i,s);
		wallet=wallet+s;
		LOOK(wallet); 
		scanf("%d",&h);
		printf("����2��%d��֧����%dԪǮ",i,h);	
		wallet=wallet-h;
		LOOK(wallet); 
	}
	return 0; 
}


