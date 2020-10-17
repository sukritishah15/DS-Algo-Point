class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.pos = None

    def insert(self, data):
        newNode = Node(data)

        if self.head == None:
            self.head = newNode
            self.pos = newNode
        else:
            tmp = self.pos.next
            self.pos.next = newNode
            self.pos = newNode
            if tmp != None:
                newNode.next = tmp

    def delete(self):
        if self.pos == self.head:
            self.pos = self.pos.next
            del self.head
            self.head = self.pos
        else:
            tmp = self.head
            while tmp.next != self.pos:
                tmp = tmp.next
            tmp.next = self.pos.next
            del self.pos
            self.pos = tmp

    def reset(self):
        self.pos = self.head

    def advance(self):
        if self.pos != None:
            self.pos = self.pos.next

    def out_of_list(self):
        if self.pos == None:
            return True
        else:
            return False

    def pos_position(self):
        if not (self.out_of_list()):
          return self.pos.data
        else:
          return "pos is out of list"
    
    def print_list(self):
        if self.head == None:
            print("List is empty")
        else:
            tmp = self.head
            while tmp != None:
                print(tmp.data)
                tmp = tmp.next


run = True
sll = SinglyLinkedList()
while run:
    print( "\ni  [insert]  insert element")
    print( "d  [delete]  delete element")
    print( "o  [out]     out_of_list ?")
    print( "p  [pos]     current position of pos")
    print( "r  [reset]   pos-pointer")
    print( "a  [advance] pos-pointer")
    print( "pr [print]   print list")
    print( "q  [quit]    program")
    choice = input()

    if choice == "i":
        num = input("Enter Data for insertion: ")
        sll.insert(num)

    elif choice == "d":
        sll.delete()

    elif choice == "o":
        print(sll.out_of_list())

    elif choice == "r":
        sll.reset()

    elif choice == "a":
        sll.advance()

    elif choice == "p":
        print(sll.pos_position())

    elif choice == "q":
        run = False

    elif choice == "pr":
        sll.print_list()

    else:
        print("Invalid Input")



"""
Sample I/O:

i  [insert]  insert element
d  [delete]  delete element
o  [out]     out_of_list ?
p  [pos]     current position of pos
r  [reset]   pos-pointer
a  [advance] pos-pointer
pr [print]   print list
q  [quit]    program
i (Userinput)
Enter Data for insertion: 10

i  [insert]  insert element
d  [delete]  delete element
o  [out]     out_of_list ?
p  [pos]     current position of pos
r  [reset]   pos-pointer
a  [advance] pos-pointer
pr [print]   print list
q  [quit]    program
i (Userinput)
Enter Data for insertion: 20

i  [insert]  insert element
d  [delete]  delete element
o  [out]     out_of_list ?
p  [pos]     current position of pos
r  [reset]   pos-pointer
a  [advance] pos-pointer
pr [print]   print list
q  [quit]    program
pr (Userinput)
10
20

i  [insert]  insert element
d  [delete]  delete element
o  [out]     out_of_list ?
p  [pos]     current position of pos
r  [reset]   pos-pointer
a  [advance] pos-pointer
pr [print]   print list
q  [quit]    program
p (Userinput)
20

i  [insert]  insert element
d  [delete]  delete element
o  [out]     out_of_list ?
p  [pos]     current position of pos
r  [reset]   pos-pointer
a  [advance] pos-pointer
pr [print]   print list
q  [quit]    program
a (Userinput)

i  [insert]  insert element
d  [delete]  delete element
o  [out]     out_of_list ?
p  [pos]     current position of pos
r  [reset]   pos-pointer
a  [advance] pos-pointer
pr [print]   print list
q  [quit]    program
o (Userinput)
True

i  [insert]  insert element
d  [delete]  delete element
o  [out]     out_of_list ?
p  [pos]     current position of pos
r  [reset]   pos-pointer
a  [advance] pos-pointer
pr [print]   print list
q  [quit]    program
r (Userinput)

i  [insert]  insert element
d  [delete]  delete element
o  [out]     out_of_list ?
p  [pos]     current position of pos
r  [reset]   pos-pointer
a  [advance] pos-pointer
pr [print]   print list
q  [quit]    program
p (Userinput)
10

i  [insert]  insert element
d  [delete]  delete element
o  [out]     out_of_list ?
p  [pos]     current position of pos
r  [reset]   pos-pointer
a  [advance] pos-pointer
pr [print]   print list
q  [quit]    program
d (Userinput)

i  [insert]  insert element
d  [delete]  delete element
o  [out]     out_of_list ?
p  [pos]     current position of pos
r  [reset]   pos-pointer
a  [advance] pos-pointer
pr [print]   print list
q  [quit]    program
pr (Userinput)
20

i  [insert]  insert element
d  [delete]  delete element
o  [out]     out_of_list ?
p  [pos]     current position of pos
r  [reset]   pos-pointer
a  [advance] pos-pointer
pr [print]   print list
q  [quit]    program
p (Userinput)
20

i  [insert]  insert element
d  [delete]  delete element
o  [out]     out_of_list ?
p  [pos]     current position of pos
r  [reset]   pos-pointer
a  [advance] pos-pointer
pr [print]   print list
q  [quit]    program
q (Userinput)

Time Complexity:
Insert: O(1)
Delete: O(N)
PrintList: O(N)
Everything Else: O(1)

"""
