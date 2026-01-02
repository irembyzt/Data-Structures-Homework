#include <stdio.h>

 
void hanoi(int n, char source, char destination, char auxiliary) {

 
    if (n == 1) {
        printf("Disk 1: %c -> %c\n", source, destination);
        return;
    }
 
    hanoi(n - 1, source, auxiliary, destination);
 
    printf("Disk %d: %c -> %c\n", n, source, destination);
 
    hanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;

    printf("Disk sayisini giriniz: ");
    scanf("%d", &n);

    printf("\nTower of Hanoi Cozumu:\n");
    hanoi(n, 'A', 'C', 'B');

    return 0;
}
