#include <iostream>
#include <fstream>
using namespace std;

struct phanSo
{
	int tuSo, mauSo;
};

struct danhSach
{
	phanSo a[30];
	int n;
};

void doc1PhanSo(phanSo& ps, ifstream& inPut)
{
	inPut >> ps.tuSo;
	char x;
	inPut >> x;
	inPut >> ps.mauSo;
}

void docFile(danhSach& ds, ifstream& inPut)
{
	inPut >> ds.n;
	for (int i = 0; i < ds.n; i++)
	{
		doc1PhanSo(ds.a[i], inPut);
	}
}

void xuatDSPhanSo(danhSach ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		cout << ds.a[i].tuSo << "/" << ds.a[i].mauSo << endl;
	}
}

int timUCLL(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

void rutGonPhanSo(phanSo& ps)
{
	int ucll = timUCLL(ps.tuSo, ps.mauSo);
	ps.tuSo /= ucll;
	ps.mauSo /= ucll;
}

void ghiFilePhanSoRutGon(danhSach& ds, ofstream& OutPut)
{
	for (int i = 0; i < ds.n; i++)
	{
		rutGonPhanSo(ds.a[i]);
	}
	OutPut.open("RutGonPhanSo.txt", ios_base::app);
	OutPut << ds.n << endl;
	for (int i = 0; i < ds.n; i++)
	{
		OutPut << ds.a[i].tuSo << "/" << ds.a[i].mauSo << endl;
	}
	OutPut.close();
}

void ghiFilePhanSoLonNhat(danhSach& ds, ofstream& OutPut)
{
	int viTri = 0;
	OutPut.open("output.txt", ios_base::app);
	float max = ds.a[0].tuSo / (ds.a[0].mauSo * 1.0);
	for (int i = 1; i < ds.n; i++)
	{
		float temp = ds.a[i].tuSo / (ds.a[i].mauSo * 1.0);
		if (max < temp)
		{
			max = temp;
			viTri = i;
		}
	}
	OutPut << ds.a[viTri].tuSo << "/" << ds.a[viTri].mauSo;
	OutPut.close();
}

int main()
{
	danhSach ds;
	ifstream inPut;
	ofstream outPut;

	inPut.open("input.txt", ios_base::in);
	if (inPut.fail())
	{
		cout << "File isn't exist!" << endl;
		system("puase");
		return 0;
	}
	docFile(ds, inPut);
	xuatDSPhanSo(ds);
	ghiFilePhanSoLonNhat(ds, outPut);
	ghiFilePhanSoRutGon(ds, outPut);

	inPut.close();
	system("pause");
	return 0;
}