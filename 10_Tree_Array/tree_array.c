#include <stdio.h>

#define SIZE 7

int tree[SIZE] = {10, 20, 30, 40, 50, 60, 70};
 
void preorder(int i) {
    if (i >= SIZE)
        return;

    printf("%d ", tree[i]);
    preorder(2 * i + 1);
    preorder(2 * i + 2);
}
 
void inorder(int i) {
    if (i >= SIZE)
        return;

    inorder(2 * i + 1);
    printf("%d ", tree[i]);
    inorder(2 * i + 2);
}
 
void postorder(int i) {
    if (i >= SIZE)
        return;

    postorder(2 * i + 1);
    postorder(2 * i + 2);
    printf("%d ", tree[i]);
}

int main() {

    printf("Preorder  : ");
    preorder(0);

    printf("\nInorder   : ");
    inorder(0);

    printf("\nPostorder : ");
    postorder(0);

    return 0;
}
