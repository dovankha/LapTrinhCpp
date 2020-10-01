#include <iostream>
#include <vector>
#define ar array
using namespace std;

void xuatMang(vector<int> ar)
{
	for (int i = 0; i < ar.size(); i++)
		cout << ar[i] << " ";
}

int main()
{
	vector<int> ar;
	vector<int> x;
//	ar.resize(5, 8);
//	cout << "\tXUAT MANG" << endl;
//	xuatMang(ar);
//	cout << "\nPhan tu tai vi tri 0: " << ar.at(0);
//	ar.resize(10);
//	cout << "\n------------------" << endl << endl;
//	xuatMang(ar);

	for (int i = 0; i < 10; i++)
	{
		ar.push_back(i);
	}
	cout << "\t=======XUAT MANG=======" << endl;
	xuatMang(ar);
	
	cout << "\nPhan tu dau tien cua mang: " << ar.front();
	cout << "\nPhan tu cuoi cung cua mang: " << ar.back();
	
	ar.pop_back(); // delete phan tu cuoi cung cua mang
	cout << "\n\t=======XUAT MANG=======" << endl;
	cout << "(Sau khi delete phan tu cuoi cung)" << endl;
	xuatMang(ar);
	
	cout << "\nKich thuoc thuc su cua mang vector hien tai: " << ar.capacity();
	cout << "\nSo luong phan tu co the chua duoc cua vector: " << ar.max_size();
	
//	ar.erase(ar.begin() + 2);  // xoa phan tu tai vi tri so 2
//	cout << "\nMang sau khi xoa: ";
//	xuatMang(ar);
	ar.erase(ar.begin() + 2, ar.begin() + 5); // xoa tu vi tri 2 den 4
	cout << "\nMang sau khi xoa tu vi tri so 2 den 4: ";
	xuatMang(ar);	
	
	ar.insert(ar.begin() + 2, 100); // them phan tu 100 tai vi tri so 2
	cout << "\nMang sau khi them tai vi tri so 2: ";
	xuatMang(ar);
	
//	ar.clear(); // xoa all cac phan tu trong vector
	for (int i = 100; i <= 105; i++)
	{
		x.push_back(i);
	}
	cout << "\n\t=======XUAT MANG=======" << endl;
	xuatMang(x);
	
	ar.swap(x);
	cout << "\nMang ar sau khi hoan doi: ";
	xuatMang(ar);
	cout << "\nMang x sau khi hoan doi: ";
	xuatMang(x);
	cout << "Kha dep trai ne!" << endl;
	system("pause");
	return 0;
}
