#include <iostream>
#include <map>
#include <algorithm>
#include<string>
#include <iterator> 
using namespace std;
	
void iterate_over_record(auto start,auto end)
{
	cout<<"Name"<<"   "<<"Marks"<<endl;
	for(auto i=start;i!=end;i++)
	{
		cout<<i->first<<"     "<<i->second<<endl;
	 } 
	cout<<endl;
}
void erase_pair(map<int,string> &record,auto position)
{
	record.erase(position); 
}
bool Is_empty(map<int,string> &record)
{
	return record.empty();
}

int main()
{
	/*  Each element has a key value and a mapped value. No two mapped values can have same key values.
		using key for marks obtained in a test out of 100 and 
		value for name of student  */
	map<int,string> record;
	record.insert({99,"Saurabh"});             // O(log(n)) --average
	record.insert({50,"vikas"});
	record.insert({78,"watson"});
	record.insert({65,"steve"});
	record.insert({50,"suresh"});              // no duplicate key allowed
 	// pairs are stored in increasing order of key value 
	cout<<"Size of record: "<<record.size()<<endl;
	cout<<"original map record: "<<endl;  
	iterate_over_record(record.begin(),record.end());
	
	cout<<"Student with marks just above 33 passing marks: "<<record.upper_bound(33)->second<<endl;
	
	cout<<"Student with marks 99: "<<record.find(99)->second<<endl;
	cout<<endl;
	
	erase_pair(record,record.find(65));
	
	cout<<"Size of record: "<<record.size()<<endl;	
	cout<<"Mapped record after erasing some pair: "<<endl; 
	iterate_over_record(record.begin(),record.end());	
	
	cout<<"Is map container empty: "<<Is_empty(record)<<endl;
	record.clear();
	cout<<"Is map container empty: "<<Is_empty(record)<<endl;	
	
	return 0;
}
