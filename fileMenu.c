#include <stdio.h>

int main() {
    int choice = 1;
    char name[10], roll[5], ch;
    FILE *fp;
    fp = fopen("db.txt", "a+");

    while(choice == 1 || choice == 2) {
        printf("Choose option:\n1) Add record\n2) List records\n3) Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%s", roll);
                printf("Enter name: ");
                scanf("%s", name);
                fprintf(fp, "%s\t%s\n", roll, name);
                break;
            case 2:
                fseek(fp, 0, SEEK_SET);
                do {
                    ch = fgetc(fp);
                    printf("%c", ch);
                }
                while (ch != EOF);
                break;
            default:
                printf("Exiting\n");
                break;
        }
    }
    fclose(fp);
    return 0;
}