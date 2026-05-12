/*
Commands:
gcc two_level_paging.c -o paging
./paging
*/

#include <stdio.h>

int main() {
    unsigned int virtualAddress = 0x00403004;

    unsigned int l1 = (virtualAddress >> 22) & 0x3FF;
    unsigned int l2 = (virtualAddress >> 12) & 0x3FF;
    unsigned int offset = virtualAddress & 0xFFF;

    int l1Table[1024];
    int l2Table[1024];

    l1Table[1] = 5000;
    l2Table[3] = 7;

    unsigned int frame = l2Table[3];

    unsigned int physicalAddress = (frame * 4096) + offset;

    printf("Virtual Address = 0x%X\n", virtualAddress);
    printf("L1 Index = %u\n", l1);
    printf("L2 Index = %u\n", l2);
    printf("Offset = %u\n", offset);

    printf("L1[1] -> L2 Table Base = %d\n", l1Table[1]);
    printf("L2[3] -> Frame = %d\n", l2Table[3]);

    printf("Physical Address = 0x%X\n", physicalAddress);

    return 0;
}
