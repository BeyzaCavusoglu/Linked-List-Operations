#include<iostream>
#include<string>
using namespace std;
#define SIZE 4
// A PROGRAM FOR MAKÝNG SOME OPERATIONS WITH LINKED LISTS LIKE ADD,DELETE,MERGE,PRINT.
struct complexNode {
	int num;
	string type; // Can be "S"(standard) or "M"(merged)
	complexNode *nexts[SIZE];
	complexNode(int n = 0)
		: num(n) {
			for (int i = 0; i < SIZE; i++)
				nexts[i] = NULL;
			type = "S";}};

class linked_list { //class for linked list implementations
private:
	complexNode *head;
	int indexNumber;
public:
	complexNode *getHead() { //for returning to the head(getting the head)
		return head;}
	complexNode *setHead(complexNode *newNode) {  //for changing the head value
		head = newNode;
		return head;}
	linked_list(int number) {
		head = NULL;
		indexNumber = number;}

	void addToEnd(int &element)  //for adding element to the end of the selected list
	{
		complexNode *ptr = head;
		complexNode *temp = new complexNode(element);    //the one which will be added to end holds the element value given by user
		if (head == nullptr) //If list is empty
		{
			head = temp;}
		else {
			while (ptr->nexts[indexNumber] != NULL) {
				ptr = ptr->nexts[indexNumber]; }  // keep going to last node
			ptr->nexts[indexNumber] = temp; }       //add to the last node
		cout<<endl;}

	void Delete(int &element)// for deleting element given by user from the selected list
	{
		complexNode *prevptr = NULL;
		complexNode *ptr = head;

		if (head == nullptr) //If list is empty
		{
			cout << "The list is empty\n\n";
			return;
		}
		while (ptr->num != element &&
			ptr->nexts[indexNumber] != NULL)  //if the element is not found && not the end of list
		{
			prevptr = head;
			ptr = prevptr->nexts[indexNumber];    //continue searching
		}
		if (ptr->num != element)  //if the element is not found
		{
			cout << "The element could not found.";
		}
		else {    //if the element is found
			if (ptr->type == "S") {
				if (ptr == head)   //if element found at the first node
				{
					prevptr = ptr;
					ptr = ptr->nexts[indexNumber];
					delete prevptr;
					head = ptr;
				}
				if (ptr != head && ptr->nexts[indexNumber] != NULL)  //if element found at the middle (not 1st of last)
				{
					prevptr->nexts[indexNumber] = ptr->nexts[indexNumber];
					delete ptr;
				}
				if (ptr->nexts[indexNumber] == NULL) //if element found at last node
				{
					prevptr->nexts[indexNumber] = NULL;
					delete ptr;	}}
			else // if node to be deleted is a merged one
			{
				if (ptr == head)   //if element found at the first node
				{
					ptr->nexts[indexNumber] = NULL;}
				else if (ptr != head && ptr->nexts[indexNumber] != NULL)  //if element found at the middle (not 1st of last)
				{
					prevptr->nexts[indexNumber] = ptr->nexts[indexNumber];
					ptr->nexts[indexNumber] = NULL;	}
				else if (ptr->nexts[indexNumber] == NULL) //if element found at last node
				{
					prevptr->nexts[indexNumber] = NULL;	}	}	} 
		cout<<endl;	}

	void PrintList() {  //function for printing the selected list
		complexNode *ptr = head;
		if (head == nullptr){ //If list is empty		
			cout << "The list is empty \n";
			cout<<endl;}		
		else {
			while (ptr->nexts[indexNumber] != NULL) { //if not at the end of list
				cout << ptr->type << "-" << ptr->num << " ";   //print the elements
				ptr = ptr->nexts[indexNumber];} //go to other node
			cout << ptr->type << "-" << ptr->num << "\n";}}};

void Merge(linked_list &a, linked_list &b, linked_list &c, linked_list &d) {  //function for merging lists that include same elements
	linked_list heads[] = { a, b, c, d };
	for (int i = 0; i < 4; i++) {
		complexNode *firstPtr = NULL;
		if (i == 0) {
			firstPtr = a.getHead();	}
		if (i == 1) {
			firstPtr = b.getHead();	}
		if (i == 2) {
			firstPtr = c.getHead();	}
		if (i == 3) {
			firstPtr = d.getHead();	}
		complexNode *secondPtr = NULL;
		complexNode *secondPrevPtr = NULL;
		while (firstPtr != NULL) {
			for (int j = 0; j < 4; j++) {
				if (i < j) {
					if (j == 0) {
						secondPtr = a.getHead();}
					if (j == 1) {
						secondPtr = b.getHead();}
					if (j == 2) {
						secondPtr = c.getHead();}
					if (j == 3) {
						secondPtr = d.getHead();}
					secondPrevPtr = NULL;
					while (secondPtr != NULL) {
						string temp_string = "M" + to_string(i);
					if ((firstPtr->num == secondPtr->num) && (firstPtr->type == temp_string || firstPtr->type == "S")){//if common element found
							if (secondPrevPtr == NULL)        //merge head
							{
								firstPtr->nexts[j] = secondPtr->nexts[j];
								firstPtr->type = temp_string;
								delete secondPtr;
								if (j == 0) {
									secondPtr = a.setHead(firstPtr);}
								if (j == 1) {
									secondPtr = b.setHead(firstPtr);}
								if (j == 2) {
									secondPtr = c.setHead(firstPtr);}
								if (j == 3) {
									secondPtr = d.setHead(firstPtr);}
								secondPtr = heads[j].setHead(firstPtr);	}
							else if (secondPtr->nexts[j] != NULL) {   //merge middle
								secondPrevPtr->nexts[j] = firstPtr;
								firstPtr->nexts[j] = secondPtr->nexts[j];
								firstPtr->type = temp_string;
								delete secondPtr;
								secondPtr = firstPtr;}							
							else{                                  //merge tail							
								secondPrevPtr->nexts[j] = firstPtr;
								firstPtr->type = temp_string;
								delete secondPtr;
								secondPtr = firstPtr;}}
						secondPrevPtr = secondPtr;
						secondPtr = secondPtr->nexts[j];}}}
			firstPtr = firstPtr->nexts[i];}}}

void message(int &choice){   //for asking the user 6 options to choose
	cout << "1 - Insert a new node\n" <<
		"2 - Merge lists\n" <<
		"3 - Print list\n" <<
		"4 - Print all lists\n" <<
		"5 - Delete node\n" <<
		"6 - Exit\n\n" <<
		"Enter your choice:";
	cin >> choice;}

void PrintAll(complexNode *head1, complexNode *head2, complexNode *head3, complexNode *head4) { //function for printing all lists
	complexNode *ptr[4] = { head1, head2, head3, head4 };
	for (int i = 0; i < 4; i++) {  //it will print all 4 lists in loop
		cout << "***** LIST" << i << " *****\n";
		if (ptr[i] == nullptr) //If list is empty
		{
			cout << "The list is empty\n";	}
		else {
			while (ptr[i]->nexts[i] != NULL) {
				cout << ptr[i]->type << "-" << ptr[i]->num << " ";
				ptr[i] = ptr[i]->nexts[i];	}
			cout << ptr[i]->type << "-" << ptr[i]->num << "\n";}}
	cout<<endl;}	

void deleteAll(complexNode *head1, complexNode *head2, complexNode *head3, complexNode *head4)//for not allocating memory after the end of program.
{
	complexNode *ptr[4] = { head1, head2, head3, head4 };
	while (head1 != NULL || head2 != NULL || head3 != NULL || head4 != NULL){ //while not empty list
		for (int i = 0; i < 4; i++)	{
			complexNode * tempPtr = ptr[i];
			complexNode * prevTempPtr = NULL;
			while (tempPtr != NULL) {
				if (tempPtr->type == "S"){   //if standart type list
					prevTempPtr = tempPtr;
					tempPtr = tempPtr->nexts[i];
					delete prevTempPtr;}
				else if (tempPtr->type[0] == 'M' && (tempPtr->nexts[0] != NULL || tempPtr->nexts[1] != NULL || tempPtr->nexts[2] != NULL || tempPtr->nexts[3] != NULL))	{
					prevTempPtr = tempPtr;
					tempPtr = tempPtr->nexts[i];
					prevTempPtr->nexts[i] = NULL;}
				else if (tempPtr->type[0] == 'M' && (tempPtr->nexts[0] == NULL && tempPtr->nexts[1] == NULL && tempPtr->nexts[2] == NULL && tempPtr->nexts[3] == NULL))	{
					prevTempPtr = tempPtr;
					tempPtr = tempPtr->nexts[i];
					delete prevTempPtr;	}}}}}

int main() {
	//creating 4 linked lists 
	linked_list a(0); 
	linked_list b(1);
	linked_list c(2);
	linked_list d(3);
	int choice = 0;
	while (choice != 6) { //if the 6th exit choice is not chosen
		message(choice);
		if (choice == 1) {
			int list;
			cout << "Please enter which list you want to add to: ";
			cin >> list;
			if (list < 0 || list > 4) {  //list number must be 0 1 2 3
				cout << "Selection out of range.\n\n";}
			else {
				cout << "Please enter the element you want to add: ";
				int element;
				cin >> element;
				if (list == 0) {
					a.addToEnd(element);}  //calling the adding function for 0th list				
				if (list == 1) {
					b.addToEnd(element);}				
				if (list == 2) {
					c.addToEnd(element);}				
				if (list == 3) {
					d.addToEnd(element);}}}
		else if (choice == 2) {
			Merge(a, b, c, d);  //calling merge function
			cout<<endl;	}
		else if (choice == 3) {
			int list2;
			cout << "Please enter which list you want print:";
			cin >> list2;
			if (list2 < 0 || list2 > 4) {
				cout << "Selection out of range.\n\n";}
			else {
				if (list2 == 0) {
					a.PrintList();}
				if (list2 == 1) {
					b.PrintList();}
				if (list2 == 2) {
					c.PrintList();}
				if (list2 == 3) {
					d.PrintList();}}}
		else if (choice == 4) {
			PrintAll(a.getHead(), b.getHead(), c.getHead(), d.getHead());}
		else if (choice == 5) {
			int list3;
			cout << "Please enter which list you want delete from: ";
			cin >> list3;
			if (list3 < 0 || list3 > 4) {
				cout << "Selection out of range.\n\n";}
			else {
				cout << "Please enter the number to be deleted: ";
				int element;
				cin >> element;
				if (list3 == 0) {
					a.Delete(element);}
				if (list3 == 1) {
					b.Delete(element);}
				if (list3 == 2) {
					c.Delete(element);}
				if (list3 == 3) {
					d.Delete(element);}}}}
	deleteAll(a.getHead(), b.getHead(), c.getHead(), d.getHead()); //at the end of program, delete all stuff to not allocate memory.
	return 0;}