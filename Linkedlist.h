#pragma once

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
	void createnode(double value, double value2)	//To make a new node
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
	void Replace(double a, double b, double p)	//To replace a specific node with another one
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
			cout << temp->val.r << " " << temp->val.i << "i" << endl;
			temp = temp->next;
		}
	}
	void insert_start(double value, double value2)	//To insert a node at the start
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