#include <stdio.h>
#include <string.h>

int main() {
    int i, found = 0;
    int numEntries = 0;
    char query[10];
    struct book {
        char title[10];
        char author[10];
    };
    
    printf("How many entries? ");
    scanf("%d", &numEntries);
    struct book books[numEntries];

    for (i = 0; i < numEntries; i++) {
        printf("Enter title: ");
        scanf("%s", books[i].title);
        printf("Enter author: ");
        scanf("%s", books[i].author);

        printf("\n");
    }
    printf("Enter search term: ");
    scanf("%s", query);

    for (i = 0; i < numEntries; i++) {
        if (strcmp(query, books[i].title) == 0 || strcmp(query, books[i].author) == 0) {
            found = 1;
            printf("Book found:\nTitle: %s\nAuthor: %s\n", books[i].title, books[i].author);
        }
    }

    if (found == 0) {
        printf("No books found.\n");
    }
    return 0;
}