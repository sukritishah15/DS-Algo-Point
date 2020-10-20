// This arena belongs to WhiteDeath99!

/*

Given an array of N integers and Q queries to be processed.
There are two types of queries

- 1 idx new_val - Add new_val to element at index idx
- 2 start end - Print array range sum from [start, end]

Problem Tag - BIT or Fenwick Tree

Constraints

N = [1, 1e5]
Q = [1, 1e5]

*/

#include<bits/stdc++.h>
using namespace std;

int tree[100005],ar[100005];
int n;
bool flag=false;

void update(int idx, int val)
{
    while(idx<=n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int fenwick(int idx)
{
    int total=0;
    while( idx>0 )
    {
        total += tree[idx];
        idx = idx - (idx & -idx);
    }
    return total;
}

int sum(int l, int r)
{
    return fenwick(r) - fenwick(l-1);
}

int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
        update(i,ar[i]);
    }

    flag = true;

    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;

        if(type == 1)
        {
            int index, new_val;
            cin>>index>>new_val;

            update(index, new_val);
        }
        else if(type == 2)
        {
            int start, end;
            cin>>start>>end;
            cout<<sum(start,end)<<endl;
        }
    }
}

/*

Sample Input
10
1 2 3 4 5 6 7 8 9 10
4
2 2 4
2 10 10
1 10 0
2 1 10

Sample Output
9
10
55

Explanation
First Query of type 2 will contain sum = 2 + 3 + 4 = 9
Second Query of type 2 will contain sum = 10

Time Complexity
Preprocessing - O(Nlog(N))
1-Update Query - O(log(N))
1-Sum Query - O(log(N))

Space Complexity - O(N)

*/