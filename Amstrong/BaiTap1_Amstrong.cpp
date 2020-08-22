#include <iostream>
#include <fstream>
using namespace std;

int CountDigit(int n)
{
	int dem = 0;
	while (n != 0)
	{
		n /= 10;
		dem++;
	}
	return dem;
}

bool check_Amstrong(int n)
{
	int i, soBanDau = n, numDigit, sum = 0;
	numDigit = CountDigit(n);
	while (n != 0)
	{
		i = n % 10;
		sum += pow(i, numDigit);
		n /= 10;
	}
	if (sum == soBanDau)
		return true;
	return false;
}

int main()
{
	int a[30], i = 0, dem = 0;
	ifstream fileInPut;
	ofstream fileOutPut;

	fileInPut.open("input.txt", ios_base::in);
	if (fileInPut.fail())
	{
		cout << "File isn't exist!" << endl;
		system("pause");
		return 0;
	}

	while (!fileInPut.eof())
	{
		fileInPut >> a[i];
		i++;
		dem++;
	}

	fileOutPut.open("FileOutPut.txt", ios_base::app);

	for (int i = 0; i < dem; i++)
	{
		if (check_Amstrong(a[i]))
			fileOutPut << a[i] << " ";
	}

	fileInPut.close();
	fileOutPut.close();
	return 0;
}