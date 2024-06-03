// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <sstream>

bool isReadableWritablePointer(void* p)
{
    MEMORY_BASIC_INFORMATION info;
    if (VirtualQuery(p, &info, sizeof(info)) == sizeof(info)) {
        if (info.State == MEM_COMMIT) {
            DWORD protect = info.Protect;
            if (!(protect & PAGE_GUARD) && !(protect & PAGE_NOACCESS)) {
                if (protect & PAGE_READONLY || protect & PAGE_READWRITE ||
                    protect & PAGE_WRITECOPY || protect & PAGE_EXECUTE_READ ||
                    protect & PAGE_EXECUTE_READWRITE || protect & PAGE_EXECUTE_WRITECOPY) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    std::cout << "Assembler Program\n";
    std::string input;
    std::ostringstream oss;
    oss << "isReadableWritablePointer is locating at: " << std::hex << std::uppercase << (PVOID)&isReadableWritablePointer << std::dec << std::nouppercase;
    std::cout << oss.str() << std::endl;
    oss.str("");
    oss.clear();
    std::cin >> input;
    oss << std::boolalpha << isReadableWritablePointer(&input) << " " << isReadableWritablePointer(nullptr);
    std::cout << oss.str();
    return TRUE;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
