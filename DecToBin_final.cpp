#include<stdio.h> 
#include<stdlib.h> 

#define MAX 8

struct MyBin 
{
   int bin[MAX];
   int dec;
   
   MyBin();
   MyBin(int);
   void DecToBin();
   void NotBin(int, int);
   void PrintOut();
   int FindFirstZero();
	
}; 



int main() {
	
	//MyBin a;
	MyBin a=54;
	a.PrintOut();
	
	MyBin b=-50;
	b.PrintOut();
	
	//a.dec=254;
	//a.DecToBin();
	//a.PrintOut();
	

	
	
	return 0;
}
//=================================================
MyBin::MyBin()
{
	for(int i=0;i<MAX;i++)
		bin[i]=0;	
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
	PrintOut();
	if(dec<0)
	{
		NotBin(0, MAX-1);
		PrintOut();
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




