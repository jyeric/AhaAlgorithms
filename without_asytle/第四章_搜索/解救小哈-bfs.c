#include<stdio.h>
struct note{
	int x;  //������
	int y;  //������
	int f;  //�����ڶ����еı�ţ����ⲻ��Ҫ���·�������Բ���Ҫf�� 
	int s;  //���� 
};
int main()
{
	struct note que[2501];  //��Ϊ��ͼ��С������50*50����˶�����չ���ᳬ��2500��
	
	int a[51][51] = {0};  //�����洢��ͼ 
	int book[51][51] = {0};  //����book�������Ǽ�¼��Щ���Ѿ��ڶ������ˣ���ֹһ���㱻�ظ���չ����ȫ����ʼ��Ϊ0
	//����һ�����ڱ�ʾ�ߵķ��������
	int next[4][2] = {  //˳ʱ�뷽�� 
	{0,1}, //������ 
	{1,0},  //������ 
	{0,-1},  //������ 
	{-1,0},  //������ 
	};

	int head,tail;
	int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
	
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	
	//���г�ʼ��
	head = 1;
	tail = 1;
	//�����в����Թ�������� 
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;
	
	flag = 0;  //��������Ƿ񵽴�Ŀ��㣬0��ʾ��ʱû�е�� 1��ʾ�ѵ���
	while(head < tail){  //�����в�Ϊ��ʱѭ�� 
		for(k=0;k<=3;k++)  //ö���ĸ����� 
		{
			//������һ��������� 
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			if(tx < 1 || tx > n || ty < 1 || ty > m)  //�ж��Ƿ�Խ�� 
				continue;
			if(a[tx][ty] == 0 && book[tx][ty] == 0)  //�ж��Ƿ����ϰ�������Ѿ���·���� 
				{
					book[tx][ty] = 1;  //���������Ϊ�Ѿ��߹���ע��bfsÿ����ͨ�������ֻ���һ�Σ������Ѳ�ͬ������Ҫ��book���黹ԭ
					//�����µĵ㵽������
					que[tail].x = tx;
					que[tail].y = ty;
					que[tail].f = head;  //��Ϊ������Ǵ�head��չ�����ģ��������ĸ�����head�����ⲻ��Ҫ��·������˿�ʡ�� 
					que[tail].s = que[head].s+1;  //�����Ǹ��׵Ĳ���+1
					tail++; 
					
				}
			if(tx == p && ty == q)  //�����Ŀ����ˣ�ֹͣ��չ������������˳�ѭ�� 
			{
				flag = 1;  //��Ҫ�����䲻Ҫд�� 
				break;
			}
		}
		if(flag == 1)
			break;
		head++;  //��һ������չ�����󣬲��ܶԺ���ĵ��ٽ�����չ 
	}	
	printf("%d",que[tail-1].s);  //��ӡ������ĩβ���һ���㣬Ҳ����Ŀ���Ĳ��� 
 	//ע��tail��ָ����ж�β�����һλ������һ��λ�ã�����������Ҫ��1 
	getchar();getchar();
	return 0;		 
}
