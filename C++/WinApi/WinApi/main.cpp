#include <tchar.h>
#include <string>
#include <iostream>
#include <regex>
#include <Windows.h>
int _tmain(int argc, _TCHAR *argv[])
{
	wchar_t buf[50] = {0};
	wchar_t *hello = L"пппп";
	
	wcscpy(buf, hello);
	wcscat(buf, L"укеуке");
	std::wcout.imbue(std::locale(".866"));
	std::wregex r(L"[уеаыоияёэю]");
	std::wstring s(buf);
	std::wsmatch m;
	std::regex_search(s,m,r);
	std::wcout << m.size() << L"clkujd";
	//wprintf(L"%S EGK;LK",hello);
	
	std::wcout << buf <<std::endl;
	getc(stdin);

	return 0;
}
