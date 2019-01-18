#include<stdio.h>
int n,m,p,q,min=99999999;
int a[51][51],book[51][51];
void dfs(int x,int y,int step)
{
    int next[4][2]={
    {0,1},//������
    {1,0},//������
    {0,-1},//������
    {-1,0},//������ 
    };
    int tx,ty,k;
    if(x==p && y==p)  //�ж��Ƿ񵽴�С����λ�� 
    {
        if(step<min)
            min=step;  //������Сֵ
        return; 
    }
    /*ö�������߷�*/ 
    for(k=0;k<=3;k++)
    {
        /*������һ���������*/
        tx=x+next[k][0];
        ty=y+next[k][1];
        if(tx<1 || tx>n || ty<1 || ty>m)  //�ж��Ƿ�Խ��
            continue;
        /*�жϸõ��Ƿ�Ϊ�ϰ�������Ѿ���·����*/
        if(a[tx][ty]==0 && book[tx][ty]==0)
        {
            book[tx][ty]=1;  //���������Ѿ��߹�
            dfs(tx,ty,step+1);  //��ʼ������һ����
            book[tx][ty]=0;  //���Խ�����ȡ�������ı�� 
        } 
    }
    return;
} 

int main()
{
    int i,j,startx,starty;
    scanf("%d %d",&n,&m);  //����n��m��nΪ�У�mΪ��
    /*�����Թ�*/
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    scanf("%d %d %d %d",&startx,&starty,&p,&q);  //���������յ�����
    /*����㿪ʼ����*/
    book[startx][starty]=1;  //�������Ѿ���·���У���ֹ�����ظ���
    dfs(startx,starty,0);  //��һ������������x���꣬�Դ�����������y���꣬��ʼ����Ϊ0
    printf("%d",min);  //�����̲���
    return 0; 
}
