#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {

    int count = 0;
    DIR *directory;
    struct dirent *entry;

    // Open the current directory (".")
    directory = opendir(".");
    if (directory == NULL) {
        perror("Error opening directory");
        return 1;
    }

while ((entry = readdir(directory)) != NULL) {

    // Read and print each entry in the directory
        for (count = 1; (entry = readdir(directory)) != NULL; count++) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){ continue; }
        printf("%s\n", entry->d_name);
        printf("%d", count);
        }



    // Close the directory
    closedir(directory);
            while(1){}
    return 0;
}}



/* 

    if (entry->d_type == DT_REG) { /* If the entry is a regular file *//*
         count++;
    }

   while ((entry = readdir(directory)) != NULL) {
        printf("%s\n", entry->d_name);
    }


cannot open output file ... permission denied = terminate program in taskmanager
    */
