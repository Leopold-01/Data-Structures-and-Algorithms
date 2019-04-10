#include<iostream>
#include<cstdio>
#define MaxSize 10000
#define M 8
#define N 8
using namespace std;

//�Թ����飬��ԭ���Թ������ϼ�һȦΧǽ �����ж�   
int mg[M+2][N+2]=
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
};


//���巽������ 
typedef struct
{
	int i;//��ǰ������к� 
	int j;//��ǰ������к� 
	int di;//di����һ�����ߵ����ڷ���ķ�λ�� 
}Box;

//����˳��ջ���� 
typedef struct
{
	Box data[MaxSize];
	int top;//ջ��ָ�� 
}StType;

//Ѱ�Ҳ����·�� 
bool mgpath(int xi,int yi,int xe,int ye);


int main()
{
	if(!mgpath(1,1,M,N))	
		cout<<"���Թ�����û�н�"<<endl; 
	return 0;
} 

//Ѱ�Ҳ����·�� 
bool mgpath(int xi,int yi,int xe,int ye)//���·��Ϊ��xi��yi��->(xe,ye) 
{
	int i,j,k,di,find;
	StType st;//����ջ �����洢·��  ���һ��ݣ����κ�λ���϶�����ԭ·���أ� 
	st.top=-1;//��ʼ��ջ��ָ��
	//��ʼ�������ջ
	st.top++;
	st.data[st.top].i=xi;
	st.data[st.top].j=yi;
	st.data[st.top].di=-1;
	mg[xi][yi]=-1;//���Ϊ-1 ��֤��̽�Ŀ������ڷ��鲻������·���ϵķ��� 
	while(st.top>-1)//ջ��Ϊ��ʱѭ��
	{
		//ȡջ������ 
		i=st.data[st.top].i;
		j=st.data[st.top].j;
		di=st.data[st.top].di;//������һ���޸�ջ��Ԫ�ص�diֵ��֮��Ӧ ������������� ����ֱ���ж��ϴ��жϵ���һ������ 
		if(i==xe&&j==ye)
		{
			cout<<"�Թ�·�����£�"<<endl;
			for(k=0;k<=st.top;k++)
			{
				printf("\t(%d,%d)",st.data[k].i,st.data[k].j);
				if((k+1)%5==0)//���5������ 
					cout<<endl;
			} 
			cout<<endl;
			return true;//�ҵ�һ��·���󷵻�true 
		}
		find=0;
		//���� find��Ǻ�switch whileѭ�����ʹ�ÿ��Զ�ʵ�����ζ��ĸ���λ����ֵ���ж� 
		//����һ�����߷���  
		while(di<4&&find==0)
		{
			di++;
			switch(di)
			{
				case 0:i=st.data[st.top].i-1;j=st.data[st.top].j;break;//0��ʾ�Ϸ�  ���Ҹı䵱ǰi,j����Ϊ�Ϸ��������� ���������ж� 
				case 1:i=st.data[st.top].i;j=st.data[st.top].j+1;break;//1��ʾ�ұ�
				case 2:i=st.data[st.top].i+1;j=st.data[st.top].j;break;//2��ʾ�·�
				case 3:i=st.data[st.top].i;j=st.data[st.top].j-1;break; //3��ʾ��� 
			}
			if(mg[i][j]==0)find=1;//�ҵ��¸��������ڷ��� �˳���ǰѭ�� ����ִ�е��ô�ѭ��ʱ �����ϴεķ�λ�ж��´η�λ 
		}
		//�ҵ��¸��������ڷ��� 
		if(find==1)
		{
			st.data[st.top].di=di;//�޸�ԭջ��Ԫ�ص�diֵ
			//��һ�����߷����ջ
			st.top++;
			st.data[st.top].i=i;st.data[st.top].j=j; 
			st.data[st.top].di=-1;
			mg[i][j]=1;//�����ظ��ߵ��÷��� 
		} 
		else//û��·���� ��ջ 
		{
			mg[st.data[st.top].i][st.data[st.top].j]=0;//��Ϊ֮ǰ�ǽ�ջ״̬ ����Ҫ��д��0 ������·������ 
			st.top--;//ջ��ָ���ƶ� ��ջ 
		}
	} 
	 
	return false; //��ʾû�п���·��������false 
} 



































