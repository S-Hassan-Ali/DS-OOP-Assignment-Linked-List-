#include <iostream>
using namespace std;



class calc
{
private:
	int a = 0;
	double var1;
	double var2;
	
public:
	
	calc(double A=0, double B=0)
	{
		var1 = A;
		var2 = B;
	}

	calc operator +(calc &obj) //operator overloading used in the next method
	{
		calc res;
		res.var1 = 0;
		res.var2 = 0;
		res.var1 = this->var1 + obj.var1;
		res.var2 = this->var2 + obj.var2;
		return res;
	}
	calc add(calc &A, calc &B)	//Method for complex obj addition
	{
		calc res;
		res = A + B;
		return res;
	}

	calc operator -(calc &obj)	//operator overloading used in the next method
	{
		calc res;
		res.var1 = 0;
		res.var2 = 0;
		res.var1 = this->var1 - obj.var1;
		res.var2 = this->var2 - obj.var2;
		return res;
	}
	calc sub(calc &A, calc &B)	//Method for complex obj subtraction
	{
		calc res;
		res = A - B;
		return res;
	}

	calc operator *(calc &obj)	//operator overloading used in the next method
	{
		calc res;
		res.var1 = 0;
		res.var2 = 0;
		res.var1 = this->var1 * obj.var1;
		res.var2 = this->var2 * obj.var2;
		return res;
	}
	calc multi(calc &A, calc &B)	//Method for complex obj multiplication
	{
		calc res;
		res = A * B;
		return res;
	}

	calc operator /(calc &obj)	//operator overloading used in the next method
	{
		a = 0;
		if (obj.var1 == 0 || obj.var2 == 0)	//Condition for exception handling
		{
			a = 1;
			
			{
				throw (0);
			}
			
		}
		else
		{
			calc res;
			res.var1 = 5;
			res.var2 = 0;
			res.var1 = this->var1 / obj.var1;
			res.var2 = this->var2 / obj.var2;
			return res;
		}
	}
	
	
	calc div(calc &A, calc &B)	//Method for complex obj division
	{
		calc res;
		try
		{
			res = A / B;

		}
		catch (int e) //Part of exceptional handling
		{
			cout << "The denominator is zero" << endl;
		}
		
		return res;
	}
	int divo() 
	{
		return a;
	}
	double first()
	{
		return var1;
	}
	double sec()
	{
		return var2;
	}

	void display()
	{
		cout << var1<< " ";
		cout << var2<<"i"<< endl;
	}
};

//-------------------------------------------------------
struct dat //To store complex numbers
{
	double r;
	double i;
};

struct node
{
	dat val;
	node *next;
};

class list
{
private:
	node *head, *tail;
public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	void createnode(double value, double value2 )	//To make a new node
	{
		node *temp = new node;
		temp->val.r = value;
		temp->val.i = value2;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	void Replace(double a,double b, double p)	//To replace a specific node with another one
	{
		node*temp = head;

		for (int i = 1; i < p - 1; i++)
		{
			temp = temp->next;
		}
		node*s = new node;
		s->next = temp->next;
		temp->next = s;
		s->val.r = a;
		s->val.i = a;
	}

	void display()	//To traverse and display the whole linked list
	{
		node *temp = new node;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->val.r<<" "<<temp->val.i<<"i" << endl;
			temp = temp->next;
		}
	}
	void insert_start(double value, double value2 )	//To insert a node at the start
	{
		node *temp = new node;
		temp->val.r = value;
		temp->val.i = value2;
		temp->next = head;
		head = temp;
	}
	void insert_end(double value, double value2)	//To insert a node at the end
	{
		node *temp = new node;
		tail->next = temp;
		temp->val.r = value;
		temp->val.i = value2;
		temp->next = NULL;

		tail = temp;
	}
	void delete_first()	//To delete the first node
	{
		node *temp = new node;
		temp = head;
		head = head->next;
		delete temp;
	}
	void delran(int p)	//To delete a specified node
	{
		node *temp = head;
		node * temp2 = head;
		node *temp3 = head;
		for (int i = 1; i < p + 1; i++)
		{
			temp = temp->next;
		}
		for (int i = 1; i < p; i++)
		{
			temp2 = temp2->next;
		}
		delete temp2;
		for (int i = 1; i < p - 1; i++)
		{
			temp3 = temp3->next;
		}
		temp3->next = temp;
	}
	void delete_last()	//To delete the last node
	{
		node *current = new node;
		node *previous = new node;
		current = head;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = NULL;
		delete current;
	}
};

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