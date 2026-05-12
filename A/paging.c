#include <stdio.h>

int main() {

    int page_table[3] = {3,1,4};

    unsigned int addresses[] = {0x1A3F, 0x2B10};

    for(int i=0;i<2;i++) {

        unsigned int va = addresses[i];

        unsigned int page = va / 4096;
        unsigned int offset = va % 4096;

        unsigned int frame = page_table[page];

        unsigned int pa = frame * 4096 + offset;

        printf("VA = 0x%X\n", va);
        printf("Page = %u Offset = %u\n", page, offset);
        printf("PA = 0x%X\n\n", pa);
    }

    return 0;
}
