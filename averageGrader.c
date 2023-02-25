#include <stdio.h>
double average(int student,double std_grades[3][4]); //function prototype for average
/*

student -- integer variable which refers to the number of the student  
std_grades[3][4]  --  2d array to store the 4 grades that each of the 3 students have obtained
*/
int main()
{
    double std_grades[3][4] = {{7.7, 6.8, 8.6, 7.3}, ///initialise array values 
                              {9.6, 8.7, 8.9, 7.8},
                              {7.0, 9.0, 8.6, 8.1}};
    /*
        student -- index variable which refers to the number of the student as mentioned above
        j -- index variable to display each grade of the particular student 
    */
    for (int student = 0; student < 3; student++)//prints each one of the four grades every student have obtained 
    {
        printf("\nGrades for student %d are: ",student);
        for (int j = 0; j < 4; j++)
        {
            printf(" %.2f",std_grades[student][j]);
        }
    printf("\nStudent average = %.2f\n",average(student,std_grades));//prints the overall average of the 4 grades for each student
    }                                                               ///by invoking stringInsert function
}

double average(int student,double std_grades[3][4])
{
    double average;//initialise veriable to display the average grade 
    double sum=0;//initialise veriable to display the sum of the fout grades
    int moduleNum;//index variable for the module number 
    for (moduleNum = 0; moduleNum < 4; moduleNum++)
    {
        sum = sum + std_grades[student][moduleNum];///add all the four grades together
    }
    average=sum/moduleNum;///devide the sum of the grades with the number of the modules to find average
    
    return average;/// return the value of variable average
}