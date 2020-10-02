#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
template<class t>
class Quick_sort
{
public:
	t a[500];
	int count;
	int n;
	void input();
	void display();
	int qsort(t a[], int p, int r);
	int partition(t a[], int p,  int r);
};
template <class t>
void Quick_sort<t>::input()
{
	int i;
	cout <<"\nEnter the number of elements"<< endl;
	cin >> n;
	for (i = 1;i <= n;i++)
		a[i] = rand() % 100;
}
template<class t>
void Quick_sort<t>::display()
{
	for (int i = 1;i <= n;i++)
		cout << a[i] <<" ";
}
template<class t>
int Quick_sort<t>::qsort(t a[], int p, int r)
{int q;
	if (p < r)
	{
		 q = partition(a,p,r);
		qsort(a,p,q-1);
		qsort(a,q+1,r);
	}
	return count;
}
template<class t>
int Quick_sort<t>::partition(t a[], int p, int r)
{
	int x, i, j, temp;
	x = a[r];
	i = p - 1;
	for (j = p;j <= r - 1;j++)
	{
		if (a[j] <= x)
		{
			i = i + 1;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			
	
		}
		count++;
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	
	return i+1;
}
int main()
{
	ofstream f("quickSort.csv");
	int c;
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		Quick_sort<int> q;
		q.input();
		cout <<"\nThe elements of the array are: ";
		q.display();
		q.count = 0;
		c = q.qsort(q.a, 1, q.n);
		cout <<"\nAfter sorting:"<< endl;
		q.display();
		if (f)
		{
			f << q.n <<","<< c;
			f << endl;
		}
		cout <<"\nDo you wish to continue?(y/n)";
		cin >> ch;
	}
	f.close();
	return 0;
}
