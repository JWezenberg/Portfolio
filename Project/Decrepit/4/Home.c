#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void breakpoint(int x){
    if (x == 1) { printf("Succes\n"); }
}

int main() {

    int count;
    int debug = 1;
    int cmd;
    int sys;
    DIR *directory;
    struct dirent *entry;

    // Open the current directory (".")
    directory = opendir(".");
    if (directory == NULL) {
        perror("Error opening directory");
        return 1;
    }
    breakpoint(debug);

    printf("Intro placeholder\n\n");
    printf("1 - exit program\n");
    while ((entry = readdir(directory)) != NULL) {

    // Read and print each entry in the directory
        for (count = 1; (entry = readdir(directory)) != NULL; count++) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){ continue; }
        printf("%d - %s\n", count, entry->d_name);
        }
    breakpoint(debug);
    printf("\noutro placeholder\n");
    scanf("%d", &cmd);
    breakpoint(debug);

    sys = system("cd C:\\Users\\JHWez\\OneDrive - ROCvA, ROCvF en VOvA\\Portfolio\\Project\\output");
    system("start home.exe");
    if (sys == -1){
        perror("Error opening file");
        return 1;
    }


    // Close the directory
    closedir(directory);
    breakpoint(debug);
    scanf("");
    while(1){}
    return 0;
}}



/* 



   while ((entry = readdir(directory)) != NULL) {
        printf("%s\n", entry->d_name);
    }


cannot open output file ... permission denied = terminate program in taskmanager
    */
