#include<stdio.h>
int main()
{
	int data[101],right[101];
	int i,n,t,len;
	scanf("%d",&n);  //�������е���
	for(i=1;i<=n;i++)
		scanf("%d",&data[i]);
	len=n;
	for(i=1;i<=n;i++)  //��ʼ������right
	{
		if(i!=n)
			right[i]=i+1;
		else
			right[i]=0;
	} 
	len++;  //ֱ��������data��ĩβ����һ���� 
	scanf("%d",&data[len]);  
	/*�������ͷ����ʼ����*/
	t=1;
	while(t!=0)
	{
		if(data[right[t]]>data[len])  //�����ǰ�����һ������ֵ���ڴ����������������뵽�м�
		{
			right[len]=right[t];  //�²���������һ������ŵ��ڵ�ǰ������һ�������
			right[t]=len;  //��ǰ������һ������ž����²������ı��
			break;  //�����������ѭ�� 
		} 
		t=right[t];
	} 
	/*������������е���*/ 
	t=1;
	while(t!=0)
	{
		printf("%d ",data[t]);
		t=right[t];	
	}
	return 0;
} 
