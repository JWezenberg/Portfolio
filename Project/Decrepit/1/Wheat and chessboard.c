#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
    
    // Declare variables to store input
    int height;
    int depth;
    int board;
    int muli;
    unsigned long long grains;
    unsigned long long total;

    // State Problem
    printf("The wheat and chessboard problem is a mathematical problem expressed in textual form as:\nIf a board were to have wheat placed upon each square such that one grain were placed on the first square,two on the second, four on the third, and so on (doubling the number of grains on each subsequent square), how many grains of wheat would be on the board in total?\n\n");

    // Collect input from user
    printf("Enter the height of the board: ");
    scanf("%d", &height);
    printf("Enter the depth of the board: ");
    scanf("%d", &depth);
    printf("Enter the amount of grains on the first tile: ");
    scanf("%llu", &grains);
    printf("Enter the multiplication on every subsequent tile: ");
    scanf("%d", &muli);

    // Process and output the input
    board = height * depth;
    for (int i = 1; i <= board; i++) {
        if (i == 1) { total = 0; printf("\n"); }
        if (ULONG_MAX + total < ULONG_MAX) { printf("Overflow occurred!\n"); break; }
        printf("Square %d: %llu grain(s)\n", i, grains);
        total += grains;
        grains *= muli;
        if (i == board) { printf("\nAdd those up for a total of: %llu\n", total ); }
    }

    // EOP
    while(1){}
    return 0;
}