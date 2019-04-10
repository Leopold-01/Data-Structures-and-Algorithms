#include<iostream>
#include<cstdio>
#define MaxSize 10000
#define M 8
#define N 8
using namespace std;

//迷宫数组，在原有迷宫基础上加一圈围墙 方便判断   
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


//定义方块类型 
typedef struct
{
	int i;//当前方块的行号 
	int j;//当前方块的列号 
	int di;//di是下一个可走的相邻方块的方位号 
}Box;

//定义顺序栈类型 
typedef struct
{
	Box data[MaxSize];
	int top;//栈顶指针 
}StType;

//寻找并输出路径 
bool mgpath(int xi,int yi,int xe,int ye);


int main()
{
	if(!mgpath(1,1,M,N))	
		cout<<"该迷宫问题没有解"<<endl; 
	return 0;
} 

//寻找并输出路径 
bool mgpath(int xi,int yi,int xe,int ye)//求解路径为（xi，yi）->(xe,ye) 
{
	int i,j,k,di,find;
	StType st;//定义栈 用来存储路径  并且回溯（在任何位置上都能沿原路返回） 
	st.top=-1;//初始化栈顶指针
	//初始化方块进栈
	st.top++;
	st.data[st.top].i=xi;
	st.data[st.top].j=yi;
	st.data[st.top].di=-1;
	mg[xi][yi]=-1;//标记为-1 保证试探的可走相邻方块不是已走路径上的方块 
	while(st.top>-1)//栈不为空时循环
	{
		//取栈顶方块 
		i=st.data[st.top].i;
		j=st.data[st.top].j;
		di=st.data[st.top].di;//下面有一句修改栈顶元素的di值与之对应 所以是有意义的 可以直接判断上次判断的下一个方向 
		if(i==xe&&j==ye)
		{
			cout<<"迷宫路径如下："<<endl;
			for(k=0;k<=st.top;k++)
			{
				printf("\t(%d,%d)",st.data[k].i,st.data[k].j);
				if((k+1)%5==0)//输出5个后换行 
					cout<<endl;
			} 
			cout<<endl;
			return true;//找到一条路径后返回true 
		}
		find=0;
		//巧妙 find标记和switch while循环结合使用可以对实现依次对四个方位方块值的判断 
		//找下一个可走方块  
		while(di<4&&find==0)
		{
			di++;
			switch(di)
			{
				case 0:i=st.data[st.top].i-1;j=st.data[st.top].j;break;//0表示上方  并且改变当前i,j坐标为上方方块坐标 进入下面判断 
				case 1:i=st.data[st.top].i;j=st.data[st.top].j+1;break;//1表示右边
				case 2:i=st.data[st.top].i+1;j=st.data[st.top].j;break;//2表示下方
				case 3:i=st.data[st.top].i;j=st.data[st.top].j-1;break; //3表示左边 
			}
			if(mg[i][j]==0)find=1;//找到下个可走相邻方块 退出当前循环 若再执行到该次循环时 接着上次的方位判断下次方位 
		}
		//找到下个可走相邻方块 
		if(find==1)
		{
			st.data[st.top].di=di;//修改原栈顶元素的di值
			//下一个可走方块进栈
			st.top++;
			st.data[st.top].i=i;st.data[st.top].j=j; 
			st.data[st.top].di=-1;
			mg[i][j]=1;//避免重复走到该方块 
		} 
		else//没有路径走 退栈 
		{
			mg[st.data[st.top].i][st.data[st.top].j]=0;//因为之前是进栈状态 所以要重写置0 让其他路径可走 
			st.top--;//栈顶指针移动 退栈 
		}
	} 
	 
	return false; //表示没有可走路径，返回false 
} 



































