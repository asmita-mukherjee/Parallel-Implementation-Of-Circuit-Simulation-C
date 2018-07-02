
#include<stdio.h>
#include<stdlib.h>
float* y_modify(float y[],float i[],int k,int n);
float * RK_ODE(float x[],float y[],float ((*func_arr[])(float x_val,float y[])),int n)
{
	float x_val;
 //int n;
	//FILE *temp=fopen("RK_data","w");
	float *k1,*k2,*k3,*k4;
float h;
h=0.001;
int i,range,j;
range=(x[1]-x[0])/h;
x_val=x[0];
//n=sizeof(y)/sizeof(y[0]);
//printf("%d\n",n );
FILE *temp[n];
char file_name[n][50];
for(i=0;i<n;i++)
{ printf("Enter the file name of equation%d \n",i+1);
	scanf("%s",file_name[i]);
	temp[i]=fopen(file_name[i],"w");
}
k1=(float *)malloc(sizeof(float)*n);
k2=(float *)malloc(sizeof(float)*n);
k3=(float *)malloc(sizeof(float)*n);
k4=(float *)malloc(sizeof(float)*n);
//for(i=0;i<range;i++)
while(x_val<x[1])
{
for(j=0;j<n;j++)
{  
k1[j]=h*((*func_arr[j])(x_val,y)); 
}
for(j=0;j<n;j++)
{  

k2[j]=h*((*func_arr[j])(x_val+h/2,y_modify(y,k1,2,n)));
}
for(j=0;j<n;j++)
{  
//k3[j]=h*((*func_arr[j])(x_val+h/2,y_modify(y,k2[j]/2)));
k3[j]=h*((*func_arr[j])(x_val+h/2,y_modify(y,k2,2,n)));
for(j=0;j<n;j++)
{  
	//k4[j]=h*((*func_arr[j])(x_val+h,y_modify(y,k3[j]))); 
k4[j]=h*((*func_arr[j])(x_val+h,y_modify(y,k3,1,n))); 
}
for(j=0;j<n;j++)
{
	y[j]=y[j]+(1.0/6.0)*(k1[j]+2*k2[j]+2*k3[j]+k4[j]);
//fprintf(temp, "%f %f \n",x_val,y[j]);
	fprintf(temp[j],"%f %f \n",x_val,y[j]);
//printf("the value of y%d at %f is %f\n",j+1,x_val,y[j]);
}
x_val=x_val+h;
//printf("--------------------------------------------\n");
}
for(j=0;j<n;j++)
{
	printf("the file name for equation%d is %s",j+1,file_name[j]);
}
//float* z;
//z=(float*)malloc(sizeof(float)*n);
//z=y;
//return z;
}
float* y_modify(float y[],float i[],int k,int n)
{
	//int n;
	//n=sizeof(y)/sizeof(y[0]);
float z[n];
int j;
for(j=0;j<n;j++)
{
	z[j]=y[j]+(i[j]/k);
}
float *z1;
z1=(float *)malloc(sizeof(float)*n);
z1=z;
	//return 0;
return z1;
}
