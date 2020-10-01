#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

// creating a node

struct nod {
   int info;
   struct nod *n;
   struct nod *p;
};
int count = 0;

//creating class

class CircularDoublyLL {
   public:
      nod*start,*last;
      nod *create_node(int);
      void insert_begin();
      void insert_end();
      void insert_pos();
      void delete_pos();
      void search();
      void update();
      void display();
      void reverse();
      circulardoublylist() {
         start = NULL;
         last = NULL;
      }
};
int main() {
   int c;
   CircularDoublyLL cdl;
   while (1)                              //perform switch operation
	 {
      cout<<"1.Insert at Beginning"<<endl;
      cout<<"2.Insert at End"<<endl;
      cout<<"3.Insert at Position"<<endl;
      cout<<"4.Delete at Position"<<endl;
      cout<<"5.Update Node"<<endl;
      cout<<"6.Search Element"<<endl;
      cout<<"7.Display List"<<endl;
      cout<<"8.Reverse List"<<endl;
      cout<<"9.Exit"<<endl;
      cout<<"Enter your choice : ";
      cin>>c;
      switch(c) {
         case 1:
            cdl.insert_begin();
         break;
         case 2:
            cdl.insert_end();
         break;
         case 3:
            cdl.insert_pos();
         break;
         case 4:
            cdl.delete_pos();
         break;
         case 5:
            cdl.update();
         break;
         case 6:
            cdl.search();
         break;
         case 7:
            cdl.display();
         break;
         case 8:
            cdl.reverse();
         break;
         case 9:
            exit(1);
         default:
            cout<<"Wrong choice"<<endl;
      }
   }
   return 0;
}
nod* CircularDoublyLL::create_node(int v) {
   count++;
   struct nod *t;
   t = new(struct nod);
   t->info = v;
   t->n = NULL;
   t->p = NULL;
   return t;
}
void CircularDoublyLL::insert_begin() {
   int v;
   cout<<endl<<"Enter the element to be inserted: ";
   cin>>v;
   struct nod *t;
   t = create_node(v);
   if (start == last && start == NULL) {
      cout<<"Element inserted in empty list"<<endl;
      start = last = t;
      start->n = last->n = NULL;
      start->p = last->p = NULL;
   } else {
      t->n = start;
      start->p = t;
      start = t;
      start->p = last;
      last->n = start;
      cout<<"Element inserted"<<endl;
   }
}
void CircularDoublyLL::insert_end() {
   int v;
   cout<<endl<<"Enter the element to be inserted: ";
   cin>>v;
   struct nod *t;
   t = create_node(v);
   if (start == last && start == NULL) {
      cout<<"Element inserted in empty list"<<endl;
      start = last = t;
      start->n= last->n = NULL;
      start->p = last->p= NULL;
   } else {
      last->n= t;
      t->p= last;
      last = t;
      start->p = last;
      last->n= start;
   }
}
void CircularDoublyLL::insert_pos() {
   int v, pos, i;
   cout<<endl<<"Enter the element to be inserted: ";
   cin>>v;
   cout<<endl<<"Enter the position of element inserted: ";
   cin>>pos;
   struct nod *t, *s, *ptr;
   t = create_node(v);
   if (start == last && start == NULL) {
      if (pos == 1) {
         start = last = t;
         start->n = last->n = NULL;
         start->p = last->p = NULL;
      } else {
         cout<<"Position out of range"<<endl;
         count--;
         return;
      }
   } else {
      if (count < pos) {
         cout<<"Position out of range"<<endl;
         count--;
         return;
      }
      s = start;
      for (i = 1;i <= count;i++) {
         ptr = s;
         s = s->n;
         if (i == pos - 1) {
            ptr->n = t;
            t->p= ptr;
            t->n= s;
            s->p = t;
            cout<<"Element inserted"<<endl;
            break;
         }
      }
   }
}
void CircularDoublyLL::delete_pos() {
   int pos, i;
   nod *ptr, *s;
   if (start == last && start == NULL) {
      cout<<"List is empty, nothing to delete"<<endl;
      return;
   }
   cout<<endl<<"Enter the position of element to be deleted: ";
   cin>>pos;
   if (count < pos) {
      cout<<"Position out of range"<<endl;
      return;
   }
   s = start;
   if(pos == 1) {
      count--;
      last->n = s->n;
      s->n->p = last;
      start = s->n;
      free(s);
      cout<<"Element Deleted"<<endl;
      return;
   }
   for (i = 0;i < pos - 1;i++ ) {
      s = s->n;
      ptr = s->p;
   }
   ptr->n = s->n;
   s->n->p = ptr;
   if (pos == count) {
      last = ptr;
   }
   count--;
   free(s);
   cout<<"Element Deleted"<<endl;
}
void CircularDoublyLL::update() {
   int v, i, pos;
   if (start == last && start == NULL) {
      cout<<"The List is empty, nothing to update"<<endl;
      return;
   }
   cout<<endl<<"Enter the position of node to be updated: ";
   cin>>pos;
   cout<<"Enter the new value: ";
   cin>>v;
   struct nod *s;
   if (count < pos) {
      cout<<"Position out of range"<<endl;
      return;
   }
   s = start;
   if (pos == 1) {
      s->info = v;
      cout<<"Node Updated"<<endl;
      return;
   }
   for (i=0;i < pos - 1;i++) {
      s = s->n;
   }
   s->info = v;
   cout<<"Node Updated"<<endl;
}
void CircularDoublyLL::search() {
   int pos = 0, v, i;
   bool flag = false;
   struct nod *s;
   if (start == last && start == NULL) {
      cout<<"The List is empty, nothing to search"<<endl;
      return;
   }
   cout<<endl<<"Enter the value to be searched: ";
   cin>>v;
   s = start;
   for (i = 0;i < count;i++) {
      pos++;
      if (s->info == v) {
         cout<<"Element "<<v<<" found at position: "<<pos<<endl;
         flag = true;
      }
      s = s->n;
   }
   if (!flag)
      cout<<"Element not found in the list"<<endl;
}
void CircularDoublyLL::display() {
   int i;
   struct nod *s;
   if (start == last && start == NULL) {
      cout<<"The List is empty, nothing to display"<<endl;
      return;
   }
   s = start;
   for (i = 0;i < count-1;i++) {
      cout<<s->info<<"<->";
      s = s->n;
   }
   cout<<s->info<<endl;
}
void CircularDoublyLL::reverse() {
   if (start == last && start == NULL) {
      cout<<"The List is empty, nothing to reverse"<<endl;
      return;
   }
   struct nod *p1, *p2;
   p1 = start;
   p2 = p1->n;
   p1->n = NULL;
   p1->p= p2;
   while (p2 != start) {
      p2->p = p2->n;
      p2->n = p1;
      p1 = p2;
      p2 = p2->p;
   }
   last = start;
   start = p1;
   cout<<"List Reversed"<<endl;
}


/*
Operation

Time Complexity:                          Worst Case                       Average Case

Insert at beginning or end                  O(1)                              O(1)

Delete at beginning or end                  O(1)                              O(1)

Search                                      O(n)                              O(n)

Access                                      O(n)                              O(n)


OUTPUT -

.Insert at Beginning
2.Insert at End
3.Insert at Position
4.Delete at Position
5.Update Node
6.Search Element
7.Display List
8.Reverse List
9.Exit
Enter your choice : 1

Enter the element to be inserted: 7
Element inserted in empty list












*/

