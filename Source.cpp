#include <iostream>
using namespace std;
#include "linkedlist.h"
#include "calc.h"



int main()
{
	calc A(4,5), B(3,-3), C(4,3); //Initializing objects of the class 'calc'

	calc res = A.add(A, B);	//Adding the object 'A' and 'B'
	cout << "Addition = ";
	res.display();
	
	calc res2 = A.sub(A, C);	//Subtracting the object 'A' and 'C'
	cout << "Subtraction = ";
	res2.display();

	calc res3 = B.multi(B, C);	//Multiplying the object 'B' and 'C'
	cout << "Multiplication = ";
	res3.display();

	cout << "Division = ";	
	calc res4 = A.div(A, C);	//Dividing the onject 'A' and 'C'
	if (A.divo() == 0)
	{
		res4.display();
	}
	cout << endl;

	list Complex;	//Creating the object of the class 'list'

	Complex.createnode(C.first(),C.sec());
	Complex.insert_start(B.first(), B.sec());
	Complex.insert_start(A.first(), A.sec()); //Created three nodes with complex numbers
	
	cout << "Initial linked list"<<endl;
	Complex.display();
	cout << endl;

	Complex.insert_end(res.first(), res.sec()); cout << "Inserting the addition of first and second member of the list as a new member at the end of the list" << endl;
	Complex.display();
	cout << endl;

	Complex.insert_end(res2.first(), res2.sec());	cout<<"Inserting the subtraction of first and third member of the list as a new member at the end of the list" <<endl;
	Complex.display();
	cout << endl;

	Complex.insert_end(res3.first(), res3.sec());	cout << "Inserting the multiplication of second and third member of the list as a new member at the end of the list" << endl;
	Complex.display();
	cout << endl;

	Complex.insert_end(res4.first(), res4.sec());	cout << "Inserting the division of first and third member of the list as a new member at the end of the list" << endl;
	Complex.display();
	cout << endl;

	Complex.delran(4);	cout << "Deleting the 4th member in the linked list" << endl;
	Complex.display();
	cout << endl;

	Complex.delete_last();	cout << "Deleting the last member of the linked list" << endl;
	Complex.display();
	cout << endl;
	cout << "------------------------------------------ACE PRODUCTIONS OFFICIAL----------------------------------------"<<endl;

	
	system("pause");
	return 0;
}