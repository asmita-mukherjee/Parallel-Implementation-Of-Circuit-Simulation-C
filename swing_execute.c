#define pi 3.14159
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Sys_RK.h"
float **k;
float *theta;

int n1;
float f1(float x,float y[]);
float f2(float x,float y[]);
float f3(float x,float y[]);
float f4(float x,float y[]);
//float 1=pi/180;
int n;
float *p;
float *s;
int main()
{//float *k;
		int i,j;
	printf("enter the number of equations\n");
	scanf("%d",&n);
	float *y;
y=(float *)malloc(sizeof(float)*n);
//k=(float *)malloc(sizeof(float)*n);
p=(float *)malloc(sizeof(float)*n/2);
float (*func[])(float,float *) = {f1,f2,f3,f4};
for(i=0;i<n;i++)
	{
printf("the initial value of y of equation %d",i+1);
scanf("%f",&y[i]);
}
for(i=0;i<n/2;i++)
	{
printf("the value of p of machine %d",i+1);		
scanf("%f",&p[i]);
}
k=(float **)malloc(sizeof(float *)*n/2);
k[0]=(float *)malloc(sizeof(float)*n/2*n/2);
	for(i=0;i<n/2;i++){
		k[i]=(*k+n/2*i);}
printf("enter the k matrix row wise\n");
for(i=0;i<n/2;i++)
{
	for(j=0;j<n/2;j++)
	{
		scanf("%f",&k[i][j]);
	}
}	
for(i=0;i<n/2;i++)
{
	for(j=0;j<n/2;j++)
	{
		printf("%f\t",k[i][j]);
	}
}	

float x[]={0,500};
//float x[]={0,1}; 

s=(float*)malloc(sizeof(float)*n1);
	int i1,j1;	

n1=n/2;	
RK_ODE(x,y,(func),n);
//RK_ODE_adaptive2(x,y,(func),n);
//float sum(int n)

}

float f1(float x,float y[])
{
	float result=y[1]/1;
	return result;
}
float f2(float x,float y[])
{
	int j1;
	float s=0.0;
	float a=0.1;
int k1=0;
	//for(i1=0;i1<n1;i1++)
	//{s[i1]=0.0;
		for(j1=0;j1<n1;j1++)
		{

//printf("%f",k[0][1]);
		s=s+k[0][j1]*sin((y[0]-y[k1]));
			//fprintf("%f",sin((y[0]-y[k1])) );
			k1=k1+2;
			}
	float result=p[0]-s-a*(y[1]/1);	
if(isnan(result)){
int i;
for (i=0;i<n;i++)
{
	printf("%f\t\n",y[i]);
}
printf("f2");
return;
}

	return result;
}

float f4(float x,float y[])
{int j1;
	int k1=0;
	float s=0.0;
	float a=0.1;
	for(j1=0;j1<n1;j1++)
		{
		s=s+k[1][j1]*sin((y[2]-y[k1]));
			k1=k1+2;
			}
	float result=p[1]-s-a*(y[3]/1);	
	if(isnan(result)){
		int i;
for (i=0;i<n;i++)
{
	printf("%f\t\n",y[i]);
}
printf("f4");
return;
}
	return result;
}
float f3(float x,float y[])
{
	float result=y[3];
	return result;
}
