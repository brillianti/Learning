#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>    
 
char s[100],*c;
int  n,e,d,i,C,j,k=0,len;
int str[100],b[30];

unsigned gcd(unsigned a, unsigned b )
{

	if(a%b==0)
		return b;
    else
    	return gcd(b,a%b);
}

void Egcd(int a, int b,int &x, int &y)
{                               //ax-by=1
  if(b==0||a==0)
  {
	  x=1;
	  y=0;
	  return ;
  }
  if(a<b)
  {
	  Egcd(a,b%a,x,y);
	  x=(int)(b*y+1)/a;
  }
  else
  {
      Egcd(a%b,b,x,y);
	  y=(int)(a*x-1)/b;
  }
}

void RSA()
{
	int p,q,N,Y;
    printf("����������p��q:");
    scanf("%d %d",&p,&q);
    n=p*q;
    N=(p-1)*(q-1);
   //printf("n=%d N=%d\n",n,N);
   srand( (unsigned)time( NULL ) );          //��ʼ�������
   while(1)                                //�����������e��e��N����
   { 
     e=rand()%N;
//	 printf("e==%d\n",e);
	 if(e==0)
	  continue;
	 if(gcd(N,e)==1)
	{
	   break;
	}
   }
  //printf("e=%d\n",e);
  Egcd(e,N,d,Y);
 // printf("d=%d Y=%d\n",d,Y);
  printf("��ԿPU={e=%d,n=%d}\n",e,n);
  printf("˽ԿPR={d=%d,n=%d}\n",d,n);

}


void encrypt()            //���ܺ���
{
	len=strlen(s);
	//hgprintf("len=%d\n",len);

	 for(i=0;i<len;i++)           //ȥ��s[100]�еĿո�
  {
    if(s[i]<97||s[i]>122)
    {
		  b[k]=i;
		  k++;
        for(j=i;j<len-1;j++)
		{
		  s[j]=s[j+1];
		}
        len--;	
    }
  }
   s[len]='\0';    //������

	printf("�����ǣ�");
    for(i=0;i<len;i++)
	{   
	    C=1;
    	//printf("shiji=%d\n",s[i]-97);
		for(int j=0;j<e;j++)
		{
			C=(C*(s[i]-97))%n;
		//	printf("C=%ld\n",C);
		}
        str[i]=C;
		printf("%d  ",str[i]);
	}
	printf("\n");
}

  void decrypt()          //���ܺ���
{
	c=(char*)malloc(len*sizeof(int));

	 for(i=0;i<len;i++)      //ʵ�ֽ���
	 {  
	    C=1;
		for(int j=0;j<d;j++)
		{
			C=(C*(str[i]))%n;
		//	printf("C=%ld\n",C);
		}
	//	printf("C=%d\n",C);
        c[i]=C+97;
	}
    c[i] = '\0';
   // puts(c);
	for(int z=0;z<k;z++)         //�ӿո�
	{
	  for(i=0; i<len; i++) 
      {   	
		if (i==b[z])
		{
          for(j=len;j>i;j--)
		  {
		   c[j]=c[j-1];
		  }
		  c[i]=' ';
		  len++;
		  b[z+1]=b[z+1]+(z+1);
		  break;
		}
	  }
	}
   c[len] = '\0';
   printf("���ģ�");
   puts(c);
}

int function()//ϵͳ����ѡ��ҳ��
{
 int choice;
 printf("==============================================================\n");
 printf("                 ��ӭ����RSA�㷨                              \n");
 printf("                 1--����                                      \n");
 printf("                 2--����                                      \n");
 printf("                 3--�˳�                                      \n");
 printf("==============================================================\n");
 printf("������Ҫѡ��Ĺ��ܺţ�");
 scanf("%d",&choice);
 return choice;
}

int main()
{
  
  int function();
  int fc;
  printf("�������ʼ����(Сд)��");
  gets(s);
 // puts(s);
  RSA();                 //�ṩ˽Կ�͹�Կ
    while(1)
 {
  fc=function();
  if(fc==1)              //����
     encrypt();   
  else if(fc==2)          //����
	 decrypt();
  else if(fc==3)         
   break;
  else
    printf("�����������������룡/n");
  }
return 0;
}
