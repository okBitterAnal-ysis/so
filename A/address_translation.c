/*
Commands:
gcc address_translation.c -o address
./address
*/

#include <stdio.h>

int main() {
    int pageTable[] = {3, 1, 4};

    unsigned int virtualAddresses[] = {0x1A3F, 0x2B10};

    int pageSize = 4096;

    for (int i = 0; i < 2; i++) {
        unsigned int va = virtualAddresses[i];

        unsigned int pageNumber = va / pageSize;
        unsigned int offset = va % pageSize;

        if (pageNumber >= 3) {
            printf("Invalid page number for VA 0x%X\n", va);
            continue;
        }

        unsigned int frameNumber = pageTable[pageNumber];

        unsigned int physicalAddress = (frameNumber * pageSize) + offset;

        printf("Virtual Address: 0x%X\n", va);
        printf("Page Number: %u\n", pageNumber);
        printf("Offset: 0x%X\n", offset);
        printf("Physical Address: 0x%X\n\n", physicalAddress);
    }

    return 0;
}
