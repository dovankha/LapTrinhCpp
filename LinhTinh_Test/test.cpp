//#include <iostream>
//#include <fcntl.h>
//#include <io.h>
//#include <cstdlib>
//using namespace std;
//
//int main()
//{
//	_setmode(_fileno(stdout), _O_U16TEXT);
//	cout << u8"Chào. Ðây là ti?ng Vi?t.";
//}


#include <iostream>
#include <io.h>
#include <fcntl.h>

int wmain(int argc, wchar_t* argv[])
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << L"Testing unicode -- English -- ???????? -- Español." << std::endl;
}
