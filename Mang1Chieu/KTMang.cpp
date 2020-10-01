#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

const int MAX = 100;

void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
void them(int a[], int &n, int x, int viTri);
void xoa(int a[], int &n, int x);
void timKiem(int a[], int n, int x);
void xoaPTNhoHonx(int a[], int &n, int &x);
void hoanVi(int &a, int &b);
void sapXepTang(int a[], int n);

int main()
{
    int a[MAX];
    int n, vtThem, vtXoa, x, tkiem, xoaX;

    do
    {
        cout << "Nhap so luong phan tu mang: ";
        cin >> n;
        if (n <= 0 || n > 100)
        {
            cout << "\nSo luong phan tu mang khong hop le!";
            getch();
        }
    } while (n <= 0 || n > 100);

    cout << "\n\n\t\t NHAP MANG\n";
    nhapMang(a, n);
    cout << "\n\n\t\t XUAT MANG\n";
    xuatMang(a, n);

    cout << "\nNhap gia tri can them: ";
    cin >> x;
    cout << "\nNhap vi tri can them: ";
    cin >> vtThem;

    them(a, n, x, vtThem);
    cout << "\n\n\t\t XUAT MANG SAU KHI THEM\n";
    xuatMang(a, n);

    cout << "\nNhap phan tu can tim kiem: ";
    cin >> tkiem;

    cout << "\nvi tri cua phan tu can tim la: ";
    timKiem(a, n, tkiem);

    cout << "\nNhap vao vi tri can xoa (tinh tu 0): ";
    cin >> vtXoa;
    xoa(a, n, vtXoa);
    cout << "\nMang sau khi xoa la: ";
    xuatMang(a, n);

    cout << "\nMang sau khi sap xep TANG la: ";
    sapXepTang(a, n);
    xuatMang(a, n);

    getch();
    return 0;
}

void nhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap gia tri a[" << i << "]= ";
        cin >> a[i];
    }
}

void xuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void them(int a[], int &n, int x, int viTri)
{
    if (viTri < 0)
        viTri = 0;
    else if (viTri > n)
        viTri = n;

    for (int i = n; i > viTri; i--)
    {
        a[i] = a[i - 1];
    }
    a[viTri] = x;
    n++;
}

void xoa(int a[], int &n, int viTri)
{
    if (viTri < 0)
        viTri = 0;
    else if (viTri > n)
        viTri = n;

    for (int i = viTri; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    --n;
}

void timKiem(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            cout << i << " ";
    }
}

void sapXepTang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                hoanVi(a[i], a[j]);
        }
    }
}

void hoanVi(int &a, int &b)
{
    int temp = a;
    a = b; 
    b = temp;
}
