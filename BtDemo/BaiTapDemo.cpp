#include <iostream>
#include <fstream>
using namespace std;

bool check(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int a[100], i = 0, dem = 0;
	ifstream fileInPut;
	ofstream fileOutPut;

	fileInPut.open("FileRoot.txt", ios_base::in);

	if (fileInPut.fail())
	{
		cout << "File isn't exist!" << endl;
		system("pause");
		return 0;
	}
	
	while (!fileInPut.eof()) // <=> (fileInPut.eof() == false) kiem tra con tro den cuoi tep chua
	{
		fileInPut >> a[i];
		i++;
		dem++;
	}

	fileOutPut.open("FileOutPut.txt", ios_base::app);

	for (int i = 0; i < dem; i++)
	{
		if (check(a[i]))
			fileOutPut << "True" << " ";
		else
			fileOutPut << "False" << " ";
	}

	fileInPut.close();
	fileOutPut.close();

	system("pause");
	return 0;
}