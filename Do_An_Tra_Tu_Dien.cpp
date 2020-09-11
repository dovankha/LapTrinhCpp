#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <conio.h>
#include <Windows.h>
#define manh 26
#define LenWord 25
#define LenMean 45
#define LenWordType 25
#define LenExample 100
#define TRUE 1
#define FALSE 0
#define boxx 5	 //Vi tri x bat dau cua box
#define boxy 2	 //Vi tri y bat dau cua box
#define boxx1 55 //Vi tri x bat dau cua box
#define boxy1 2	 //Vi tri y bat dau cua box
#define boxs 40	 //Box size
#define boxw 15	 //So tu hien thi trong khung ket qua tim kiem
#define boxs1 57 //Box size
#define boxw1 24 //So tu hien thi trong khung ket qua tim kiem
#define boxxmini 50
#define boxymini 2
#define boxsmini 20
#define boxwmini 3
#define MAUCHU 2
#define MAUNEN 125
#define MAUCANHBAO 4
typedef char sizethaotac[100];
enum TRANGTHAI
{
	DOWN,
	UP,
	RIGHT,
	LEFT,
	ENTER,
	ESC,
	FIND,
	BACKSPACE,
	BACK,
	SET,
	XOA
};
bool capnhat = FALSE;
// insert ordered de tu dong sap xep

//..........................................Khai bao cac cau truc struct....................................................

// khai bao nghia cua tu
struct Mean
{
	char mean[LenMean];
	Mean *Next;
};
typedef Mean *MPTR;

// khai bao struct Word
struct Word
{
	char word[LenWord];
	char word_type[LenWordType];
	MPTR First;
	char *example[5] = {NULL};
};

// tao 1 node word cho danh sach
struct Node
{
	Word word;
	Node *Left;
	Node *Right;
};
typedef Node *DPTR;

// tao struct danh sach cac node
struct List_Word
{
	DPTR First;
	DPTR Last;
};
typedef List_Word LW;
//LW D[manh]; // khai bao 26 mang chu danh sach tu

//.............................................Cac ham thuc thi............................................................

int Kbhit();				   // lay ma ASCII
int H();					   // ham bam
void InitLM();				   // Khoi tao Null cho danh sach mean
void Init(LW &l);			   // khoi tao Null cho 1 danh sach word
void InitLW();				   // khoi tao Null cho 26 mang chua tung danh sach word
int Empty_Mean_List();		   // kiem tra rong cua danh sach mean
int Empty_Word_List(LW L);	   // kiem tra rong cua danh sach tu
MPTR Make_Mean_Set();		   // tao 1 nut chua 1 gia tri cua nghia
int Len_Mean_List();		   // Do dai cua danh sach mean cua 1 word
int Len_Word_List();		   // do dai danh sach tu
void Insert_First_Mean();	   // chen 1 mean vao dau danh sach
void Insert_First_Word_List(); // chen 1 word vao dau danh sach
void Traverse();			   // show danh sach mean
MPTR MeanPointer();			   // di chuyen con tro den vi tri k cua danh sach nghia
int Fix_k_Mean();			   //chen 1 nghia vao vi tri k
DPTR Make_Node_Set();		   // tao 1 node voi gia tri x
int FindWord();				   // tim kiem 1 word
void Load_File(LW D[]);
void Save_File(LW D[]);
void gotoxy(int, int);
void textcolor(int);
TRANGTHAI key(int);
void show2(Word);
void khungchitiet();
int H(char a[]);
TRANGTHAI menu1(LW D[], char a[]);
TRANGTHAI Yes_No(char a[], int, int);
int Xuat_Chuoi(char a[], int, int, int, int);

void khung(int x, int y, int dai, int rong)
{
	gotoxy(x, y);
	printf("%c", char(201));
	for (int i = 1; i <= rong; i++)
	{
		printf("%c", char(205));
	}
	printf("%c", char(187));
	gotoxy(x, y + 1);
	for (int j = 1; j <= dai; j++)
	{
		gotoxy(x, y + j);
		printf("%c", char(186));
		gotoxy(x + rong + 1, y + j);
		printf("%c", char(186));
	}
	gotoxy(x, y + dai + 1);
	printf("%c", char(200));
	for (int k = 1; k <= rong; k++)
	{
		printf("%c", char(205));
	}
	printf("%c", char(188));
}
void Thanh_I(int x, int y, int len)
{
	gotoxy(x, y);
	printf("%c", char(203));
	for (int i = 1; i <= len; i++)
	{
		gotoxy(x, y + i);
		printf("%c", char(186));
	}
	gotoxy(x, y + len + 1);
	printf("%c", char(202));
}
void Thanh_H(int x, int y, int len)
{
	gotoxy(x, y);
	printf("%c", char(204));
	for (int i = 1; i <= len; i++)
	{
		gotoxy(x + i, y);
		printf("%c", char(205));
	}
	gotoxy(x + len + 1, y);
	printf("%c", char(185));
}
void xoakhung(int x, int y, int dai, int rong)
{
	for (int i = 0; i < dai + 2; i++)
	{
		gotoxy(x, y + i);
		for (int j = 0; j < rong + 2; j++)
		{
			gotoxy(x + j, y + i);
			printf(" ");
		}
	}
}
int Show_Wordmanhk(LW D, int k, char mangchu[])
{
	DPTR s1;
	int dem = 0;

	for (s1 = D.First; s1 != NULL; s1 = s1->Right)
	{
		if (strnicmp(s1->word.word, mangchu, strlen(mangchu)) == 0)
		{
			dem++;
			if (dem == k)
			{
				show2(s1->word);
				return 1;
			}
		}
	}
	gotoxy(boxx1 + 1, boxy1 + 2);
	printf("Tu khong ton tai");
	return 0;
}
int Show_Wordk(LW D[], int k)
{
	DPTR s1;
	int dem = 0;
	for (int i = 0; i < manh; i++)
	{

		for (s1 = D[i].First; s1 != NULL; s1 = s1->Right)
		{
			dem++;
			if (dem == k)
			{
				show2(s1->word);
				return 1;
			}
		}
	}
	printf("Vi tri k khong ton tai tu");

	return 0;
}

int Show_Find(char a[], LW D, int vtstart, int mau1[], char tudautien[])
{
	DPTR s;
	int x = boxx + 1; // vi tri x xuat
	int y = boxy + 3;
	int vt = 0; // dung de biet so phan tu trong thoa man;
	int dem = 0;
	bool nhotudautien = TRUE;
	gotoxy(boxx + 1, boxy + 3);
	textcolor(mau1[1]);
	printf("                                        ");
	for (s = D.First; s != NULL; s = s->Right)
	{
		if (strnicmp(a, s->word.word, strlen(a)) == 0)
		{
			vt++;
			if (vt >= vtstart && dem != 14)
			{

				gotoxy(x, y);
				textcolor(mau1[++dem]);
				printf(" %s", s->word.word);
				if (nhotudautien)
				{
					strcpy(tudautien, s->word.word);
					nhotudautien = FALSE;
				}
				y++;
			}
		}
	}
	return vt;
}
int chuoi(LW D[], int mau1[], int vtstart, char tunho[])
{
	int x = boxx + 1; // vi tri x xuat
	int y = boxy + 3; // vi tri y xuat
	int dem = 0;
	int size = 0;
	bool tunhodautien = TRUE;
	gotoxy(boxx + 1, boxy + 3);
	textcolor(mau1[1]);
	printf("                                        ");
	for (int i3 = 0; i3 < manh; i3++)
	{
		DPTR s;
		for (s = D[i3].First; s != NULL; s = s->Right)
		{
			size++;
			if (dem != 14 && size >= vtstart)
			{
				gotoxy(x, y);
				textcolor(mau1[++dem]);
				printf(" %s", s->word.word);
				if (tunhodautien)
				{
					strcpy(tunho, s->word.word);
					tunhodautien = FALSE;
				}
				y++;
			}

			else if (dem == 14)
				break;
		}
	}
	return size;
}

TRANGTHAI Find_Word_Main(LW D[], int n)
{
	char tunho[LenWord];
	bool chedo = FALSE, chedomini = FALSE;
	char mangchu[50] = {0};
	int ptrfind = 0; // con tro o t�m ki�m
	int demkytu = 0;
	int vtstart = 1;
	int vtstartmanh = 1;
	int *mau1 = (int *)calloc(n + 1, sizeof(int));
	for (int i1 = 0; i1 <= n; i1++)
	{
		mau1[i1] = MAUCHU;
	}
	mau1[1] = MAUNEN;
	TRANGTHAI trangthai = SET;
	while (1)
	{
		char cc;
		int c, vt;
	Nhan:
		textcolor(0);
		for (int i2 = 0; i2 < n; i2++) // xoa man hinh
		{
			gotoxy(boxx + 1, boxy + 3 + i2);
			printf("                                        ");
		}
		if (chedo) // hien thi cac tu tim kiem trong 1 manh
		{
			vt = Show_Find(mangchu, D[H(mangchu)], vtstartmanh, mau1, tunho);
		}
		else
		{ // hien thi cac tu tim kiem tong 26 manh
			vt = chuoi(D, mau1, vtstart, tunho);
		}
		if (chedomini)
		{
			textcolor(0);
			xoakhung(boxx1, boxy1, boxw1, boxs1);
			trangthai = menu1(D, tunho);
			textcolor(MAUCHU);
			xoakhung(boxxmini, boxymini, boxwmini, boxsmini);
			chedomini = FALSE;
			goto Nhan;
		}

		textcolor(mau1[0]);			   //
		gotoxy(boxx + boxs, boxy + 1); //		hien thi dau >>;
		printf("%c", char(175));
		gotoxy(boxx + 12, boxy + 1);
		printf("                          ");		   //xoa chuoi o tim kiem
		gotoxy(boxx + 12, boxy + 1);				   // con tro ve o tim kiem
		printf("%s", mangchu);						   // hien thi chuoi o tim ki�m
		gotoxy(boxx + 12 + strlen(mangchu), boxy + 1); // di chuyen con tro v� sau chuoi;

		if (trangthai != ESC)
		{
			c = getch();
			trangthai = key(c);
		}
		switch (trangthai)
		{
		case UP:
		{
			if (chedo && !chedomini)
			{
				if (vtstartmanh != 1)
					vtstartmanh--;
			}
			else if (!chedo && !chedomini)
			{
				if (vtstart != 1)
					vtstart--;
			}
			mau1[0] = MAUCHU;
			break;
		}
		case DOWN:
		{
			if (chedo)
			{
				if (vtstartmanh != vt)
					vtstartmanh++;
			}
			else
			{
				if (vtstart != vt)
					vtstart++;
			}
			mau1[0] = MAUCHU;
			break;
		}
		case RIGHT:
		{
			gotoxy(boxx + boxs, boxy + 1);
			chedomini = TRUE;
			break;
		}
		case LEFT:
		{
			chedomini = FALSE;
			break;
		}
		case ESC:
		{
			return ESC;
		}

		case ENTER:
			if (chedo)
			{
				Show_Wordmanhk(D[H(mangchu)], vtstartmanh, mangchu);
			}
			else
			{
				Show_Wordk(D, vtstart);
			}
			break;
		case FIND:
		{
			if (ptrfind != LenWord)
			{
				mangchu[ptrfind++] = c;
				vtstartmanh = 1;
			}
			chedo = TRUE;
			break;
		}
		case BACKSPACE:
		{
			if (ptrfind != 0)
			{
				mangchu[--ptrfind] = 0;
			}
			else
			{
				break;
			}
			if (ptrfind == 0)
			{
				chedo = FALSE;
				vtstart = 1;
			}
			break;
		}
		default:
			break;
		}
	}
}

int Kbhit()
{
	int ch, buff;
	while (!kbhit())
		;
	ch = getch();
	buff = getch();
	if (ch == 224)
	{
		return buff;
	}
	else
		return ch;
}

int H(char a[])
{
	int b;
	if ('A' <= a[0] && a[0] <= 'Z')
	{
		b = a[0] - 'A';
	}
	if ('a' <= a[0] && a[0] <= 'z')
	{
		b = a[0] - 'a';
	}
	return b;
}

void InitLM(MPTR &First)
{
	First = NULL;
}

MPTR Make_Mean_Set(char x[])
{
	MPTR m;
	m = (MPTR)malloc(sizeof(Mean));
	strcpy(m->mean, x);
	return (m);
}

int Empty_Mean_List(MPTR First)
{
	return ((First == NULL) ? TRUE : FALSE);
}

int Len_Mean_List(MPTR L)
{
	int i = 0;
	while (Empty_Mean_List(L) != 1)
	{
		i++;
		L = L->Next;
	}
}

void Insert_First_Mean(MPTR &First, char a[])
{
	MPTR m;
	m = Make_Mean_Set(a);
	m->Next = First;
	First = m;
}

int Traverse(MPTR First)
{
	int i = 0;
	MPTR m = First;
	if (m == NULL)
	{
		printf("\nDanh sach nghia rong");
	}
	while (m != NULL)
	{
		gotoxy(boxx1 + 2, boxy1 + 6 + 2 * i);
		i++;
		printf("Mean %d   : %s", i, m->mean);
		m = m->Next;
	}
	return i;
}

MPTR MeanPointer(MPTR First, int k)
{
	MPTR m;
	int vitri = 1;
	m = First;
	while (m != NULL && vitri < k)
	{
		m = m->Next;
		vitri++;
	}
	return m;
}

//int Fix_k_Mean(MPTR &First,char a[],int k){
//	if(k<1&&k>Len_Mean_List(First))
//	{
//		printf("Vi tri them ngoai pham vi cho phep");
//	}
//	else
//	{
//		MPTR m;
//		m=MeanPointer(First,k);
//		strcpy(m->mean,a);
//	}
//
//}

void Init(LW &l)
{

	l.First = NULL;
	l.Last = NULL;
}

void InitLW(LW *D)
{
	int j;
	for (j = 0; j < manh; j++)
	{
		Init(*(D + j));
	}
}

DPTR Make_Node_Set(Word x)
{
	DPTR D;
	D = (DPTR)malloc(sizeof(Node));
	D->word = x;
	D->Right = NULL;
	D->Left = NULL;
	return (D);
}

int Empty_Word_List(LW L)
{
	return ((L.First == NULL) ? TRUE : FALSE);
}

void Insert_First_Word_List(LW D[], Word x)
{
	DPTR D1;
	D1 = Make_Node_Set(x);
	int bucket;
	bucket = H(x.word);
	if (Empty_Word_List(D[bucket]))
	{
		D[bucket].First = D1;
		D[bucket].Last = D1;
	}
	else
	{
		D1->Right = D[bucket].First;
		D[bucket].First->Left = D1;
		D[bucket].First = D1;
	}
}

int Insert_Right_Node(LW D[], DPTR p, Word x)
{
	char a[25];
	strcpy(a, x.word);
	DPTR q, r;
	if (p == NULL)
		printf("\nNut khong hien huu, khong them nut");
	else
	{
		q = Make_Node_Set(x);
		r = p->Right;
		if (r == NULL)
		{
			q->Left = p;
			p->Right = q;
			D[H(a)].Last = q;
		}
		else
		{
			r->Left = q;
			q->Right = r;
			q->Left = p;
			p->Right = q;
		}
	}
}

int Insert_Order_Word_List(LW D[], Word x)
{
	DPTR s, t;
	for (s = D[H(x.word)].First; s != NULL && stricmp(s->word.word, x.word) < 0; t = s, s = s->Right)
		;
	if (s == D[H(x.word)].First)
	{
		Insert_First_Word_List(D, x);
	}
	else
	{
		Insert_Right_Node(D, t, x);
	}
}

int Len_Word_List(LW l)
{
	int x = 0;
	while (l.First != NULL)
	{
		x++;
		l.First = l.First->Right;
	}
	return x;
}

DPTR FindWord(char a[], LW D[])
{
	int bucket = H(a);
	DPTR ss;
	//	ss=D[bucket].First;
	for (ss = D[bucket].First; ss != NULL && stricmp(a, ss->word.word) != 0; ss = ss->Right)
		;
	return ss;
	//	while(ss!=NULL){
	//		if(!(stricmp(b,ss->word.word)))
	//		{
	//			return 1;
	//		}
	//
	//		ss=ss->Right;
	//	}
	//	return 0;
}
int demdong(char a[])
{
	int dong = strlen(a) / (boxs1 - 2);
	int du = strlen(a) % (boxs1 - 2);
	if (du != 0)
		dong++;
	return dong;
}
int vv(char a[])
{ // tra ve vi tri co khoang trang trong chuoi
	int i;
	for (i = (boxs1 - 13) - 1; i > 0; i--)
	{
		if (a[i] == ' ')
			return i;
	}
	return 0;
}

//.......................................Input/Output...................................................................

void show2(Word x)
{
	int dong = 0, i, dotangkhung = 0;
	xoakhung(boxx1, boxy1, boxw1 + 4, boxs1);

	gotoxy(boxx1 + 2, boxy1 + 2);
	printf("Word     : %s", x.word);
	gotoxy(boxx1 + 2, boxy1 + 4);
	printf("Type     : %s", x.word_type);
	int w = Traverse(x.First);
	for (i = 0; x.example[i] != NULL && i < 5; i++)
	{
		gotoxy(boxx1 + 2, boxy1 + 6 + 2 * w + dong + i);
		printf("Example %d: ", i + 1);
		Xuat_Chuoi(x.example[i], boxx1 + 13, 43, boxy1 + 6 + 2 * w + dong + i, strlen(x.example[i]) / 43 + 1);
		dong = dong + strlen(x.example[i]) / 43 + 1;
	}

	if ((5 + 2 * w + dong + i) > boxw1)
	{
		dotangkhung = 5 + 2 * w + dong + i - boxw1;
	}
	khung(boxx1, boxy1, boxw1 + dotangkhung, boxs1);
}
void showD(LW D[])
{
	int i, j;
	DPTR s;
	for (i = 0; i < manh; i++)
	{
		s = D[i].First;
		printf("Lop %d: ", i);
		if (s == NULL)
		{
			printf("NULL");
		}
		while (s != NULL)
		{
			show2(s->word);
			s = s->Right;
		}

		printf("\n");
	}
	getch();
}

// show struct Word
void chuanhoachuoi(char a[])
{
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			for (int j = i + 1; j < strlen(a); j++)
			{
				a[j] = a[j + 1];
			}
			i--;
		}
		if (a[i] >= 'A' && a[i] <= 'Z')
		{
			a[i] = a[i] - 'A' + 'a';
		}
	}
	if (a[0] == ' ')
	{
		for (int i = 0; i < strlen(a); i++)
		{
			a[i] = a[i + 1];
		}
	}
	if (a[strlen(a) - 1] == ' ')
		a[strlen(a) - 1] = 0;
}
void Dich_Trai(char a[], int vitridung)
{

	for (int i = 0; i < vitridung; i++)
	{
		a[i] = a[i + 1];
	}
}
void Dich_Phai(char a[], int vitridung)
{
	int v = strlen(a);
	for (int i = v; i >= vitridung; i--)
	{
		a[i + 1] = a[i];
	}
	a[v + 1] = 0;
}
//void Xuat_Chuoi(char a[],int xstart,int xend,int ystart,int yend)
//{
//	int rong=xend-xstart+1;
//	int dai=yend-ystart+1;
//	int dong=1,x;
//	if(strlen(a)<=rong)
//	{
//		printf("%s",a);
//	}
//	else
//	{
//		x=strlen(a);
//		do{
//			x=x-rong;
//			dong++;
//		}while(x>rong);
//		int j=0,m;
//		for(int i=0;i<dong;i++)
//		{
//			int demkytuxuat=1;
//			if(i>=dai) break;
//			gotoxy(xstart,ystart+i);
//
//			do{
//				printf("%c",a[j++]);
//				demkytuxuat++;
//			}while(demkytuxuat<=rong);
//
//		}
//	}
//
//}
//void Nhap_Chuoi(char a[],int Len,int line){
//	int c;
//	bool chedo=TRUE;
//	a[0]=0;
//	int khoangtrang1=0;
//	int dem=0;
//	int vtptr=0;
//	while(1)
//	{
//		c=getch();
//		TRANGTHAI trangthai=key(c);
//		switch(trangthai)
//		{
//		case ENTER:
//		{
//			break;
//		}
//		case FIND:
//		{
//			if(strlen(a)==Len-1||dem==Len)
//			{
//				break;
//			}
//			if(dem<strlen(a))
//			{	chedo=FALSE;
//				for(int i=strlen(a);i>=dem;i--)
//				{
//					a[i+1]=a[i];
//				}
//			}
//			if(c>='a'&&c<='z'||c==' ')
//			{
//				a[dem++]=c;
//			}
//			if(c>='A'&&c<='Z')
//			{
//				a[dem++]=c-'A'+'a';
//			}
//			if(chedo)
//			{
//				a[dem]=0;
//			}
//			gotoxy(boxx1+8,boxy1+line);
//			printf("                                   ");
//			gotoxy(boxx1+8,boxy1+line);
//			printf("%s",a);
//			gotoxy(boxx1+8+dem,boxy1+line);
//			break;
//		}
//		case LEFT:
//		{
//			if(dem==0) break;
//			dem--;
//			gotoxy(dem+boxx1+8,boxy1+line);
//
//			break;
//		}
//		case BACKSPACE:
//		{
//			if(dem==0) break;
//			gotoxy(boxx1+7+dem,boxy1+line);
//			printf(" ");
//			gotoxy(boxx1+7+dem,boxy1+line);dem--; // loi xoa
//			for(int i=dem;i<strlen(a);i++)
//			{
//				a[i]=a[i+1];
//			}
//
//			if(dem==strlen(a)-1)
//			{
//				a[dem]=0;
//			}
//
//			break;
//		}
//		case RIGHT:
//			{
//				gotoxy(50,5);
//				chuanhoachuoi(a);
//				printf("%s",a);
//				gotoxy(boxx1+7+strlen(a)+1,boxy1+line);
//				break;
//			}
//	}
//	}
//}
void Xoa_Ky_Tu(char a[], int t)
{
	for (int i = t - 1; i < strlen(a); i++)
	{
		a[i] = a[i + 1];
	}
}
int Xuat_Chuoi(char a[], int xstart, int rong, int ystart, int dai)
{
	int dong = 1, x = strlen(a);
	if (strlen(a) <= rong)
	{
		gotoxy(xstart, ystart);
		printf("%s", a);
	}
	else
	{
		dong = x / rong + 1;
		x = x % rong;
		int j = 0;
		if (dong > dai)
			dong = dai;
		for (int i = 0; i < dong; i++) // xuat ra chuoi tung dong
		{
			int demkytuxuat = 1;
			gotoxy(xstart, ystart + i);
			while (demkytuxuat <= rong && j != strlen(a)) //do
			{
				printf("%c", a[j]); // in ky tu thu j ra man hinh
				if ((a[j] != ' ') && (a[j + 1] != ' ') && (demkytuxuat == rong))
				{
					while (a[j] != ' ')
					{
						j--;
						gotoxy(xstart + demkytuxuat - 1, ystart + i);
						printf(" ");
						demkytuxuat--;
					}
					j++;
					break;
				}
				demkytuxuat++;
				j++;
			}
		}
	}
	return dong;
}
TRANGTHAI Nhap_Chuoi_Fix(char a[], int Len_Chuoi, int Len_Show, int xstart, int rong, int ystart, int dai)
{
	textcolor(MAUCHU);
	int c;
	int vtptr = 0, vt = 0;
	char b[Len_Chuoi];
	b[0] = '\0';
	//	char d[Len_Chuoi];d[0]=0;
	for (int i = 0; i < Len_Show; i++)
	{
		gotoxy(xstart + i, ystart);
		printf(" ");
	}
	if (strlen(a) != 0)
	{ // show ra chuoi

		strcpy(b, a);
		vtptr = strlen(a);
		if (strlen(a) > Len_Show)
		{
			vt = Len_Show - 1;
			for (int i = 0; i < vtptr - Len_Show; i++)
			{
				Dich_Trai(b, strlen(b));
			}
			b[Len_Show] = '\0';
		}
		else
		{
			vt = strlen(a);
		}
		gotoxy(xstart, ystart);
		printf("%s", b);
	}
	else
	{
		a[0] = '\0';
	}
	bool chedochen = FALSE; // khoi tao che do chen off
	TRANGTHAI trangthai;
	gotoxy(xstart + vt, ystart);
	while (1)
	{
		fflush(stdin);
		c = getch();
		trangthai = key(c);
		switch (trangthai)
		{
		case ENTER:
		{
			chuanhoachuoi(a);
			return ENTER;
		}
		case DOWN:
		{
			chuanhoachuoi(a);
			return DOWN;
		}
		case UP:
		{
			chuanhoachuoi(a);
			return UP;
		}
		case FIND:
		{
			if (strlen(a) == Len_Chuoi - 1)
				break;
			if (chedochen)
			{						 // bat dau dich chuoi sang phai tu vi tri chen
				Dich_Phai(a, vtptr); // dich phai toi vi tri con tro
				a[vtptr++] = c;
			}
			else
			{
				a[vtptr++] = c;
				a[vtptr] = '\0';
			}
			if (vt != Len_Show)
				vt++;
			break;
		}
		case LEFT:
		{
			chedochen = TRUE;
			if (vtptr == 0)
				break;
			vtptr--;
			if (vt != 0)
				vt--; //gotoxy(xstart+vt,ystart); Sleep(1000);
			break;
		}
		case RIGHT:
		{
			if (vtptr == Len_Chuoi)
			{
				chedochen = FALSE;
				break;
			}
			if (vt != Len_Show && vt < strlen(a))
				vt++;
			if (vtptr < strlen(a))
			{
				vtptr++;
				chedochen = TRUE;
			}
			break;
		}
		case BACKSPACE:
		{
			if (vtptr == 0)
				break; // xet vi tri con tro
			vtptr--;
			if (vt != 0 && b[0] == a[0])
				vt--;

			if (chedochen)
			{
				Xoa_Ky_Tu(a, vtptr + 1);
			}
			else
			{
				a[vtptr] = '\0';
			}
			break;
		}
		default:
			break;
		}
		for (int i = 0; i < Len_Show; i++)
		{
			gotoxy(xstart + i, ystart);
			printf(" ");
		}
		strcpy(b, a);
		if (vtptr > Len_Show)
		{
			for (int i = 0; i < vtptr - Len_Show; i++)
			{
				Dich_Trai(b, strlen(b));
			}
		}
		b[Len_Show] = '\0';
		Xuat_Chuoi(b, xstart, Len_Show, ystart, dai);
		if (vtptr > rong)
			vt = rong;
		gotoxy(xstart + vt, ystart);
	}
}
TRANGTHAI Chon_Tu_Loai(char a[], int x, int y, bool chedoboqua)
{

	char *LOAI[4];
	int mau[4], contro = 0;
	TRANGTHAI trangthai;
	LOAI[0] = "Danh Tu";
	LOAI[1] = "Dong Tu";
	LOAI[2] = "Tinh Tu";
	LOAI[3] = "Trang Tu";

	for (int i = 0; i < 4; i++)
	{
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	for (int i = 0; i < 4; i++)
	{
		if (stricmp(a, LOAI[i]) == 0)
		{
			mau[i] = MAUNEN;
			if (i != 0)
				mau[0] = MAUCHU;
			contro = i;
			break;
		}
	}
	int c;
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			textcolor(mau[i]);
			gotoxy(x + i * 10, y);
			printf("[%s]", LOAI[i]);
		}
		if (chedoboqua)
		{
			return ENTER;
		}
		c = getch();
		trangthai = key(c);
		switch (trangthai)
		{
		case RIGHT:
		{
			if (contro == 3)
			{
				contro = 0;
				break;
			}
			contro++;
			break;
		}
		case LEFT:
		{
			if (contro == 0)
			{
				contro = 3;
				break;
			}
			contro--;
			break;
		}
		case DOWN:
			strcpy(a, LOAI[contro]);
			return DOWN;
		case UP:
			strcpy(a, LOAI[contro]);
			return UP;
		case ENTER:
			strcpy(a, LOAI[contro]);
			return ENTER;
		default:
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			mau[i] = MAUCHU;
		}
		mau[contro] = MAUNEN;
	}
}
void Menu_Add_Word()
{
	khung(boxx1, boxy1, boxw1, boxs1);
	khung(boxx1 + 1, boxy1 + 1, 1, boxs1 - 2);
	Thanh_I(boxx1 + 8, boxy1 + 1, 1);
	gotoxy(boxx1 + 2, boxy1 + 2);
	printf(" Word:");
	khung(boxx1 + 1, boxy1 + 4, 1, boxs1 - 2);
	gotoxy(boxx1 + 10, boxy1 + 5);
	printf("[Danh Tu] [Dong Tu] [Tinh Tu] [Trang Tu]");
	khung(boxx1 + 1, boxy1 + 8, 1, boxs1 - 2);
	Thanh_I(boxx1 + 8, boxy1 + 8, 1);
	gotoxy(boxx1 + 2, boxy1 + 9);
	printf(" Mean:");
	gotoxy(boxx1 + 15, boxy1 + 11);
	printf("[ Back ] [ Next ] [ Add Mean ]");
	khung(boxx1 + 1, boxy1 + 13, 1, boxs1 - 2);
	Thanh_I(boxx1 + 8, boxy1 + 13, 1);
	gotoxy(boxx1 + 2, boxy1 + 14);
	printf(" Vidu:");
	gotoxy(boxx1 + 15, boxy1 + 16);
	printf("[ Back ] [ Next ] [ Add Vidu ]");
	khung(boxx1 + 38, boxy1 + boxw1 - 2, 1, 8);
	gotoxy(boxx1 + 38 + 3, boxy1 + boxw1 - 2 + 1);
	printf("Save");
	khung(boxx1 + 48, boxy1 + boxw1 - 2, 1, 8);
	gotoxy(boxx1 + 48 + 2, boxy1 + boxw1 - 2 + 1);
	printf("Cancel");
}
int Delete_First_Mean(MPTR &First)
{
	MPTR s = First;
	if (Empty_Mean_List(First))
	{
		printf("Danh sach rong. Khong the xoa");
		return 0;
	}
	if (First->Next == NULL)
	{
		First = NULL;
	}
	else
	{
		First = First->Next;
	}
	free(s);
	return 1;
}
int Delete_Last_Mean(MPTR &First)
{
	MPTR s, t;
	if (Empty_Mean_List(First))
	{
		printf("Danh sach rong. Khong the xoa");
		return 0;
	}
	if (First->Next == NULL)
	{
		First = NULL;
	}
	else
	{
		for (s = First; s->Next != NULL; t = s, s = s->Next)
			;
		t->Next = NULL;
	}
	free(s);
	return 1;
}

void Delete_All_Vidu(char *a[])
{
	int i = 0;
	while (a[i] != NULL)
	{
		a[i] = 0;
		free(a[i]);
		i++;
	}
}
int Len_List_Vidu(char *a[])
{
	int i = 0;
	for (i; a[i] != NULL && i < 5; i++)
		;
	return i;
}
void Delete_Vidu(char *a[], int k)
{
	int i;
	for (i = k; i < Len_List_Vidu(a) - 1; i++)
	{
		strcpy(a[i], a[i + 1]);
	}
	a[i] = 0;
	free(a[i]);
}
void Delete_Vidu_Trong(char *a[])
{
	int i = 0;
	for (i = 0; a[i] != NULL && i < 5; i++)
	{
		if (strlen(a[i]) == 0)
		{
			if (i == Len_List_Vidu(a) - 1)
			{
				a[i] = 0;
				free(a[i]);
			}
			else
			{
				Delete_Vidu(a, i);
				i--;
			}
		}
	}
}
int Delete_All_Mean(MPTR &First)
{
	while (First != NULL)
	{
		return Delete_First_Mean(First);
	}
}
void Delete_Mean_Trong(MPTR &First)
{
	MPTR s, t;
	if (!Empty_Mean_List(First))
	{
		for (s = First; s != NULL; t = s, s = s->Next)
		{
			if (!strlen(s->mean))
			{
				if (s == First)
				{
					Delete_First_Mean(First);
				}
				else
				{
					if (s->Next == NULL)
					{
						Delete_Last_Mean(First);
					}
					else
					{
						MPTR x = s;
						t->Next = s->Next;
						s = t;
						free(x);
					}
				}
			}
		}
	}
}
int Delete_First(LW &D)
{
	DPTR a = D.First;
	if (a == NULL)
	{
		printf("Danh Sach Rong. Khong the xoa");
		return 0;
	}
	if (a->Right == NULL)
	{ // danh sach co mot nut
		D.First = NULL;
	}
	else
	{
		D.First = a->Right;
		D.First->Left = NULL;
	}
	Delete_All_Mean(a->word.First);
	Delete_All_Vidu(a->word.example);
	free(a);
	return 1;
}
int Delete_Node(LW &D, DPTR a)
{
	DPTR truoc, sau;
	if (a == NULL || D.First == NULL)
	{
		printf("Nut p khong hien huu hoac danh sach rong, khong xoa nut duoc");
		return 0;
	}
	if (a == D.First)
	{
		return Delete_First(D);
	}
	else
	{
		truoc = a->Left;
		sau = a->Right;
		truoc->Right = sau;
		sau->Left = truoc;
		Delete_All_Mean(a->word.First);
		Delete_All_Vidu(a->word.example);
		free(a);
	}
	return 1;
}
int Delete_Info(LW D[], char tunho[])
{
	int bucket = H(tunho);
	DPTR s;
	for (s = D[bucket].First; s != NULL && stricmp(s->word.word, tunho) != 0; s = s->Right)
		;
	if (s != NULL)
	{
		return Delete_Node(D[bucket], s);
	}
	return 0;
}
TRANGTHAI Chon_Save_Cancel(Word w, LW D[], int x, int y, bool fix)
{

	int mau[2], contro = 0;
	TRANGTHAI trangthai;

	for (int i = 0; i < 2; i++)
	{
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	int c;
	while (1)
	{

		textcolor(mau[0]);
		gotoxy(x, y);
		printf("  Save  ");
		textcolor(mau[1]);
		gotoxy(x + 10, y);
		printf(" Cancel ");
		c = getch();
		trangthai = key(c);
		switch (trangthai)
		{
		case RIGHT:
		{
			if (contro == 1)
			{
				contro = 0;
				break;
			}
			contro++;
			break;
		}
		case LEFT:
		{
			if (contro == 0)
			{
				contro = 1;
				break;
			}
			contro--;
			break;
		}
		case UP:
			return UP;
		case ENTER:
		{
			if (contro == 0)
			{
				bool khongrong = TRUE;
				if (strlen(w.word) == 0)
				{
					khongrong = FALSE;
					gotoxy(boxx1 + 10, boxy1 + 2);
					textcolor(MAUCANHBAO);
					printf("Yeu cau nhap thong tin");
				}
				if (Empty_Mean_List(w.First))
				{
					khongrong = FALSE;
					gotoxy(boxx1 + 10, boxy1 + 9);
					textcolor(MAUCANHBAO);
					printf("Yeu cau nhap thong tin");
				}
				if (Len_List_Vidu(w.example) == 0)
				{
					khongrong = FALSE;
					gotoxy(boxx1 + 10, boxy1 + 14);
					textcolor(MAUCANHBAO);
					printf("Yeu cau nhap thong tin");
				}
				if (khongrong)
				{
					Delete_Mean_Trong(w.First);
					Delete_Vidu_Trong(w.example);

					DPTR nho = FindWord(w.word, D);

					if (nho != NULL)
					{
						TRANGTHAI yn;
						char a[] = "Tu da ton tai. Ban co muon thay moi ";
						if (fix)
						{
							strcpy(a, "Ban co chac chan muon sua doi");
						}

						yn = Yes_No(a, 7, 22);
						if (yn != BACK)
						{ // Tuong duong voi Yes
							nho->word = w;
							capnhat = TRUE;
						}
					}
					else
					{

						Insert_Order_Word_List(D, w);
						capnhat = TRUE;
					}
				}
				else
				{
					Sleep(1200);
					return SET;
				}
			}
			return BACK;
		}
		default:
			break;
		}

		for (int i = 0; i < 2; i++)
		{
			mau[i] = MAUCHU;
		}
		mau[contro] = MAUNEN;
	}
}
TRANGTHAI Add_Mean(MPTR &First, int x, int y)
{
	TRANGTHAI trangthai;
	char b[LenMean];
	b[0] = 0;
	trangthai = Nhap_Chuoi_Fix(b, LenMean, 45, x, 45, y, 1);
	if (strlen(b) != 0)
		Insert_First_Mean(First, b);
	return trangthai;
}
TRANGTHAI Fix_Mean(MPTR &p, int x, int y)
{
	TRANGTHAI trangthai;
	trangthai = Nhap_Chuoi_Fix(p->mean, LenMean, 45, x, 45, y, 1);
	return trangthai;
}
TRANGTHAI Chon_Back_Next_AddMean(int x, int y, MPTR &a, MPTR First, int x1, int y1, bool &chedothem)
{
	int mau[3], contro = 0;
	TRANGTHAI trangthai;
	for (int i = 0; i < 3; i++)
	{
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	int c;
	while (1)
	{

		textcolor(mau[0]);
		gotoxy(x, y);
		printf("[ Back ]");
		textcolor(mau[1]);
		gotoxy(x + 9, y);
		printf("[ Next ]");
		textcolor(mau[2]);
		gotoxy(x + 18, y);
		printf("[ Add Mean ]");
		c = getch();
		trangthai = key(c);
		switch (trangthai)
		{
		case RIGHT:
		{
			if (contro == 2)
			{
				contro = 0;
				break;
			}
			contro++;
			break;
		}
		case LEFT:
		{
			if (contro == 0)
			{
				contro = 2;
				break;
			}
			contro--;
			break;
		}
		case UP:
			return UP;
		case DOWN:
			return DOWN;
		case ENTER:
		{
			if (contro == 2) // Add
			{
				chedothem = TRUE;
				return UP;
			}
			if (contro == 1) //Next
			{
				if (a == First)
					return UP;
				for (First; strcmp(First->Next->mean, a->mean) != 0; First = First->Next)
					;
				a = First;
				return UP;
			}
			if (contro == 0) // back
			{
				if (a->Next != NULL)
					a = a->Next;

				return UP;
			}
			else
			{
				return BACK;
			}
		}
		default:
			break;
		}

		for (int i = 0; i < 3; i++)
		{
			mau[i] = MAUCHU;
		}
		mau[contro] = MAUNEN;
	}
}
TRANGTHAI Add_Example(char *&a, int x, int y)
{
	TRANGTHAI trangthai;

	if (a == NULL)
	{
		a = (char *)calloc(100, sizeof(char));
	}
	trangthai = Nhap_Chuoi_Fix(a, LenExample, 45, x, 45, y, 1);
	//	printf("thuan");
	return trangthai;
}

TRANGTHAI Chon_Back_Next_AddVidu(int x, int y, int &viduthu, int &viduthu1, int x1, int y1, bool &chedothem1)
{
	int mau[3], contro = 0;

	TRANGTHAI trangthai;
	for (int i = 0; i < 3; i++)
	{
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	int c;
	while (1)
	{

		textcolor(mau[0]);
		gotoxy(x, y);
		printf("[ Back ]");
		textcolor(mau[1]);
		gotoxy(x + 9, y);
		printf("[ Next ]");
		textcolor(mau[2]);
		gotoxy(x + 18, y);
		printf("[ Add Vidu ]");
		c = getch();
		trangthai = key(c);
		switch (trangthai)
		{
		case RIGHT:
		{
			if (contro == 2)
			{
				contro = 0;
				break;
			}
			contro++;
			break;
		}
		case LEFT:
		{
			if (contro == 0)
			{
				contro = 2;
				break;
			}
			contro--;
			break;
		}
		case UP:
			return UP;
		case DOWN:
			return DOWN;
		case ENTER:
		{
			if (contro == 2) // add vi du
			{
				if (viduthu == 4)
				{
					gotoxy(boxx1 + 2, boxy1 + 17);
					textcolor(MAUCANHBAO);
					printf("* Khong the them vi du.Toi da cho phep 5 vi du *");
					return UP;
				}
				if (!chedothem1)
				{

					viduthu++;
					chedothem1 = TRUE;
				}
				return UP;
			}
			if (contro == 1) // next
			{
				if (viduthu1 < viduthu)
				{
					viduthu1++;
				}
				return UP;
			}
			if (contro == 0) // back
			{
				if (viduthu1 != 0)
				{
					viduthu1--;
				}
				return UP;
			}
			else
			{
				return BACK;
			}
		}
		default:
			break;
		}

		for (int i = 0; i < 3; i++)
		{
			mau[i] = MAUCHU;
		}
		mau[contro] = MAUNEN;
	}
}

TRANGTHAI Add_Name_Word(char a[], int x, int y)
{
	TRANGTHAI trangthai;
	trangthai = Nhap_Chuoi_Fix(a, LenWord, 45, x, 45, y, 1);
	return trangthai;
}
void Add_Word(LW D[])
{
	Menu_Add_Word();
	Word x;
	x.word[0] = 0;
	InitLM(x.First);
	MPTR First1 = x.First;
	bool chedothem = TRUE;
	bool chedothem1 = TRUE;
	if (x.First->mean != NULL)
		chedothem = FALSE;
	TRANGTHAI trangthai;
	int c = 19;
	int viduthu = 0;
	int viduthu1 = 0;
	int chucnang = 1;
	while (1)
	{
		switch (chucnang)
		{
		case 1: // them ten tu
		{
			trangthai = Add_Name_Word(x.word, boxx1 + 10, boxy1 + 2);
			break;
		}
		case 2: // loai tu
		{
			trangthai = Chon_Tu_Loai(x.word_type, boxx1 + 10, boxy1 + 5, FALSE);
			break;
		}
		case 3: // them nghia
		{
			if (chedothem)
			{
				trangthai = Add_Mean(x.First, boxx1 + 10, boxy1 + 9);
				if (x.First->mean != 0)
					chedothem = FALSE;
				First1 = x.First;
			}
			else
			{

				trangthai = Fix_Mean(First1, boxx1 + 10, boxy1 + 9);
			}

			break;
		}
		case 4: // di chuyen qua lai cac nghia
		{
			trangthai = Chon_Back_Next_AddMean(boxx1 + 15, boxy1 + 11, First1, x.First, boxx1 + 10, boxy1 + 9, chedothem);
			textcolor(MAUCHU);
			gotoxy(boxx1 + 15, boxy1 + 11);
			printf("[ Back ]");
			gotoxy(boxx1 + 15 + 9, boxy1 + 11);
			printf("[ Next ]");
			gotoxy(boxx1 + 15 + 18, boxy1 + 11);
			printf("[ Add Mean ]");
			break;
		}

		case 5: // them vidu
		{
			if (chedothem1)
			{
				trangthai = Add_Example(x.example[viduthu], boxx1 + 10, boxy1 + 14);
				if (strlen(x.example[viduthu]) != 0)
					chedothem1 = FALSE;
				viduthu1 = viduthu;
			}
			else
			{ // sua vi du thu i
				trangthai = Add_Example(x.example[viduthu1], boxx1 + 10, boxy1 + 14);
			}
			break;
		}
		case 6: // di chuyen qua lai cac vidu
		{
			trangthai = Chon_Back_Next_AddVidu(boxx1 + 15, boxy1 + 16, viduthu, viduthu1, boxx1 + 10, boxy1 + 14, chedothem1);
			textcolor(MAUCHU);
			gotoxy(boxx1 + 15, boxy1 + 16);
			printf("[ Back ]");
			gotoxy(boxx1 + 15 + 9, boxy1 + 16);
			printf("[ Next ]");
			gotoxy(boxx1 + 15 + 18, boxy1 + 16);
			printf("[ Add Vidu ]");
			break;
		}
		case 7: // save_cancel
		{
			trangthai = Chon_Save_Cancel(x, D, boxx1 + 38 + 1, boxy1 + boxw1 - 1, FALSE);
			textcolor(MAUCHU);
			gotoxy(boxx1 + 38 + 1, boxy1 + boxw1 - 1);
			printf("  Save  ");
			gotoxy(boxx1 + 38 + 1 + 10, boxy1 + boxw1 - 1);
			printf(" Cancel ");
			break;
		}
		default:
			break;
		}
		switch (trangthai)
		{
		case DOWN:
		{
			chucnang++;
			break;
		}
		case UP:
		{
			if (chucnang == 1)
				break;
			chucnang--;
			break;
		}
		case ENTER:
		{
			chucnang++;
			break;
		}
		case SET:
		{
			if (strlen(x.word) == 0)
			{
				chucnang = 1;
				break;
			}
			if (Empty_Mean_List(x.First))
			{
				chucnang = 3;
				break;
			}
			if (strlen(x.example[0]) == 0)
			{
				chucnang = 5;
			}
			break;
		}
		case BACK:
		{
			textcolor(MAUCHU);
			xoakhung(boxx1, boxy1, boxw1, boxs1);
			return;
		}
		default:
			break;
		}
	}
}
void Xuat_45_Ky_Tu(char a[])
{
	if (strlen(a) <= 45)
	{
		printf("%s", a);
	}
	else
	{
		int i = strlen(a) - 45;
		i = i - 1;
		for (i; i < strlen(a) - 1; i++)
		{
			printf("%c", a[i]);
		}
	}
}
void Hien_Thi_Thong_Tin(Word x, MPTR begin)
{

	gotoxy(boxx1 + 10, boxy1 + 2);
	printf("%s", x.word);
	Chon_Tu_Loai(x.word_type, boxx1 + 10, boxy1 + 5, TRUE);
	textcolor(MAUCHU);

	gotoxy(boxx1 + 10, boxy1 + 9);
	printf("%s", begin->mean);
	gotoxy(boxx1 + 10, boxy1 + 14);
	Xuat_45_Ky_Tu(x.example[0]);
}
int Copy_Word(Word &x, Word y)
{
	strcpy(x.word, y.word);
	strcpy(x.word_type, y.word_type);
	int i;
	for (i = 0; y.example[i] != NULL && i < 5; i++)
	{
		x.example[i] = (char *)calloc(LenExample, sizeof(char));
		strcpy(x.example[i], y.example[i]);
	}

	MPTR s = y.First;
	while (s != NULL)
	{
		Insert_First_Mean(x.First, s->mean);
		s = s->Next;
	}
	return (i - 1);
}
void Fix_Word(LW D[], char a[])
{
	textcolor(MAUCHU);
	xoakhung(boxxmini, boxymini, boxwmini, boxsmini);
	Menu_Add_Word();
	DPTR xx = FindWord(a, D);

	Word x;
	InitLM(x.First);
	int viduthu = Copy_Word(x, xx->word);

	MPTR First1 = x.First;
	while (First1->Next != NULL)
		First1 = First1->Next; // dua ve cuoi danh sach, forget quan ly con tro last
	Hien_Thi_Thong_Tin(x, First1);
	bool chedothem = FALSE;
	bool chedothem1 = FALSE;
	TRANGTHAI trangthai;
	int c = 19;
	int viduthu1 = 0;
	int chucnang = 1;
	while (1)
	{
		switch (chucnang)
		{
		case 1: // loai tu
		{
			trangthai = Chon_Tu_Loai(x.word_type, boxx1 + 10, boxy1 + 5, FALSE);
			break;
		}
		case 2: // them nghia
		{
			if (chedothem)
			{
				trangthai = Add_Mean(x.First, boxx1 + 10, boxy1 + 9);
				if (x.First->mean != 0)
					chedothem = FALSE;
				First1 = x.First;
			}
			else
			{

				trangthai = Fix_Mean(First1, boxx1 + 10, boxy1 + 9);
			}

			break;
		}
		case 3: // di chuyen qua lai cac nghia
		{
			trangthai = Chon_Back_Next_AddMean(boxx1 + 15, boxy1 + 11, First1, x.First, boxx1 + 10, boxy1 + 9, chedothem);
			textcolor(MAUCHU);
			gotoxy(boxx1 + 15, boxy1 + 11);
			printf("[ Back ]");
			gotoxy(boxx1 + 15 + 9, boxy1 + 11);
			printf("[ Next ]");
			gotoxy(boxx1 + 15 + 18, boxy1 + 11);
			printf("[ Add Mean ]");
			break;
		}

		case 4: // them vidu
		{
			if (chedothem1)
			{
				trangthai = Add_Example(x.example[viduthu], boxx1 + 10, boxy1 + 14);
				if (strlen(x.example[viduthu]) != 0)
					chedothem1 = FALSE;
				viduthu1 = viduthu;
			}
			else
			{ // sua vi du thu i
				trangthai = Add_Example(x.example[viduthu1], boxx1 + 10, boxy1 + 14);
			}
			break;
		}
		case 5: // di chuyen qua lai cac vidu
		{
			trangthai = Chon_Back_Next_AddVidu(boxx1 + 15, boxy1 + 16, viduthu, viduthu1, boxx1 + 10, boxy1 + 14, chedothem1);
			textcolor(MAUCHU);
			gotoxy(boxx1 + 15, boxy1 + 16);
			printf("[ Back ]");
			gotoxy(boxx1 + 15 + 9, boxy1 + 16);
			printf("[ Next ]");
			gotoxy(boxx1 + 15 + 18, boxy1 + 16);
			printf("[ Add Vidu ]");
			break;
		}
		case 6: // save_cancel
		{
			trangthai = Chon_Save_Cancel(x, D, boxx1 + 38 + 1, boxy1 + boxw1 - 1, TRUE);
			textcolor(MAUCHU);
			gotoxy(boxx1 + 38 + 1, boxy1 + boxw1 - 1);
			printf("  Save  ");
			gotoxy(boxx1 + 38 + 1 + 10, boxy1 + boxw1 - 1);
			printf(" Cancel ");
			break;
		}
		default:
			break;
		}
		switch (trangthai)
		{
		case DOWN:
		{
			chucnang++;
			break;
		}
		case UP:
		{
			if (chucnang == 1)
				break;
			chucnang--;
			break;
		}
		case ENTER:
		{
			chucnang++;
			break;
		}
		case SET:
		{

			if (Empty_Mean_List(x.First))
			{
				chucnang = 2;
				break;
			}
			if (strlen(x.example[0]) == 0)
			{
				chucnang = 4;
			}
			break;
		}
		case BACK:
		{
			textcolor(MAUCHU);
			xoakhung(boxx1, boxy1, boxw1, boxs1);
			return;
		}
		default:
			break;
		}
	}
}
void Load_File(LW D[])
{
	FILE *fptr;
	char namefile[2];
	char dem[100];
	for (int k = 0; k < manh; k++)
	{
		namefile[0] = k + 'a';
		namefile[1] = 0;

		fptr = fopen(namefile, "r");
		if (fptr == NULL)
		{
			printf("\n khong mo duoc file!");
			exit(1);
		}
		while (fgets(dem, LenWord, fptr) != NULL)
		{
			Word x;
			dem[strlen(dem) - 1] = 0; // tao 1 struct word de insert_first vao danh sach
			strcpy(x.word, dem);	  //printf("\n word :%s",x.word)	;
			fgets(dem, LenWordType, fptr);
			dem[strlen(dem) - 1] = 0;
			strcpy(x.word_type, dem); //printf("\n%s",x.word_type)	;
			fgets(dem, LenMean, fptr);
			for (InitLM(x.First); strcmp(dem, ".\n") != 0;)
			{
				dem[strlen(dem) - 1] = 0;
				Insert_First_Mean(x.First, dem);
				fgets(dem, LenMean, fptr);
			}
			fgets(dem, LenExample, fptr);
			for (int i = 0; strcmp(dem, ".\n") != 0; i++)
			{
				dem[strlen(dem) - 1] = 0;
				x.example[i] = (char *)calloc(100, sizeof(char));
				strcpy(x.example[i], dem);
				fgets(dem, LenExample, fptr);
			}
			Insert_Order_Word_List(D, x);
		}
	}
	fclose(fptr);
}

void Save_File(LW D[])
{ // on

	char namefile[2];
	FILE *fptr;
	for (int i = 0; i < manh; i++)
	{
		if (D[i].First != NULL) // neu D[i] khong co phan tu thi bo qua
		{
			namefile[0] = 97 + i;
			namefile[1] = 0;
			fptr = fopen(namefile, "w+");
			if (fptr == NULL) // loi phat hien khong mo duoc tep
			{
				printf("\nCant open file");
				exit(0);
			}
			for (DPTR s = D[i].First; s != NULL; s = s->Right)
			{
				fprintf(fptr, "%s\n", s->word.word);
				fprintf(fptr, "%s\n", s->word.word_type);
				for (MPTR ss = s->word.First; ss != NULL; ss = ss->Next)
				{
					fprintf(fptr, "%s\n", ss->mean);
				}
				fprintf(fptr, ".\n");
				for (int i = 0; s->word.example[i] != NULL; i++)
				{

					fprintf(fptr, "%s\n", s->word.example[i]);
				}
				fprintf(fptr, ".\n");
			}
		}
	}
	fclose(fptr);
}
void Format_FILE()
{
	char namefile[2];
	FILE *fptr;
	for (int i = 0; i < manh; i++)
	{
		namefile[0] = i + 'a';
		namefile[1] = 0;
		fptr = fopen(namefile, "w");
	}

	fclose(fptr);
}

//..............................Ham xu ly DO HOA.................................................

void Setfont()
{
	HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
	PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX();
	font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(cons, 0, font);
	font->dwFontSize.X = 1;
	font->dwFontSize.Y = 25;
	font->FontWeight = 100;
	//font->FontFamily = FF_DECORATIVE;
	SetCurrentConsoleFontEx(cons, 0, font);
}
int inputKey()
{
	if (kbhit())
	{
		int key = getch();

		if (key == 224) // special key
		{
			key = getch();
			return key;
		}
		else
		{
			return key;
		}
	}
}
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	HANDLE hConsoleOut;
	COORD Home = {0, 0};
	DWORD dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//screen: get [x]
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

//screen: get [y]
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

void textcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void dicbox()
{ //Ham ve khung nhap va khung ket qua tim kiem
	textcolor(2);
	gotoxy(boxx, boxy);
	cout << char(201);
	for (int i = 1; i < boxs; i++)
	{
		printf("%c", char(205));
		if (i == boxs - 2)
			printf("%c", char(203));
	}
	cout << char(187);
	gotoxy(boxx + boxs - 1, boxy + 1);
	printf("%c", char(186));
	gotoxy(boxx, boxy + 1);
	cout << char(186) << " Tim kiem:";
	gotoxy(boxx + boxs, boxy + 1);
	printf("%c", char(175));
	gotoxy(boxx + boxs + 1, boxy + 1);
	cout << char(186);
	gotoxy(boxx, boxy + 2);
	cout << char(204);
	for (int i = 1; i < boxs; i++)
	{
		if (i == boxs - 1)
			printf("%c", char(202));
		cout << char(205);
	}
	cout << char(185);
	for (int i = boxy + 3; i < boxy + 3 + boxw; i++)
	{
		gotoxy(boxx, i);
		cout << char(186);
		gotoxy(boxx + boxs + 1, i);
		cout << char(186);
	}
	gotoxy(boxx, boxy + boxw + 3);
	cout << char(200);
	for (int i = 1; i < boxs + 1; i++)
		cout << char(205);
	cout << char(188);
	textcolor(2);
}
void khungchitiet()
{ //Ham ve khung nhap va khung ket qua tim kiem
	textcolor(2);
	gotoxy(boxx1, boxy1);
	printf("%c", char(201));
	for (int i = 1; i <= boxs1; i++)
		printf("%c", char(205));
	printf("%c", char(187));
	for (int i = 1; i <= boxw1; i++)
	{
		gotoxy(boxx1, boxy + i);
		printf("%c", char(186));
		gotoxy(boxx1 + boxs1 + 1, boxy + i);
		printf("%c", char(186));
	}
	gotoxy(boxx1, boxy1 + boxw1 + 1);
	printf("%c", char(200));
	for (int i = 1; i <= boxs1; i++)
	{
		printf("%c", char(205));
	}
	gotoxy(boxx1 + boxs1 + 1, boxy1 + boxw1 + 1);
	printf("%c", char(188));
}

void khungmenu()
{
	gotoxy(boxx + boxs + 3, boxy);
	printf("%c", char(201));
	for (int i = 1; i <= boxsmini; i++)
		printf("%c", char(205));
	printf("%c", char(187));
	for (int i = 1; i <= boxwmini; i++)
	{
		gotoxy(boxx + boxs + 3, boxy + i);
		printf("%c", char(186));
		gotoxy(boxx + boxs + 3 + boxsmini + 1, boxy + i);
		printf("%c", char(186));
	}
	gotoxy(boxx + boxs + 3, boxy + boxwmini + 1);
	printf("%c", char(200));
	for (int i = 1; i <= boxsmini; i++)
		printf("%c", char(205));
	printf("%c", char(188));
	gotoxy(boxx + 12, boxy + 1);
}

void thuoc()
{
	for (int i = 0; i <= 106; i++)
	{
		textcolor(4);
		if (i % 9 == 0)
			printf("0");
		textcolor(224);
		printf("%d", i % 9 + 1);
	}
	for (int i = 0; i <= 106;)
	{
		textcolor(224);
		printf("\n%d", i % 9 + 1);
		textcolor(4);
		i++;
		if (i % 9 == 0)
			printf("\n0");
	}
}

TRANGTHAI key(int x)
{
	if (x == 224)
	{
		char c;
		c = getch();
		if (c == 72)
			return UP;
		if (c == 80)
			return DOWN;
		if (c == 77)
			return RIGHT;
		if (c == 75)
			return LEFT;
	}
	else if (x == 13)
		return ENTER;

	else if (x == 27)
		return ESC;

	else if (x >= 'a' && x <= 'z' || x == ' ' || x >= 'A' && x <= 'Z')
	{
		return FIND;
	}
	else if (x == 8)
		return BACKSPACE;
}

TRANGTHAI menu1(LW D[], char tunho[])
{
	int t = 0;
	int n = 3;
	int mau1[n];
	for (int i = 0; i < n; i++)
	{
		mau1[i] = MAUCHU;
	}
	mau1[0] = MAUNEN;

	sizethaotac chucnang[n] = {"Them tu moi", "Xoa tu", "Sua tu"};
	bool OFF = FALSE;

	textcolor(MAUNEN);			   //
	gotoxy(boxx + boxs, boxy + 1); //		hien thi dau >>;
	printf("%c", char(175));

	while (!OFF)
	{
		textcolor(MAUCHU);
		khung(boxxmini, boxymini, boxwmini, boxsmini);
		for (int ii = 0; ii < n; ii++)
		{
			gotoxy(boxxmini + 1, boxymini + 1 + ii);
			printf("      ");
		}
		for (int ii = 0; ii < n; ii++)
		{
			gotoxy(boxxmini + 1, boxymini + 1 + ii);
			textcolor(mau1[ii]);
			printf(" %-19s", chucnang[ii]);
			gotoxy(boxx + boxs, boxy + 1);
		}
		int z = getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai)
		{
		case UP:
		{
			if (t == 0)
				t = n - 1;
			else
				t--;
			break;
		}
		case DOWN:
		{
			if (t == n - 1)
				t = 0;
			else
				t++;
			break;
		}
		case LEFT:
		{
			textcolor(0);
			xoakhung(boxxmini, boxymini, boxwmini + 2, boxsmini + 2);

			OFF = TRUE;
			return LEFT;
		}
		case ENTER:
		{
			switch (t)
			{
			case 0: // them tu moi
			{
				xoakhung(boxxmini, boxymini, boxwmini, boxsmini);
				Add_Word(D);

				break;
			}
			case 1: // xoa tu hien tai tren thanh tim kiem
			{
				TRANGTHAI yn;
				gotoxy(10, 23);
				printf("Tu: %s", tunho);
				char a[] = "Ban co chac chan muon xoa tu nay";
				//strcat(a,tunho);
				yn = Yes_No(a, 7, 22);
				if (yn != BACK)
				{
					Delete_Info(D, tunho);
					capnhat = TRUE;
				}
				break;
			}
			case 2:
			{
				Fix_Word(D, tunho);
				break;
			}
			default:
				break;
			}

			break;
		}
		case ESC:
			return ESC;
		default:
			break;
		}
		for (int i = 0; i < n; i++)
		{
			mau1[i] = MAUCHU;
		}
		mau1[t] = MAUNEN;
	}
}
TRANGTHAI Yes_No(char a[], int x, int y)
{
	gotoxy(x + 2, y + 2);
	printf("%s", a); //printf("Ban dang ESE.Ban co muon tiep tuc");
	khung(x, y, 6, 35);
	khung(x + 7, y + 4, 1, 9);
	khung(x + 7 + 12, y + 4, 1, 9);
	int mau[2], contro = 0;
	TRANGTHAI trangthai;
	for (int i = 0; i < 2; i++)
	{
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	int c;
	while (1)
	{

		textcolor(mau[1]);
		gotoxy(x + 8, y + 5);
		printf("   Yes   ");
		textcolor(mau[0]);
		gotoxy(x + 8 + 12, y + 5);
		printf("    No   ");
		c = getch();
		trangthai = key(c);
		switch (trangthai)
		{
		case RIGHT:
		{
			if (contro == 1)
			{
				contro = 0;
				break;
			}
			contro++;
			break;
		}
		case LEFT:
		{
			if (contro == 0)
			{
				contro = 1;
				break;
			}
			contro--;
			break;
		}
		case ENTER:
		{
			textcolor(2);
			xoakhung(x, y, 6, 35);
			if (contro == 0)
			{
				return BACK;
			}
			else
			{
				return ESC;
			}
		}
		default:
			break;
		}

		for (int i = 0; i < 2; i++)
		{
			mau[i] = MAUCHU;
		}
		mau[contro] = MAUNEN;
	}
}
void Giao_Dien()
{
	Setfont(); // set font chu
	SetConsoleTitle("     Vo Minh Thuan _ N17DCAT070 _ D17CQAT01-N");
}
int main()
{
	Giao_Dien();
	LW D[manh]; //tao mang chua 26 danh sach
	InitLW(D);	// khoi tao null
	TRANGTHAI trangthai;
	Load_File(D);

	while (trangthai != ESC)
	{
		clrscr();
		thuoc();
		dicbox();
		trangthai = Find_Word_Main(D, 14);
		char a[] = "Ban dang ESE.Ban co muon tiep tuc";
		trangthai = Yes_No(a, 7, 22);
	}
	if (capnhat)
		Save_File(D);

	return 0;
}
