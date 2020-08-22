#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
// setw(<1 so nguyen>): hien thi do rong cua ket qua in ra man hinh

struct sinhVien
{
	string hoTen, MSSV;
	float diemTB = 0;
	float diemCTDL_GT = 0;
	float diemKTLT = 0;
};

void nhapThongTin(sinhVien& sv)
{
	cin.ignore();
	do
	{
		cout << "\nNhap vao Ho & ten: ";
		getline(cin, sv.hoTen);
		if (sv.hoTen.length() > 30)
			cout << "Ten ban khong hop le. Vui long nhap lai!" << endl;
	} while (sv.hoTen.length() > 30);


	do
	{
		cout << "Nhap vao MSSV: ";
		getline(cin, sv.MSSV);
		if (sv.MSSV.length() > 10)
			cout << "MSSV khong hop le. Vui long nhap lai!" << endl;
	} while (sv.MSSV.length() > 10);

	do
	{
		cout << "Nhap vao diem Toan: ";
		cin >> sv.diemTB;
		if (sv.diemTB < 0 || sv.diemTB > 10)
			cout << "Diem khong hop le. Vui long nhap lai!" << endl;
	} while (sv.diemTB < 0 || sv.diemTB > 10);

	do
	{
		cout << "Nhap vao diem CTDL&GT: ";
		cin >> sv.diemCTDL_GT;
		if (sv.diemCTDL_GT < 0 || sv.diemCTDL_GT > 10)
			cout << "Diem khong hop le. Vui long nhap lai!" << endl;
	} while (sv.diemCTDL_GT < 0 || sv.diemCTDL_GT > 10);

	do
	{
		cout << "Nhap vao diem KTLT: ";
		cin >> sv.diemKTLT;
		if (sv.diemKTLT < 0 || sv.diemCTDL_GT > 10)
			cout << "Diem khong hop le. Vui long nhap lai!" << endl;
	} while (sv.diemKTLT < 0 || sv.diemKTLT > 10);
}

/*void xuatThongTinSV(sinhVien sv)
{
	cout << "\nHo & ten:\t" << sv.hoTen << endl;
	cout << "MSSV:\t\t" << sv.MSSV << endl;
	cout << "Diem Toan:\t" << sv.diemTB << endl;
	cout << "Diem CTDT&GT:\t" << sv.diemCTDL_GT << endl;
	cout << "Diem KTLT:\t" << sv.diemKTLT << endl;
}*/

void xuatThongTinSV(sinhVien sv)
{
	cout << setw(30) << left << sv.hoTen << "\t";
	cout << setw(10) << left << sv.MSSV << "\t";
	cout << setw(4) << left << sv.diemTB << "\t";
	cout << setw(11) << left << sv.diemCTDL_GT << "\t";
	cout << setw(18) << left << sv.diemKTLT << "\t";
}

int main()
{
	sinhVien x, y;

	for (int i = 1; i < 255; i++)
	{
		SetConsoleTextAttribute(console, i);
		cout << i << "\tI want love you forever alone." << endl;
	}
	
	SetConsoleTextAttribute(console, 7);

	cout << "\n\n\t--------NHAP THONG TIN SINH VIEN----------\n" << endl;
	nhapThongTin(x);
	cout << "\n\n\t--------NHAP THONG TIN SINH VIEN----------\n" << endl;
	nhapThongTin(y);

	/*cout << "\n\n\t--------XUAT THONG TIN SINH VIEN----------\n" << endl;
	xuatThongTinSV(x);
	xuatThongTinSV(y);*/


	cout << "\n\n\t\t\t======== XUAT THONG TIN SINH VIEN ========\n" << endl;
	SetConsoleTextAttribute(console, 116);
	cout << "\n" << setw(30) << left << "Ho & ten" << "\t" << setw(10) << left << "MSSV" << "\t" << setw(4) << left << "Diem" << "\t" << setw(11) << left << "DiemCTDL_GT" << "\t" << setw(8) << left << "DiemKTLT" << endl;
	SetConsoleTextAttribute(console, 7);
	cout << endl;
	xuatThongTinSV(x);
	cout << endl;
	xuatThongTinSV(y);

	cout << endl;

	system("pause");
	return 0;
}