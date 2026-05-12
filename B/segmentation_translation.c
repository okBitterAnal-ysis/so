/*
Commands:
gcc segmentation_translation.c -o segment
./segment
*/

#include <stdio.h>

typedef struct {
    int base;
    int limit;
} Segment;

int main() {
    Segment segments[3] = {
        {1000, 400},
        {2000, 500},
        {3000, 300}
    };

    int requests[3][2] = {
        {0, 200},
        {1, 600},
        {2, 150}
    };

    for (int i = 0; i < 3; i++) {
        int seg = requests[i][0];
        int offset = requests[i][1];

        printf("Segment %d, Offset %d -> ", seg, offset);

        if (offset >= segments[seg].limit) {
            printf("Segmentation fault: Offset exceeds limit\n");
        } else {
            int physical = segments[seg].base + offset;
            printf("Physical Address = %d\n", physical);
        }
    }

    return 0;
}
