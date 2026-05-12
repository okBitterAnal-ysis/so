#include <stdio.h>

int main() {
    unsigned int virtual_address = 0x00403004;

    unsigned int l1 = (virtual_address >> 22) & 0x3FF;
    unsigned int l2 = (virtual_address >> 12) & 0x3FF;
    unsigned int offset = virtual_address & 0xFFF;

    printf("Virtual Address = 0x%X\n", virtual_address);
    printf("L1 Index = %u\n", l1);
    printf("L2 Index = %u\n", l2);
    printf("Offset = %u\n", offset);

    int l1_table[1024];
    l1_table[1] = 5000;

    int l2_table[1024];
    l2_table[3] = 7;

    int frame = l2_table[3];
    unsigned int physical_address = frame * 4096 + offset;

    printf("Frame Number = %d\n", frame);
    printf("Physical Address = 0x%X\n", physical_address);

    return 0;
}
