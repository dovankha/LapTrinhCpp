#include <iostream>
#include <typeinfo>
using namespace std;

void changeA(int *ptr)
{
	*ptr = 1;
	ptr[1] = 3;
}

int main()
{
	int a [4] = {5, 8, 2, 7};
	
//	cout << "Val : " << a << endl;
//	cout << "Address: " << &a << endl;
//	cout << "Element 0: " << &a[0] << endl;

//	cout << *a << endl; // tra ve phan tu dau tien
//	int *ptr = a; 
//	cout << (ptr) << endl;
//	
//	char name[] = "Kha";
//	cout << *name << endl;

//	cout << typeid(a).name() << endl;
//	cout << sizeof(a) << endl;
//	
//	int *ptr = a;
//	cout << typeid(ptr).name() << endl;
//	cout << sizeof(ptr) << endl;
	
	cout << "Truoc: " << endl;
	
	cout << "a[0] " << a[0] << endl;
	cout << "a[1]" << a[1] << endl;
	changeA(a);
	
	cout << "Sau: " << endl;
	cout << "a[0]" << a[0] << endl;
	cout << "a[1]" << a[1] << endl;
	
	return 0;
}
