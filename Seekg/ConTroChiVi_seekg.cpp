#include <iostream>
#include <fstream>
using namespace std;

/* seekg(x, y)
-x: so byte can dich chuyen(luon la so nguyen)
	+ am (-): dich ve ben tay trai.
	+ duong (+): dich ve ben tay phai.
-y: vi tri bat dau dich:
	+ y = 0: dau file. <=> ios::beg <=> SEEKG_SET
	+ y = 1: vi tri hien tai. <=> ios::cur <=> SEEKG_CUR
	+ y = 2: vi tri cuoi file. <=> ios::end  <=> SEEKG_END */

int main()
{
	int n;
	ifstream fileInPut;
	ofstream fileOutPut;

	fileInPut.open("D:\\KyThuat_C++\\Seekg\\FileInPut.txt", ios_base::in);

	if (fileInPut.fail())
	{
		cout << "File isn't exist!" << endl;
		system("pause");
		return 0;
	}

	fileInPut.seekg(-3, ios::end);

	fileInPut >> n;
	cout << n << endl;

	fileInPut.close();
	fileOutPut.close();

	system("pause");
	return 0;
}