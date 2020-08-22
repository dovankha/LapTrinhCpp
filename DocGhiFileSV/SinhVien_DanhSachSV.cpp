#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

struct monHoc
{
	string tenMonHoc;
	float diem = 0;
};

struct sinhVien
{
	string ten, MSSV, birth;
	vector <monHoc> listMonHoc; // mang 1 chieu cac mon hoc
};

void docThongTinSV(ifstream& inPut, sinhVien& sv)
{
	getline(inPut, sv.ten, ','); // doc toi dau ',' thi dung
	getline(inPut, sv.MSSV, ',');
	getline(inPut, sv.birth);
}

void docThongTinMonHoc(ifstream& inPut, monHoc& mon)
{
	getline(inPut, mon.tenMonHoc, '-');
	inPut >> mon.diem;
}

void docFile(ifstream& inPut, vector <sinhVien>& danhSachSV)
{
	while (inPut.eof() == false)
	{
		sinhVien sv;
		int n = 0; // so luong mon hoc
		//b1: doc thong tin cua 1 sinh vien
		docThongTinSV(inPut, sv);
		//b2: doc so luong mon hoc
		inPut >> n;
		string temp;
		getline(inPut, temp);
		//b3: doc danh sach cac mon hoc
		for (int i = 1; i <= n; i++)
		{
			monHoc mon;
			docThongTinMonHoc(inPut, mon);
			getline(inPut, temp); // lay dau enter cuoi cung.
			sv.listMonHoc.push_back(mon); // them 1 mon hoc vao cuoi mang vector listMonHoc cua sinh vien tuong ung.
		}
		//b4: them thong tin sinh vien. (bao gom: thong tin sv + danhsach mon hoc cua sinh vien)
		danhSachSV.push_back(sv); // them sinh vien vao cuoi mang
	}
}

// ham TEST xuat du lieu sinh vien ra man hinh 

void xuatThongTinSV(sinhVien sv)
{
	cout << "\nHo ten sinh vien: " << sv.ten << endl;
	cout << "MSSV: " << sv.MSSV << endl;
	cout << "Date of Birth: " << sv.birth << endl;
}

void xuatThongTinMonHoc(monHoc mon)
{
	cout << "\nTen mon hoc: " << mon.tenMonHoc << endl;
	cout << "Diem: " << mon.diem << endl;
}

void test(vector<sinhVien> danhSachSV)
{
	for (int i = 0; i < danhSachSV.size(); i++)
	{
		cout << "\n==== SINH VIEN THU " << i + 1 << "=====" << endl;
		xuatThongTinSV(danhSachSV[i]);
		for (int j = 0; j < danhSachSV[i].listMonHoc.size(); j++)
		{
			cout << "\n###### MON HOC THU " << j + 1 << endl;
			xuatThongTinMonHoc(danhSachSV[i].listMonHoc[j]);
		}
	}
}

// void timKiemSinhVienTheoTen(vector<sinhVien> ds, string ten)
// {
// 	int dem = 1;
// 	for (int i = 0; i < ds.size(); i++)
// 	{
// 		if (stricmp(ds[i].ten.c_str(), ten.c_str()) == 0)
// 		{
// 			cout << "\n$$$$ Sinh Vien Thu: " << dem++;
// 			xuatThongTinSV(ds[i]);
// 			int n = ds[i].listMonHoc.size();
// 			for (int j = 0; j < n; j++)
// 			{
// 				cout << "\n### Mon Hoc Thu: " << j + 1;
// 				xuatThongTinMonHoc(ds[i].listMonHoc[j]);
// 			}
// 		}
// 	}
// }

string tachNamSinh(string str)
{
	string temp;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] >= '0' && str[i] <= '9')
			temp.insert(temp.begin() + 0, str[i]);
		else
			break;
	}
	return temp;
}

void ghiThongTinMonHoc(ofstream& outPut, monHoc mon)
{
	outPut << mon.tenMonHoc << "-" << mon.diem << endl;
}

void ghiThongTinSinhVien(ofstream& outPut, sinhVien sv)
{
	outPut << sv.ten << ", " << sv.MSSV << ", " << sv.birth << endl;
	outPut << sv.listMonHoc.size() << endl;
	for (int i = 0; i < sv.listMonHoc.size(); i++)
	{
		ghiThongTinMonHoc(outPut, sv.listMonHoc[i]);
		//outPut << endl;
	}
}

// void saveFile_NamSinh(ofstream& outPut, vector<sinhVien> ds, string birth)
// {
// 	for (int i = 0; i < ds.size(); i++)
// 	{
// 		string temp = tachNamSinh(ds[i].birth);
// 		if (stricmp(temp.c_str(), birth.c_str()) == 0)
// 		{
// 			xuatThongTinSV(ds[i]);
// 			ghiThongTinSinhVien(outPut, ds[i]);
// 		}
// 	}
// }

int main()
{
	ifstream inPut;
	ofstream outPut;
	string ten, namSinh;
	inPut.open("D:\\KyThuat_C++\\DocGhiFileSV\\SinhVien.txt", ios_base::in);
	vector <sinhVien> danhSachSV;
	docFile(inPut, danhSachSV);
	cout << "InPut seccussfull!" << endl;
	cout << "\nNhap ten sinh vien can tim kiem: ";
	getline(cin, ten);
	// timKiemSinhVienTheoTen(danhSachSV, ten);

	test(danhSachSV);
	outPut.open("D:\\KyThuat_C++\\DocGhiFileSV\\NamSinh.txt", ios_base::app);
	cout << "\nNhap vao nam sinh: ";
	getline(cin, namSinh);
	// saveFile_NamSinh(outPut, danhSachSV, namSinh);

	inPut.close();
	outPut.close();
	system("pause");
	return 0;
}