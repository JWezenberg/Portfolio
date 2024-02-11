#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void breakpoint(int x){
    if (x == 1) { printf("Succes\n"); }
}

int main() {

    int count;
    int debug = 0;
    int cmd = 0;
    int sys;
    char root[] = "C:\\Users\\JHWez\\OneDrive - ROCvA, ROCvF en VOvA\\Portfolio\\Project\\output";
    char ccmd1[256];
    char ccmd2[256];

    DIR *directory;
    struct dirent *entry;

    // Open the root directory
        breakpoint(debug);
    directory = opendir(("%s", root));
    if (directory == NULL) {
        perror("Error opening directory");
        return 1;
    }
    breakpoint(debug);

    printf("Intro placeholder\n\n");
    printf("1 - exit program\n");


    char **entries = NULL; // Array to store directory entries
    int num_entries = 0;   // Number of entries in the array

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
        // Free the memory allocated for each entry
  //      free(entries[i]);
    }
    // Free the memory allocated for the entries array




    breakpoint(debug);

    printf("\noutro placeholder\n");
    scanf("%d", &cmd);
    sprintf(ccmd1, "cd %s", root);
    sprintf(ccmd2, "start \"\" \"%s\"", entries[cmd]);
    breakpoint(debug);
    printf ("%s", ccmd2);

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



/* 



   while ((entry = readdir(directory)) != NULL) {
        printf("%s\n", entry->d_name);
    }


cannot open output file ... permission denied = terminate program in taskmanager



rewinddir(directory);


    while ((entry = readdir(directory)) != NULL) {

    // Read and print each entry in the directory
        for (count = 1; (entry = readdir(directory)) != NULL; count++) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){ continue; }
    //    printf("%d - %s\n", count, entry->d_name);
        }
    */
