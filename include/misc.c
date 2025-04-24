#include <stdlib.h>

void clear(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
