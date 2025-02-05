#include<iostream>
#include<string>
#include<io.h> // for _setmode
#include<fcntl.h> // for _O_UI16TEXT

void set_utf16_mode()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);
}

int main()
{
    set_utf16_mode();

    std::wcout << L"Введите строку:" << std::endl;
    std::wstring ws;
    std::wcin >> ws;
    std::wcout << ws << L"\n";
    return 0;
}