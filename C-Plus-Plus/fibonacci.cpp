#include<iostream.h>
#include<conio.h>

int fibonacci(int n)
{
 if ((n==1)||(n==0))
 {
  return n;
 }
 else
 {
  return (fibonacci(n-1)+fibonacci(n-2));
 }
}
int main()
{
 int n,i=0;
 clrscr();
 cout<<"\n input the no. of terms for fibonacci series";
 cin>>n;
 while(i<n)
 {
  cout<<" "<<fibonacci(i);
  i++;
 }
 return 0;
}
