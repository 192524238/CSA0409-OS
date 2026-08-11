#include <stdio.h>

int main() {
    int base, limit, logical, physical;

    printf("Enter Base: ");
    scanf("%d", &base);

    printf("Enter Limit: ");
    scanf("%d", &limit);

    printf("Enter Logical Address: ");
    scanf("%d", &logical);

    if (logical < limit) {
        physical = base + logical;
        printf("Valid Address\n");
        printf("Physical Address = %d\n", physical);
    } else {
        printf("Invalid Address\n");
    }

    return 0;
}
