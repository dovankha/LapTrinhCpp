#include <iostream>
#include <typeinfo>

#define NULL 0
using namespace std;

int main()
{
//	int x;
//	cout << "Nhap x: ";
//	cin >> x;
//	
//	cout << "x = " << x << endl;
//	cout << "&x = " << &x << endl;
//	cout << "*&x = " << *&x << endl;
//	
//	*&x = 20;
//	
//	cout << "*&x = " << *&x << endl;
//	cout << "x = " << x << endl;
	
//	int *iPtr;
//	double *dPtr;
//	
//	int* iPtr2;
//	int* iPtr3; // khong nen dung
//	
//	int *iPtr4, *iPtr5; // nen dung voi bien
//	
//	int* someThing(); // nen dung voi function
//	

//	int val = 10;
//	int *ptr = &val;
//	
//	cout << &val << endl; // in dia chi bien val
//	cout << ptr << endl; // in dia chi cua con tro ptr dang giu
//	cout << *ptr << endl; // in gia tri cua con tro ptr dang giu
//	
//	*ptr = 100;
//	cout << *&val << endl; // cout << val << endl;

//	int iVal = 5;
//	double dVal = 7.0;
//	
//	int *iPtr = &iVal;
//	double *dPtr = &dVal;
//	
//	iPtr = &dVal; // con tro int khong the tro den dia chi cua bien double
//	dPtr = &iVal; // con tro double khong the tro den dia chi cua bien int
//	
//	int *ptr = 5; // sai - con tro chi co the giu 1 bien dia chi

//	double val = 5.5;
//	cout << typeid(&val).name() << endl;

	// float *ptr{ 0 }; // con tro null
	
//	float a = 10;
//	float *ptr = &a;
//	 
//	float *ptr2; // con tro rac
//	ptr2 = 0; // con tro null
//	
//	// double *ptr{ 0 };
//	
//	if (ptr)
//		cout << "Con tro tro den dia chi";
//	else 
//		cout << "Con tro tro den NULL";
	
	// double *ptr = NULL; // khong nen dung
	int a = 5;
	int *ptr = &a; // la mot con tro null - nen dung;
	
	if (ptr)
		cout << "you passed in " << *ptr << endl;
	else
		cout << "You passed in null pointer" << endl;
	
	return 0;
}
