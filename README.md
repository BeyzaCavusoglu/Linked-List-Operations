# Linked-List-Compression

The aim of this code is to practice linked list operations. There will be four linked lists and five operations that can be executed. Also the linked lists can be compressed by merging the nodes containing the same number. The details are described below.

2.	Data Structure
There will be four linked lists. Instead of standard node implementations, I will use the given complexNode implementation.

		#define SIZE 4
  	
		struct complexNode {
  	
		int num;
  
		string type; // Can be "S"(standard) or "M"(merged)
  	
		complexNode* nexts[SIZE];

		complexNode(int n = 0)
				: num(n) {
					for(int i = 0; i < SIZE; i++)
						nexts[i] = NULL;
					type = "S";
			} 
  		};

Num is the content of the nodes. Type denotes whether a node is merged or not and nexts is an array of next pointers. One for each linked list in project. When a node becomes a merged node, multiple next pointers will point to corresponding next nodes in linked lists.

3.	Program Flow
When the program starts the user will be prompted to select from 6 options. For the options you can use the function below:

		void message()
		{
				cout << "1 - Insert a new node\n" << 
				"2 - Merge lists\n" << 
				"3 - Print list\n" << 
				"4 - Print all lists\n" <<
				"5 - Delete node\n" <<
				"6 - Exit\n\n" <<
				"Enter your choice:";
		}

•	Insertion:
When the user selects insertion, the program will ask for which linked-list to add first. If the given number is in the interval [0,4], the number to be added will be asked. Then the corresponding number will be added at the end of the selected list. If the selection of list is not in the interval [0,4], then an error message will be displayed.

•	Print List:
When the user selects print list, the program will ask for which linked-list is to be printed. If the given number is in the interval [0,4], the selected list will be printed. If the selection of list is not in the interval [0,4], then an error message will be displayed. While printing a list, first the type of the list then the content of the list is printed, separated by a dash. For example, if the node has a type “S” and num = 5, it should be printed as S-5. If the node is a merged node, then after printing the type you should also print the index of the list to which the original copy of that node belongs to. For example, if there is a merged node in list 1, and the content is 3 you should print: M1-3. 

•	Print All Lists:
When this option is selected, all the lists will be printed. Between lists, you should use multiple * characters as a separator. 

•	Merge:
When the user selects merge, all the lists will be merged. The merging operation is done as follows:
If there are multiple nodes with the same number as content, all the copies except the first occurrence of the number is deleted. To be able to track the lists with deleted nodes, all the pointers pointing to the deleted node will point to the original copy. Also, here we use a complexNode, which is similar to the traditional node definition but has four next pointers. When two or more nodes are merged, each next pointer of the merged node will point to the next node of the corresponding list. For clarity, please check the figure below.
 

For simplicity, we demonstrate a case where there are two linked lists. As you can see, List 0 uses the 0th next pointers in the nexts array, whereas List 1 uses the 1st next pointers. Below you can find the merged version of these linked lists. 
 
Since the number 2 appears in both lists, the second one is deleted when the merge operation is executed. The next pointer in List 1 points to the corresponding node in List 0.  Also, the 1st next pointer points to the corresponding node in List 1 so that the 1st list can be tracked without any problems. Finally, the type of the node in List 0 is changed to M0 since it has now become a merged node and the list index of that node is 0. 
Note that, there can’t be multiple numbers in a single list. In other words, if a number is added to a list before, it won’t be added again. You don’t need to implement a control mechanism for this.

•	Delete node:
When this option is selected, first the list index will be prompted and then the number to be deleted will be entered by the user.  After the appropriate index checks are done, if a node with the given number exists in the given list, it will be removed. Note that, removing an element from a list does not necessarily mean that you have to delete that node. If the selected node is a merged node, then only the corresponding pointers should be deleted. If a node has no more next nodes left, i.e. all the next pointers are NULL, then the node can be deleted. Also, if a node becomes a standard node after a deletion, you should also change its type back to S. Below you can find the lists above, after deleting 2 from List 1.
 
-----------------------------------------------------------------------------------------------------------------------------------------

4.	Sample Runs

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 0

Please enter the element you want to add: 1

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 0

Please enter the element you want to add: 2

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 0

Please enter the element you want to add: 3

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 1

Please enter the element you want to add: 2

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 1

Please enter the element you want to add: 4

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:4

***** LIST 0 *****

S-1 S-2 S-3

***** LIST 1 *****

S-2 S-4

***** LIST 2 *****

The list is empty

***** LIST 3 *****

The list is empty

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:2

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:4

***** LIST 0 *****

S-1 M0-2 S-3

***** LIST 1 *****

M0-2 S-4

***** LIST 2 *****

The list is empty

***** LIST 3 *****

The list is empty

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:6

Press any key to continue . . .

---------------------------------------------------------

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 3

Please enter the element you want to add: 2

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 3

Please enter the element you want to add: 7

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 3

Please enter the element you want to add: 9

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 2

Please enter the element you want to add: 8

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 2

Please enter the element you want to add: 7

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:2

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:3

Please enter which list you want print: 3

S-2 M2-7 S-9

9

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:6

Press any key to continue . . .

-----------------------------------------------------

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 0

Please enter the element you want to add: 9

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 0

Please enter the element you want to add: 8

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 0

Please enter the element you want to add: 7

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 1

Please enter the element you want to add: 4

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 1

Please enter the element you want to add: 8

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 1

Please enter the element you want to add: 3

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 2

Please enter the element you want to add: 4

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 2

Please enter the element you want to add: 8

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:1

Please enter which list you want to add to: 2

Please enter the element you want to add: 5

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:4

***** LIST 0 *****

S-9 S-8 S-7

***** LIST 1 *****

S-4 S-8 S-3

***** LIST 2 *****

S-4 S-8 S-5

***** LIST 3 *****

The list is empty

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:2

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:4

***** LIST 0 *****

S-9 M0-8 S-7

***** LIST 1 *****

M1-4 M0-8 S-3

***** LIST 2 *****

M1-4 M0-8 S-5

***** LIST 3 *****

The list is empty

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:5

Please enter which list you want delete from: 1

Please enter the number to be deleted: 8

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:4

***** LIST 0 *****

S-9 M0-8 S-7

***** LIST 1 *****

M1-4 S-3

***** LIST 2 *****

M1-4 M0-8 S-5

***** LIST 3 *****

The list is empty

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:6

Press any key to continue . . .

-------------------------------------------------

1 - Insert a new node
2 - Merge lists
3 - Print list
4 - Print all lists
5 - Delete node
6 - Exit

Enter your choice:1

Please enter which list you want to add to: 7

Selection out of range.

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:5

Please enter which list you want delete from: 1

Please enter the number to be deleted: 1

The list is empty


1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:3

Please enter which list you want print: 1

The list is empty

1 - Insert a new node

2 - Merge lists

3 - Print list

4 - Print all lists

5 - Delete node

6 - Exit

Enter your choice:6

Press any key to continue . . .
