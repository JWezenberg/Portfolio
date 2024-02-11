#include <stdio.h>
#include <dirent.h>

int main() {

    int count = 1;
    DIR *directory;
    struct dirent *entry;

    // Open the current directory (".")
    directory = opendir(".");
    if (directory == NULL) {
        perror("Error opening directory");
        return 1;
    }

    // Read and print each entry in the directory
       for (count = 1; (entry = readdir(directory)) != NULL; count++) {
        printf("%s\n", entry->d_name);
        printf("%d", count);
    }


    // Close the directory
    closedir(directory);
        while(1){}
    return 0;
}



/* 

   while ((entry = readdir(directory)) != NULL) {
        printf("%s\n", entry->d_name);
    }


cannot open output file ... permission denied = terminate program in taskmanager
    */
