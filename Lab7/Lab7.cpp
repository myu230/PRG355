#include <iostream>

using namespace std;

class Ratio
{
private:
	int denom;
	int num;
public:
	friend istream& operator >> (istream& cin, Ratio& r);
	friend ostream& operator << (ostream& cout, Ratio& r);
	Ratio operator+(Ratio& r);
	Ratio operator-(Ratio& r);
	Ratio operator*(Ratio& r);
	Ratio operator/(Ratio& r);
};

istream& operator >> (istream& cin, Ratio& r)
{
	static int counter = 1;
	if (counter == 3) { counter = 1; }
	cout << "Enter numerator and denominator of ratio #" << counter << " ==>  " ;
	cin >> r.num >> r.denom;
	counter++;
	return cin;
}

ostream& operator << (ostream& cout, Ratio& r)
{
	cout << r.num << "/" << r.denom;
	return cout;
}

Ratio Ratio::operator+(Ratio& r)
{
	Ratio ans;
	ans.num = (this->num * r.denom) + (r.num * this->denom);
	ans.denom = (this->denom * r.denom);
	return ans;
}

Ratio Ratio::operator-(Ratio& r)
{
	Ratio ans;
	ans.num = (this->num * r.denom) - (r.num * this->denom);
	ans.denom = (this->denom * r.denom);
	return ans;
}

Ratio Ratio::operator*(Ratio& r)
{
	Ratio ans;
	ans.num = (this->num * r.num);
	ans.denom = (this->denom * r.denom);
	return ans;
}

Ratio Ratio::operator/(Ratio& r)
{
	Ratio ans;
	ans.num = (this->num * r.denom);
	ans.denom = (this->denom * r.num);
	return ans;
}

void pMenu(void)
{
	cout << "Ratio Calculator" << endl << endl;
	cout << "Select an operation:" << endl;
	cout << "1. Add Ratios" << endl;
	cout << "2. Subtract Ratios" << endl;
	cout << "3. Divide Ratios" << endl;
	cout << "4. Multiply Ratios" << endl;
	cout << "5. Exit";
}

int main(void)
{
	Ratio r1, r2, r3;
	int selection;

	pMenu();

	do 
	{
		cout << endl << endl << "Operation ==> ";
		cin >> selection;
		cout << endl;
		
		if (selection != 5)
		{
			cin >> r1 >> r2;
		}

		switch (selection)
		{
		case 1:
			r3 = r1 + r2;
			cout << endl << "Result:  " << r1 << " + " << r2 << " = " << r3;
			break;
		case 2:
			r3 = r1 - r2;
			cout << endl << "Result:  " << r1 << " - " << r2 << " = " << r3;
			break;
		case 3:
			r3 = r1 / r2;
			cout << endl << "Result:  " << r1 << " / " << r2 << " = " << r3;
			break;
		case 4:
			r3 = r1 * r2;
			cout << endl << "Result:  " << r1 << " * " << r2 << " = " << r3;
			break;
		case 5:		
			break;
		}

	} while (selection != 5);


	system("pause");
	return(0);
}