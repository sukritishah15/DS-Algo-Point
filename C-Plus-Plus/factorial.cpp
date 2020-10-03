#include<iostream.h>
#include<conio.h>
int fact(int);
void main()
{
 int n,f;
 clrscr();
 cin>>n;
 f=fact(n);
 cout<<f;
}
int fact(int n)
{
 if (n==0)
 {
  return 1;
 }
 else
 {
  return (n*(fact(n-1)));
 }
}
