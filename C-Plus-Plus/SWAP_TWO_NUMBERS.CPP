#include<conio.h>
#include<iostream.h>
void main()
{
clrscr();
int n,m;
cout<<"\n Enter two numbers to be swaped";
cin>>n>>m;
cout<<"\n n= "<<n;
cout<<"\n m= "<<m;
//logic for swapping
n=n+m;
m=n-m;
n=n-m;
//swapping done
cout<<"\n The numbers after swapping are:"<<"\n n= "<<n<<"\n m= "<<m;
getch();
}