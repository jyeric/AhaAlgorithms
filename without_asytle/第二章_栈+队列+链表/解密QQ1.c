#include<stdio.h>
int main()
{
	int q[102]={0,6,3,1,7,5,8,9,2,4},head,tail;
	/*��ʼ������*/
	head=1;
	tail=10;  //�������Ѿ���9��Ԫ���ˣ�tailָ���β�ĺ�һ��λ��
	while(head<tail)  //�����в�Ϊ�յ�ʱ��ִ��ѭ��
	{
		printf("%d ",q[head]);  //��ӡ���ײ������׳���
		head++;
		
		q[tail]=q[head];  //�Ƚ��¶��׵�����ӵ���β
		tail++;
		head++;  //�ٽ����׳��� 
	} 
	return 0;
}
