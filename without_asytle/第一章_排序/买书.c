#include<stdio.h>
int main()
{
	int a[1001],n,i,t;
	for(i=1;i<=1000;i++)
		a[i]=0;  //��ʼ��
		
	scanf("%d",&n);
	for(i=1;i<=n;i++)  //ѭ������n��ͼ���ISBN��
	{
		scanf("%d",&t);  //��ÿһ��ISBN�Ŷ�������t��
		a[t]=1;  //��ǳ��ֹ���ISBN�� 
	} 
	
	for(i=1;i<=1000;i++)  //�����ж�1~1000���1000��Ͱ
	{
		if(a[i]==1)  //������ISBN���ֹ��ʹ�ӡ����
			printf("%d ",i); 
	} 
	return 0;
} 
