
/********************************************************

实现功能：按下正转正转90度，然后再按反转，回原位
使用芯片：AT89S52
晶振：11.0592MHZ
编译环境：Keil
作者：zhangxinchunleo
网站：www.ourhc.cn
淘宝店：汇诚科技 http://shop36330473.taobao.com

【声明】此程序仅用于学习与参考，引用请注明版权和作者信息！     
********************************************************/

#include<reg52.h> 
#define uchar unsigned char
#define uint unsigned int


/********************************************************
 						控制位定义
********************************************************/

sbit shi_neng=P1^0;  //	使能控制位
sbit fang_shi=P1^1;  //	工作方式控制位
sbit fang_xiang=P1^2;//	旋转方向控制位
sbit mai_chong=P1^3; // 脉冲控制位


sbit zrun=P2^0;	 	 //	正转选择
sbit frun=P2^1;	     //	反转选择

uint y=0;		  	 //设定转动脉冲数值
uchar bzw=1; 
/********************************************************
 						延时函数
********************************************************/
void delay(uint i)//延时函数
{
	uchar j,k;
	for(j=0;j<i;j++)
	for(k=0;k<250;k++);
}

/********************************************************
 						主函数
********************************************************/

main()
{

	shi_neng=0;  //	使能控制位
	fang_shi=1;  //	工作方式控制位
	fang_xiang=1;//	旋转方向控制位
	mai_chong=1; // 脉冲控制位
	
	while(1)
	{
	
	if(bzw==1){if(zrun==0){while(!zrun){shi_neng=1;y=48;fang_xiang=0;bzw=2;}}}	//如果正转按键按下，电机正转
	if(bzw==2){if(frun==0){while(!frun){shi_neng=1;y=48;fang_xiang=1;bzw=1;}}}	//如果反转按键按下，电机反转
	if(y>=1)   //执行转动条件
	{   y--;
		mai_chong=~mai_chong; //输出时钟脉冲
		delay(15);}
	if(y==1){shi_neng=0;}//如果y等于1，关闭使能。 //延时  (括号内数值越小，电机转动速度越快)
	}
	
}