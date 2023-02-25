#include <stdio.h>
struct student//initialise struct datatype named student
{
    char name[40];//variable to save the name of the student
    int number;/// variable to save the id number of the student
    double marks[4];// array that contains the four module grades of the student 
};

double average(int student,struct student studentArray[]);//function prototype for average

int main()
{
    ///array of structures studentArray having 5 elements to store information of 5 students.
    struct student studentArray[5]=
    {
        {"John Papidakis", 239485, {100.0, 85.5, 76.9, 91.3} },
        {"Anna Smith", 734934, {95.45, 69.8, 78.1, 87.3} },
        {"Mary Jones", 435942, {67.7, 85.0, 78.9, 56.8} },
        {"James Peterson", 445324, {98.9, 67.3, 54.78, 87.4} },
        {"Joe Black", 578492, {86.7, 67.34, 93.56, 80.21} }
    };

    /*
        studentNum -- index variable to access data for each student in studentArray
        j -- index to display the marks of each student 
    */
    for (int studentNum = 0; studentNum < 5; studentNum++)
    {
        printf("\nGrades for student (%s) : ",studentArray[studentNum].name);//display grades for each student
        for (int j = 0; j < 4; j++)
        {
            printf(" %.2f",studentArray[studentNum].marks[j]);
        }
    printf("\nStudent average = %.2f\n",average(studentNum,studentArray));//prints the overall average of the 4 grades for each student
    }                                                                    ///by invoking stringInsert function
    return 0;
}

double average(int studentNum, struct student studentArray[])
{
    double average;//initialise veriable to display the average grade 
    double sum=0;//initialise veriable to display the sum of the fout grades
    int moduleNum;//index variable for the module number

    for (moduleNum = 0; moduleNum < 4; moduleNum++)
    {
        sum = sum + studentArray[studentNum].marks[moduleNum];///add all the four grades together
    }
    average=sum/moduleNum;///devide the sum of the grades with the number of the modules to find average
    return average;/// return the value of variable average
}
