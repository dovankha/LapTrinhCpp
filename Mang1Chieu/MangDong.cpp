#include <iostream>
#include <conio.h>
using namespace std;

void Nhap_Mang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan tu a[" << i << "]= ";
        cin >> a[i]; // <=> *(a + i)
    }
}

void Xuat_Mang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void Cap_Phat_Lai_Vung_Nho(int *&a, int vung_nho_moi, int vung_nho_cu)
{
    // Bước 1: Tạo mảng phụ temp chứa các phần tử của mảng a
    int *temp = new int[vung_nho_cu];
    for (int i = 0; i < vung_nho_cu; i++)
    {
        temp[i] = a[i]; // bỏ lần lượt các phần tử của mảng a sang cho mảng temp
    }
    // Bước 2: giải phóng vùng nhớ cũ của a đi trước
    delete[] a;
    // Bước 3: Cấp phát lại vùng nhớ mới cho a dựa vào vung_nho_moi
    a = new int[vung_nho_moi]; // cấp phát lại vùng nhớ cho mảng a với số lượng phần tử mảng là vung_nho_moi
    // Bước 4: Đổ tất cả các phần tử của mảng temp về lại cho mảng a
    for (int i = 0; i < vung_nho_cu; i++)
    {
        a[i] = temp[i];
    }
    delete[] temp; // giải phóng vùng nhớ temp khi không cần
}

// hàm thêm phần tử vào vị trí bất kì trong mảng
void Them(int *&a, int &n, int vt, int x)
{
    // trước khi thêm phần tử x vào vị trí vt - thì chúng ta cần phải nới rộng vùng nhớ ban đầu ra thêm 1 ô
    Cap_Phat_Lai_Vung_Nho(a, n + 1, n);
    // thuật toán thêm
    for (int i = n - 1; i >= vt; i--)
    {
        a[i + 1] = a[i];
    }
    a[vt] = x; // thêm phần tử x vào vị trí cần thêm
    n++;       // số lượng phần tử mảng tăng lên
}

// hàm xóa phần tử tại vị trí bất kì
void Xoa(int *&a, int &n, int vt)
{
    for (int i = vt + 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    n--; // số lượng phần tử mảng giảm 1 đơn vị

    // sau khi xóa phần tử tạu vị trí vt - thì chúng ta cần phải thu hẹp vùng nhớ ban đầu
    Cap_Phat_Lai_Vung_Nho(a, n, n);
}

int main()
{
    // int *a; // con trỏ a sẽ quản lí cái mảng động của chúng ta
    int n;  // số lượng phần tử của mảng

    // vòng lặp nhập số lượng phần tử mảng
    do
    {
        cout << "\nNhap so luong phan tu mang: ";
        cin >> n;

    } while (n <= 0);

    // cấp phát vùng nhớ cho con trỏ a <=> tạo mảng động
    int *a = new int[n]; // cấp phát ra mảng động có n ô nhớ

    cout << "\n\n\t\t NHAP MANG\n";
    Nhap_Mang(a, n);
    cout << ("\n\n\t\t XUAT MANG\n");
    Xuat_Mang(a, n);

    /*int x;
	cout << "\nNhap phan tu can them: ";
	cin >> x;
	int vt;
	cout << "\nNhap vi tri can them: ";
	cin >> vt;
	Them(a, n, vt, x);
	cout << "\n\n\t\t MANG SAU KHI THEM\n";
	Xuat_Mang(a, n);*/

    int vt;
    cout << "\nNhap vi tri can xoa: ";
    cin >> vt;
    Xoa(a, n, vt);
    cout << "\n\n\t\t MANG SAU KHI XOA\n";
    Xuat_Mang(a, n);

    delete[] a; // giải phóng vùng nhớ cho mảng a
    getch();
    return 0;
}