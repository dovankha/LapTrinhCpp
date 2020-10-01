/*
================== CÁC HÀM HỖ TRỢ THAO TÁC TRÊN CHUỖI ==================
1. strlen(<chuỗi cần lấy độ dài>): trả về độ dài của 1 chuỗi
2. strcpy(<chuỗi s1>, <chuỗi s2>): sao chép chuỗi s2 sang chuỗi s1
3. strdup(<chuỗi>): sao chép chuỗi - cấp phát ra 1 vùng nhớ vừa đủ để chứa cái chuỗi cần sao chép
4. strlwr(<chuỗi cần chuyển>): chuyển chuỗi thành chuỗi in thường
5. strupr(<chuỗi cần chuyển>): chuyển chuỗi thành kí tự in hoa
6. strrev(<chuỗi cần đảo ngược>): đảo ngược 1 cái chuỗi
7. strcmp(<chuỗi s1>, <chuỗi s2>): so sánh có phân biệt hoa
thường chuỗi s1 với chuỗi s2
8. stricmp(<chuỗi s1>, <chuỗi s2>): so sánh không phân biệt hoa thường chuỗi s1 với chuỗi s2
9. strcat(<chuỗi s1>, <chuỗi s2>): nối chuỗi s2 vào sau chuỗi s1
10. strstr(<chuỗi cha>, <chuỗi con>): tìm xem chuỗi con có tồn tại(nằm trong) chuỗi cha hay không
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

using namespace std;

int STRLEN(char s[]);
void STRCPY(char str_2[], char str_1[]);
char *STRDUP(char str_1[]);
void STRLWR(char str_1[]);
void STRInHoa(char str_1[]);
void Xoa(char s[], int vitrixoa);
void Hoan_Vi(char &x, char &y);
void STRREV(char s[]);
int STRCMP(char s1[], char s2[]);
void Tim_Kiem_Xoa(char str[], char temp[], char x);
char *Trim(char s[]);
char *LTrim(char s[]);
char *RTrim(char s[]);
void xoaKiTuKhoangTrangDauChuoi(char s[]);
void xoaKiTuKhoangTrangCuoiChuoi(char s[]);
int Chuyen_Doi(char s[]);
int tong1So(int number);

int main()
{
    char str_1[40];
    char str_2[40];
    char str_3[40];
    char temp[100];
    char x;
    int number;
    int sum = 0;
    cout << "Nhap chuoi: ";
    gets(str_1);
    cout << "\nChuoi nhan duoc la: " << str_1 << " -Co do dai la: " << strlen(str_1) << endl;
    // cout << "\nChuoi sau khi bo khoang trang ben trai la: " << LTrim(str_1) << endl;
    xoaKiTuKhoangTrangDauChuoi(str_1);
    cout << "\nChuoi nhan duoc la: " << str_1 << " -Co do dai la: " << strlen(str_1) << endl;

    cin.ignore(1);

    cout << "\nNhap chuoi s2: ";
    gets(str_2);
    cout << "\nChuoi nhan duoc la: " << str_2 << " -Co do dai la: " << strlen(str_2) << endl;
    xoaKiTuKhoangTrangCuoiChuoi(str_2);
    cout << "\nChuoi nhan duoc la: " << str_2 << " -Co do dai la: " << strlen(str_2) << endl;

    cin.ignore(1);
    cout << "\nNhap chuoi s3: ";
    gets(str_3);
    cout << "\nChuoi nhan duoc la: " << str_3 << " -Co do dai la: " << strlen(str_3) << endl;
    Chuyen_Doi(str_3);
    cout << "\nSo nhan duoc la: " << str_3 << " -Co do dai la: " << strlen(str_3) << endl;
    number = Chuyen_Doi(str_3);
    cout << "\nTong cua chuoi so la: " << tong1So(number) << endl;
    

    STRLWR(str_1);
    cout << "\nChuoi in thuong: " << str_1 << endl;
    STRInHoa(str_1);
    cout << "\nChuoi in hoa la: " << str_1 << endl;
    STRREV(str_1);
    cout << "\nChuoi dao nguoc la: " << str_1 << endl;

    if (STRCMP(str_1, str_2) > 0)
        cout << "\nChuoi " << str_1 << " LON hon chuoi " << str_2 << endl;
    else if (STRCMP(str_1, str_2) < 0)
        cout << "\nChuoi " << str_1 << " NHO hon chuoi " << str_2 << endl;
    else
        cout << "\nChuoi " << str_1 << " BANG " << str_2 << endl;

    cout << "\nNhap ki tu x: ";
    gets(&x);
    Tim_Kiem_Xoa(str_1, temp, x);
    cout << "\nChuoi nhan duoc la: " << temp << endl;

    getch();
    return 0;
}

int STRLEN(char s[])
{
    //int i = 0; // vị trí mà chúng ta sẽ duyệt mảng chuỗi
    //while(true)
    //{
    //	if(s[i] == '\0')
    //	{
    //		return i;
    //	}
    //	i++;
    //}

    for (int i = 0;; i++)
    {
        if (s[i] == '\0')
        {
            return i; // i chính là độ dàu của chuỗi
        }
    }
}

void STRCPY(char str_2[], char str_1[])
{
    for (int i = 0; i < strlen(str_1); i++)
    {
        str_2[i] = str_1[i]; // bỏ từng kí tự của chuỗi str_1 sang cho chuỗi str_2
    }
    str_2[strlen(str_1)] = '\0'; // nếu không có kí tự kết thúc chuỗi sẽ bị lỗi
}

// char *STRDUP(char str_1[])
// {
//     // cấp phát 1 vùng nhớ cho chuỗi str_2 sao chép các kí tự của chuỗi str_1 sang
//     char *str_2 = (char *)malloc(strlen(str_1) + 1);
//     for (int i = 0; i < strlen(str_1); i++)
//     {
//         str_2[i] = str_1[i];
//     }
//     str_2[strlen(str_1)] = '\0';
//     return str_2;
//     free(str_2); // giải phóng vùng nhớ cho chuỗi str_2
// }

void STRLWR(char str_1[])
{
    // duyệt từ đầu chuỗi đến cuối chuỗi
    for (int i = 0; i < strlen(str_1); i++)
    {
        // nếu kí tự str_1[i] là kí tự in hoa thì sẽ chuyển thành kí tự in thường bằng cách +32
        if (str_1[i] >= 'A' && str_1[i] <= 'Z')
        {
            str_1[i] = str_1[i] + 32; // chuyển kí tự in hoa thành kí tự in thường
        }
    }
}

void STRInHoa(char str_1[])
{
    // duyệt từ đầu chuỗi đến cuối chuỗi
    for (int i = 0; i < strlen(str_1); i++)
    {
        // nếu kí tự str_1[i] là kí tự in hoa thì sẽ chuyển thành kí tự in thường bằng cách +32
        if (str_1[i] >= 'a' && str_1[i] <= 'z')
        {
            str_1[i] = str_1[i] - 32; // chuyển kí tự in hoa thành kí tự in thường
        }
    }
}

void Xoa(char s[], int vitrixoa)
{
    for (int i = vitrixoa + 1; i < strlen(s); i++)
    {
        s[i - 1] = s[i];
    }
    s[strlen(s) - 1] = '\0'; // kí tự kết thúc chuỗi
}

void xoaKiTuKhoangTrangDauChuoi(char s[])
{
    while (true)
    {
        if (s[0] == ' ')
            Xoa(s, 0);
        else
            break;
    }
}

void xoaKiTuKhoangTrangCuoiChuoi(char s[])
{
    while (true)
    {
        if (s[strlen(s) - 1] == ' ')
            Xoa(s, strlen(s) - 1);
        else
            break;
    }
}

void Hoan_Vi(char &x, char &y)
{
    char temp = x;
    x = y;
    y = temp;
}

void STRREV(char s[])
{
    int dodai = strlen(s);
    for (int i = 0; i < (dodai / 2); i++)
    {
        // đổi chỗ cặp kí tự cho nhau theo công thức: s[i] hoán vị s[dodai - i - 1]
        Hoan_Vi(s[i], s[dodai - i - 1]);
    }
}

int STRCMP(char s1[], char s2[])
{
    int dodai_min = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);

    // vòng lặp duyệt từng kí tự để so sánh
    for (int i = 0; i < dodai_min; i++)
    {
        if (s1[i] > s2[i])
        {
            return 1; // chuỗi s1 lớn hơn chuỗi s2
        }
        else if (s1[i] < s2[i])
        {
            return -1; // chuỗi s1 nhỏ hơn chuỗi s2
        }
    }

    // nếu sau khi thoát khỏi vòng lặp for mà vẫn chưa phát hiện sự khác biệt thì kiểm tra độ dài
    // nếu độ dài của thằng nào dài hơn thì thằng đó lớn hơn
    if (strlen(s1) > strlen(s2))
    {
        return 1;
    }
    else if (strlen(s1) < strlen(s2))
    {
        return -1;
    }

    return 0; // 2 chuỗi có độ dài như nhau
}

void Tim_Kiem_Xoa(char str[], char temp[], char x)
{
    int dem = 0; // chỉ số của chuỗi temp
    // duyệt từ đầu chuỗi str đến cuối chuỗi str - nếu kí tự x mà trùng với kí tự nào của chuỗi str thì bỏ kí tự của chuỗi str vào chuỗi temp
    for (int i = 0; i < strlen(str); i++)
    {

        if (str[i] == x)
        {
            temp[dem] = str[i];
            dem++; // biến dem sẽ tăng lên 1 đơn vị
        }
    }
    temp[dem] = '\0'; // phải có kí tự kết thúc chuỗi - nếu không sẽ bị lỗi
}

// cat khoang trang dau va cuoi chuoi
char *Trim(char s[])
{
    int i = 0;
    while (s[i])
        i++;
    while (s[i - 1] == 32 /* Hoặc ' ' */)
        i--;
    s[i] = 0;
    while (*s == 32 /* Hoặc ' ' */)
        s++;
    return s;
}

// cat khoang trang ben trai chuoi
char *LTrim(char s[])
{
    while (*s == 32 /* Hoặc ' ' */)
        s++;
    return s;
}

// cat khoang trang ben phai chuoi
char *RTrim(char s[])
{
    int i = 0;
    while (s[i])
        i++;
    while (s[i - 1] == 32 /* Hoặc ' ' */)
        i--;
    s[i] = 0;
    return s;
}

// chuyen chuoi so nguyen thanh so nguyen
int Chuyen_Doi(char s[])
{
	float sum = 0; // chứa kết quả của số nguyên sau khi chuyển
	int mu = 0; // biến mũ của công thức 1 * 10^2 + 2 * 10^1 + 3 * 10^0 = 123
	// duyệt từ cuối chuỗi về đầu chuỗi
	for(int i = strlen(s) - 1; i >= 0; i--)
	{
		sum = sum + ( (s[i] - 48) * pow(10, mu));
		mu++; // biến mũ tăng lên 1 đơn vị
	}
	return sum; // trả về kết quả là 1 số nguyên sau khi chuyển

}

int tong1So(int number)
{
    int sum = 0;
    while (number != 0)
    {
        int i = number % 10;
        sum += i;
        number /= 10;
    }
    return sum;
}