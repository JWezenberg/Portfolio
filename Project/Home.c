#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void breakpoint(int x){
    if (x == 1) { printf("Succes\n"); }
}

int main() {

    int debug = 0;
    int cmd = 0;
    int sys;
    char root[] = "C:\\Users\\JHWez\\OneDrive - ROCvA, ROCvF en VOvA\\Portfolio\\Project\\output";
    char **entries = NULL;
    int num_entries = 0;
    char ccmd1[256];
    char ccmd2[256];
    DIR *directory;
    struct dirent *entry;

    breakpoint(debug);

    // Open the root directory
    directory = opendir(("%s", root));
    if (directory == NULL) {
        perror("Error opening directory");
        return 1;
    }

    breakpoint(debug);

    printf("John Wezenberg's Projects\n\n");
    printf("1 - exit program\n");

    // Read directory entries and store them in the array
    while ((entry = readdir(directory)) != NULL) {
        // Allocate memory for the new entry
        char *new_entry = malloc(strlen(entry->d_name) + 1);
        if (new_entry == NULL) {
            perror("Memory allocation failed");
            return 1;
        }
        // Copy the entry name into the allocated memory
        strcpy(new_entry, entry->d_name);
        // Reallocate memory for the entries array
        entries = realloc(entries, (num_entries + 1) * sizeof(char *));
        if (entries == NULL) {
            perror("Memory allocation failed");
            return 1;
        }
        // Add the new entry to the array
        entries[num_entries++] = new_entry;
    }

    // Print the directory entries stored in the array
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i], ".") == 0 || strcmp(entries[i], "..") == 0){ continue; }
        printf("%d - %s\n", i, entries[i]);
    }

    breakpoint(debug);
    //read and process choice of user
    printf("\nChoose which program to start\n");
    scanf("%d", &cmd);
    sprintf(ccmd1, "cd %s", root);
    sprintf(ccmd2, "start \"\" \"%s\"", entries[cmd]);

    breakpoint(debug);

    //exit program if needed
    if (cmd <= 1){
        free(entries);
        exit(0);
    }

    //write command lines into cmd
    sys = system(ccmd1);
    if (sys == -1){
        perror("Error finding directory");
        return 1;
    }
    sys = system(ccmd2);
    if (sys == -1){
        perror("Error opening file");
        return 1;
    }

    // Close the directory
    free(entries);
    closedir(directory);

    breakpoint(debug);
    return 0;
}