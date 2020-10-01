/*
============= MẢNG ĐỘNG BÊN STRUCT ============= 
Bài 3. Khai báo cấu trúc 1 phân số biết rằng 1 phân số luôn luôn có tử số và mẫu số
1. Nhập danh sách các phân số
2. Xuất danh sách các phân số
3. Rút gọn các phân số
2/4 ==> 1/2
3/6  ==> 1/2
4. Tìm phân số lớn nhất
5. Tính tổng tất cả các phân số
1/2
2/3
==> 7/6
1/2
2/3
==> 7/6
3/4
==> 46/24
==> 23/12 
*/

#include<iostream>
using namespace std;


// ================ KHAI BÁO STRUCT PHÂN SỐ ================
struct phanso
{
	int tuso;
	int mauso;
};
typedef struct phanso PhanSo;

// hàm nhập 1 phân số
void Nhap_Phan_So(PhanSo &x)
{
	cout << "\nNhap tu so: ";
	cin >> x.tuso;
	cout << "\nNhap mau so: ";
	cin >> x.mauso;
}

// hàm xuất 1 phân số
void Xuat_Phan_So(PhanSo x)
{
	cout << x.tuso << "/" << x.mauso;
}

// ============ KHAI BÁO STRUCT DANH SÁCH PHÂN SỐ ============
struct danhsach
{
	PhanSo *arr; // khai báo 1 mảng động chứa phân số // PhanSo arr[100]; // khai báo mảng tĩnh chứa tối đa 100 phân số
	int n; // số lượng phân số
};
typedef struct danhsach DanhSach;

// hàm nhập danh sách phân số
void Nhap_Danh_Sach_Phan_So(DanhSach &ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		cout << "\nNhap phan so thu " << i + 1 << endl;
		// gọi lại hàm nhập 1 phân số để nhập giá trị
		Nhap_Phan_So(ds.arr[i]);
	}
}

// hàm xuất danh sách phân số
void Xuat_Danh_Sach_Phan_So(DanhSach ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		cout << "\nPhan so thu " << i + 1 << ": ";
		// gọi lại hàm xuất 1 phân số
		Xuat_Phan_So(ds.arr[i]);
	}
}

// hàm tìm UCLN
int UCLN(int x, int y)
{
	if (x < 0)
	{
		x *= -1;
	}
	if (y < 0)
	{
		y *= -1;
	}

	while (x != y)
	{
		if (x > y)
		{
			x = x - y;
		}
		else
		{
			y = y - x;
		}
	}
	return x;
}

// hàm rút gọn 1 phân số
void Rut_Gon_Phan_So(PhanSo &x)
{
	int ucln = UCLN(x.tuso, x.mauso);
	x.tuso = x.tuso / ucln;
	x.mauso = x.mauso / ucln;
}

// hàm rút gọn tất cả các phân số
void Rut_Gon_Danh_Sach_Phan_So(DanhSach &ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		Rut_Gon_Phan_So(ds.arr[i]);
	}
}

// hàm tính tổng 2 phân số
PhanSo Tinh_Tong_2_Phan_So(PhanSo x, PhanSo y)
{
	PhanSo ketqua;
	if (x.mauso != y.mauso)
	{
		ketqua.tuso = (x.tuso * y.mauso) + (y.tuso * x.mauso);
		ketqua.mauso = x.mauso * y.mauso;
	}
	else
	{
		ketqua.tuso = x.tuso + y.tuso;
		ketqua.mauso = x.mauso;
	}
	return ketqua;
}

// hàm tính tổng tất cả các phân số
PhanSo Tinh_Tong_Tat_Ca_Phan_So(DanhSach ds)
{

	PhanSo ketqua = ds.arr[0];
	/*ketqua.tuso = ds.arr[0].tuso;
	ketqua.mauso = ds.arr[0].mauso;*/

	for (int i = 1; i < ds.n; i++)
	{
		ketqua = Tinh_Tong_2_Phan_So(ketqua, ds.arr[i]);
	}

	return ketqua;
}


int main()
{
	DanhSach ds; // khai báo struct danh sách phân số
	cout << "\nNhap so luong phan so: ";
	cin >> ds.n;

	// cấp phát mảng động
	ds.arr = new PhanSo[ds.n]; 

	cout << "\n\n\t\t NHAP DANH SACH PHAN SO\n";
	Nhap_Danh_Sach_Phan_So(ds);
	cout << "\n\n\t\t DANH SACH PHAN SO\n";
	Xuat_Danh_Sach_Phan_So(ds);

	cout << "\n\n\t\t DANH SACH PHAN SO SAU KHI RUT GON\n";
	Rut_Gon_Danh_Sach_Phan_So(ds);
	Xuat_Danh_Sach_Phan_So(ds);

	cout << "\n\n\n\t\t TONG TAT CA CAC PHAN SO\n";
	PhanSo ketqua;
	ketqua = Tinh_Tong_Tat_Ca_Phan_So(ds);
	Rut_Gon_Phan_So(ketqua);
	Xuat_Phan_So(ketqua);

	system("pause");
	return 0;
}