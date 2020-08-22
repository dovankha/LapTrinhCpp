#include <iostream>
#include <string>
using namespace std;

struct sinhVien
{
	string hoTen, MSSV;
	float diemTB = 0;
	float diemKTLT = 0;
	float diemCTDL_GT = 0; // tinh bao mat thi phai co gia tri. Gan cho no = 0;
};

struct danhSach
{
	sinhVien* DSSV[100];
	int n;
};

void nhapThongTin(sinhVien& sv)
{
	// rewind(stdin);
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

void xuatThongTin(sinhVien sv)
{
	cout << "\nHo & ten:\t" << sv.hoTen << endl;
	cout << "MSSV:\t\t" << sv.MSSV << endl;
	cout << "Diem Toan:\t" << sv.diemTB << endl;
	cout << "Diem CTDT&GT:\t" << sv.diemCTDL_GT << endl;
	cout << "Diem KTLT:\t" << sv.diemKTLT << endl;
}

void xuatDSSV(danhSach ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		cout << "\nSTT: " << i + 1 << endl;
		xuatThongTin(*ds.DSSV[i]);
	}
}

void MENU(danhSach& ds)
{
	int luaChon;
	while (true)
	{
		cout << "\n\n\t========= QUAN LY SINH VIEN =========" << endl;
		cout << "\n\t1 - Them thong tin sinh vien.";
		cout << "\n\t2 - Xuat danh sach sinh vien.";
		cout << "\n\t0 - Ket thuc.";
		cout << "\n\n\t      ========= END =======\n" << endl;

		cout << "\nNhap vao lua chon: ";
		cin >> luaChon;

		if (luaChon == 1)
		{
			sinhVien* x = new sinhVien;
			cout << "\n\n\t--------NHAP THONG TIN SINH VIEN----------\n" << endl;
			nhapThongTin(*x);
			ds.DSSV[ds.n] = x;
			ds.n++;
		}
		else if (luaChon == 2)
		{
			system("cls");
			cout << "\n\n\t---------DANH SACH SINH VIEN-------------\n" << endl;
			xuatDSSV(ds);
			cin.get(); // dung man hinh = system("pause");
		}
		else
			break;
	}
}

int main()
{
	danhSach ds;
	ds.n = 0;

	/*sinhVien x;
	cout << sizeof(x) << endl;*/

	MENU(ds);

	for (int i = 0; i < ds.n; i++)
	{
		delete ds.DSSV[i];
	}

	system("pause");
	return 0;
}