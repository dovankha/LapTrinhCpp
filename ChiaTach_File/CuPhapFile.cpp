#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int a, b;
	ifstream fileInPut;
	fileInPut.open("E:\FileRoot.txt", ios_base::in);
	 
	if (fileInPut.fail())
	{
		cout << "\nFile isn't exist" << endl;
		system("pause");
		return 0;
	}

	fileInPut >> a; // doc du lieu tu file
	fileInPut >> b;

	cout << "Tong cua 2 so nguyen = " << a + b << endl;
	
	fileInPut.close();

	/*--------------------------------------------------------*/

	ofstream fileOutPut;

	fileOutPut.open("E:\\fileOutPut.txt", ios_base::app);
	/*	ios_base::app : ghi them vao file (data file van con nguyen).
		ios_base::in : doc du lieu tu file.
		ios_base::out : ghi du lieu vao file (data file se mat di).*/
	fileOutPut << a + b; // ghi du lieu vao file moi

	fileOutPut.close();

	system("pause");
	return 0;
}