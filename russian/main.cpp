#include<iostream>
#include<string>
#include<locale>

int main()
{
  // cyrillic input-outout for linux
    std::locale loc("");
    std::locale::global(loc);
    std::wcout << L"Введите строку: " << std::endl;
    std::wstring ws;
    std::wcin >> ws;
    std::wcout << ws << L"\n";
  return 0;
}