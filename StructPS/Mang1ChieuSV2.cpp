#include <iostream>
#include <string>
using namespace std;

struct sinhVien
{
    string ten, MSSV;
    float diemTB = 0; 
};

void nhapThongTin(sinhVien& info)
{
    cout << "\n-------NHAP THONG TIN SINH VIEN---------\n" << endl;
    while (getchar() != '\n');
    do
    {
        cout << "Nhap vao HO & TEN cua ban: ";
        getline(cin, info.ten);
        if (info.ten.length() > 30)
            cout << "Ten ban qua dai.Vui long nhap lai!" << endl;
    } while (info.ten.length() > 30);

    do
    {
        cout << "Nhap vao MSSV cua ban: ";
        getline(cin, info.MSSV);
        if (info.MSSV.length() > 15)
            cout << "MSSV khong hop le. Vui long nhap lai!" << endl;
    } while (info.MSSV.length() > 15);

    do
    {
        cout << "Nhap vao diem trung binh cua ban: ";
        cin >> info.diemTB;
        if (info.diemTB < 0 || info.diemTB > 10)
            cout << "Diem TB cua ban khong hop le. Vui long nhap lai!" << endl;
    } while (info.diemTB < 0 || info.diemTB > 10);
}

void xuatThongTin(sinhVien info)
{
    cout << "\n-------THONG TIN SINH VIEN--------\n" << endl;
    cout << "HO & TEN: " << info.ten << endl;
    cout << "MSSV: " << info.MSSV << endl;
    cout << "Diem TB: " << info.diemTB << endl;
}

void nhapDanhSachSV(sinhVien a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n\n\t****** NHAP THONG TIN SINH VIEN THU " << i + 1 << " ******" << endl;
        nhapThongTin(a[i]);
    }
}

void xuatDanhSachSV(sinhVien a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n\n\t****** XUAT THONG TIN SINH VIEN THU " << i + 1 << " ******" << endl;
        xuatThongTin(a[i]);
    }
}

void timSVTheoDiemTB(sinhVien a[], int n, float diem)
{
    int dem = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i].diemTB == diem)
        {
            cout << "\n\n\t****** THONG TIN SINH VIEN THU " << dem++ << " ******" << endl;
            xuatThongTin(a[i]);
        }
    }
}

void themSV(sinhVien a[], int& n, int viTri, sinhVien x)
{
    for (int i = n - 1; i >= viTri; i--)
    {
        a[i + 1] = a[i];
    }
    a[viTri] = x;
    n++;
}

void xoaSV(sinhVien a[], int& n, int viTri)
{
    for (int i = viTri + 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    n--;
}

void xoaSVDiem5(sinhVien a[], int& n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].diemTB < 5)
        {
            xoaSV(a, n, i);
            i--;
        }
    }
}

void hoanVi(sinhVien& x, sinhVien& y)
{
    sinhVien temp;
    temp = x;
    x = y;
    y = temp;
}

void sapXepTheoDiemTB(sinhVien a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].diemTB > a[j].diemTB)
                hoanVi(a[i], a[j]);
        }
    }
}

int main()
{
    sinhVien a[100];
    int n, viTri;
    float diem;
    sinhVien x;

    cout << "Nhap vao so luong sinh vien: ";
    cin >> n;

    nhapDanhSachSV(a, n);
    xuatDanhSachSV(a, n);

    cout << "\nNhap diem can tim: ";
    cin >> diem;
    timSVTheoDiemTB(a, n, diem);

    cout << "\n----------------------------------" << endl;

    cout << "Nhap vao vi tri can them sinh vien: ";
    cin >> viTri;
    nhapThongTin(x);
    themSV(a, n, viTri, x);
    xuatDanhSachSV(a, n);

    sapXepTheoDiemTB(a, n);

    cout << "\n\n\t=======DANH SACH SAU KHI SAP XEP========" << endl;
    xuatDanhSachSV(a, n);

    system("pause");
    return 0;
}