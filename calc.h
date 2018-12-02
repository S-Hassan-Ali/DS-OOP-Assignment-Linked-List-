#pragma once

class calc
{
private:
	int a = 0;
	double var1;
	double var2;

public:

	calc(double A = 0, double B = 0)
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
		cout << var1 << " ";
		cout << var2 << "i" << endl;
	}
};