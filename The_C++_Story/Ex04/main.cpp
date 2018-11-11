#include "MyString.hpp"

using namespace std;

int main()
{
	CString str1 = "Hello";
	CString str2 = "World";

	CString str3 = str1 + " " + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	cout << "Type the string : ";
	cin >> str1;

	str2 = str1;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
}
