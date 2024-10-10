#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "String.h"
void setupCRT() {
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}
void onExit() {
#ifdef DEBUG
    _CrtDumpMemoryLeaks();
#endif // DEBUG

    std::cout << "Press Enter to exit...";
    std::cin.get();
}
int main()
{
#ifdef DEBUG
    setupCRT(); 
#endif
    using DLOzTOR::String;
    String *str = new String("text");
    std::cout << *str <<'\n';
    delete(str);
    onExit();
    return 0;
}