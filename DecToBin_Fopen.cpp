#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#define MAX 8
#include<string.h>
struct MyBin 
{
   int bin[MAX];
   int dec;
   long lbin;
   MyBin();
   MyBin(int);
   
   void DecToBin();
   void NotBin(int, int);
   void PrintOut();
   int FindFirstZero();
   void BinToDec();
	
}; 



int main() {
	
	//MyBin a;
	MyBin a;

	
	MyBin b;

	
	
	FILE *fptr=NULL;
	FILE *wptr=NULL;
	fptr=fopen("hw2.txt","r");
	wptr=fopen("result.txt","w");
	if(fptr!=NULL){
		MyBin answear;
		char p [2];
		while(!feof(fptr))
		{
			fscanf(fptr,"%ld",&a.lbin);
			
			fscanf(fptr,"%s",p);
			
			fscanf(fptr,"%ld",&b.lbin);
			
			
			a.BinToDec();
			b.BinToDec();
			
			if(!strcmp(p,"+")){	
				answear.dec=a.dec+b.dec;
				answear.DecToBin();
			}
			else{
				answear.dec=a.dec-b.dec;
				answear.DecToBin();
			}
			fprintf(wptr,"%ld %s %ld=",a.lbin,p,b.lbin);
			for(int i=MAX-1;i>=0;i--)
			{
				fprintf(wptr,"%d",answear.bin[i]);
			}
			fprintf(wptr,"(%d %s %d = %d)",a.dec,p,b.dec,answear.dec);
			fprintf(wptr,"\n");
			
			
		}
		fclose(fptr);
		fclose(wptr);
	}
	else{
		 printf("error");
	}

	
	//a.dec=254;
	//a.DecToBin();
	//a.PrintOut();
	

	
	
	return 0;
}
//=================================================
MyBin::MyBin()
{
	for(int i=0;i<MAX;i++)
		{bin[i]=0;}
	dec=0;	
} 
//=================================================
MyBin::MyBin(int val)
{
	for(int i=0;i<MAX;i++)
		bin[i]=0;
	dec=val;
	DecToBin(); 
} 
//=================================================
void MyBin::DecToBin()
{
	int temp=dec, i=0;
	if(dec<0) temp=dec*(-1);
	while(temp!=0)
	{
		bin[i]=temp%2;
		temp=temp/2;
		i++;
	}
	
	if(dec<0)
	{
		NotBin(0, MAX-1);
		
		int firstZero=FindFirstZero();
		NotBin(0, firstZero);
	} 
}
//=================================================
void MyBin::NotBin(int begin, int end)
{
	for(int i=begin;i<=end;i++)
	{
		if(bin[i]==0)
			bin[i]=1;
		else
			bin[i]=0;
	}
	
}
//=================================================
void MyBin::PrintOut()
{
	
	for(int i=MAX-1;i>=0;i--)
	{
		printf("%d",bin[i]);
	}
	printf("\n");
	
}
//=================================================
int MyBin::FindFirstZero() 
{
	int i=0;
	while(bin[i]!=0)
		i++;
	return i;
	
}
//=================================================
void MyBin::BinToDec()
{
	int i=0,rem;
	long tmpn;
	dec=0;
	tmpn=lbin;
	while(tmpn!=0){
		rem=tmpn%10;
		tmpn/=10;
		dec+=rem*pow(2,i);
		++i;
	}
	
}



