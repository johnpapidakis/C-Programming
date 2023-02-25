#include <stdio.h>
#include <stdlib.h>

int main() {
    int classSize = 11; //2 last digits of your student ID is 31
    if (classSize < 10) {
        classSize += 10;
    }

    //Determine whether to create a non-formatted or character file
    FILE *fp;
    char space[]="\t";
    char newLine[]="\n";
    

    if ((fp = fopen("AE5U_Finals.dat", "w")) == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char studentInitials[3];
    float mark;

    //Input student names and their final marks
    for (int i = 0; i < classSize; i++) {
        printf("Enter student %d initials: ", i+1);
        scanf("%s", studentInitials);
        printf("Enter student %d final mark: ", i+1);
        scanf("%f", &mark);

        //Write student initials and mark to file
        if (classSize % 2 == 0) {
            fwrite(studentInitials,sizeof(studentInitials),1,fp);
            fwrite(space,sizeof(space),1,fp);
            fwrite(&mark,sizeof(float),1,fp);
            fwrite(newLine,sizeof(newLine),1,fp);



        } else {
            fprintf(fp, "%s\t%.1f\n", studentInitials, mark);
        }
    }

    //Close the file
    fclose(fp);
    printf("Data written to file successfully\n");
    return 0;
}