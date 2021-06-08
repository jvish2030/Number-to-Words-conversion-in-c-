#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
string s1[9]={"one","two","three","four","five","six","seven","eight","nine"};
string s2[9]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","ninteen"};
string s3[9]={"ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninty"};
string s4[9]={"hundred","thousand","million","billion"};
int n,n1,r,count=0,i=0,j=0,k=0,temp;
int s[50],a[50];


void count0()
{
		if(count==3)
			cout<<s4[k]<<" ";
		else if(count==4)
			cout<<s4[1]<<" ";
		else{
			temp=a[k];
			cout<<s3[temp-1]<<" ";
		}
}
void count1(){
	temp=a[k];
	cout<<s1[temp-1]<<" ";
}
void count2(){
		if(a[k]==1)
		{
			k++;
			temp=a[k];
			cout<<s2[temp-1]<<" ";			
		}
		else
		{
			if(a[k]!=0)
			{
				temp=a[k];
				cout<<s3[temp-1]<<" ";
			}
			k++;
			if(a[k]!=0)
			{
				temp=a[k];
				cout<<s1[temp-1]<<" ";
			}
		}	
}
void count3()
{	
	if(a[k]!=0)
	{
		temp=a[k];
		cout<<s1[temp-1]<<" "<<s4[0]<<" ";
	}
	k++;
	if(a[k]!=0)
	{
		count2();
	}
	k++;
	if(a[k]!=0)
	{
		count1();
	}			
}
void count45()
{
	if(count==4)
	{
		if(a[1]==0 && a[2]==0 && a[3]==0)
		{
			 count1();
		 	cout<<s4[1]<<" ";
		}
		else
		{
		if(a[k]!=0)
		{
			count1();
			cout<<s4[1]<<" ";
		}
		k++;
		count3();
		}
	}
	else
	{
		if(a[2]==0 && a[3]==0 && a[4]==0)
		{
			 count2();
		 	cout<<s4[1]<<" ";
		}
		else
		{
			if(a[k]!=0)
			{
				count2();
				cout<<s4[1]<<" ";
				k++;
				count3();
			}
			else
			{
				k++;
				count45();
			}
		}
	}
}
void count6()
{
	if(a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0 && a[5]==0)
	{
		count1();
		cout<<s4[0]<<" ";
		cout<<s4[1]<<" ";
	}
	else
	{
		if(a[k]!=0)
		{	
			count1();cout<<s4[0]<<" ";
		}
		k++;
		if(a[k]!=0)
		{
			count2();	
		}
		else
		{
			k++;
			if(a[k]!=0)	
			count1();
		}
		k++;
		cout<<s4[1]<<" ";
		count3();
		
	}
}
void count78()
{
	if(count==7)
	{
		if(a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0 && a[5]==0&& a[6]==0)
		{
			count1();
			cout<<s4[2]<<" ";
		}
		else
		{
			if(a[k]!=0)
			{
				count1();
				cout<<s4[2]<<" ";
				k++;
				count6();
			}
			else
			{
				k++;
				count6();
			}
		}
	}
	else
	{
		if(count==8)
		{
			count2();cout<<s4[2]<<" ";
			k++;
			count6();
		}
		if(count==9)
		{
				count1();
			cout<<s4[0]<<" ";
			k++;
				count2();
			cout<<s4[2]<<" ";
			k++;
				count6();		
		}
	}
}
void count10()
{
	if(a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0 && a[5]==0&& a[6]==0&& a[7]==0&& a[8]==0&& a[9]==0)
	{
	count1();cout<<s4[3]<<" ";
	}
}
int main()
{
	while(1)
	{
	n=n1=r=count=i=j=k=temp=0;
	cout<<"enter number\n";
	cin>>n;
	n1=n;
	while(n!=0)
	{
		r=n%10;
		s[i]=r;
		n=n/10;
		i++;
		count++;
	}
	i--;
	while(i>=0)
	{
		a[j]=s[i];
		i--;j++;
	}
	if(count==1)
	count1();
	else if(n1==10 ||n1==20 ||n1==30 ||n1==40 ||n1==50 ||n1==60 ||n1==70 ||n1==80 ||n1==90 || n1==100)
		count0();
	else if(count==2)
		count2();
	else if(count==3)
		count3();
	else if(count==4 || count==5)
		count45();
	else if(count==6)
		count6();
	else if(count==7|| count==8 || count==9)
		count78();
	else if(count==10)
		count10();
	else
	{
		exit(1);
		return 0;
	}
	char e;
	cout<<"......Exit(y/n) ";
	cin>>e;
	if(e=='y')
		exit(1);
    }
}

