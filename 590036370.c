#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100




struct Student {
    long long sapID;
    int rollNo;

    char name[100];
    char phone[20];
    char email[100];

    int year;
    int semester;

    float sgpa[8];
};


struct Student students[MAX_STUDENTS];


int studentCount = 0;




void addStudent();
void searchStudent();
float calculateCGPA(struct Student s);
void averageCGPAByYear();
void displayStudent(struct Student s);
void displayAllStudents();
void deleteStudent();
void sortBySAPID();
void sortByName();
void academicAdvisor();


void addStudent() {

    if(studentCount >= MAX_STUDENTS) {
        printf("\nStudent record is full.\n");
        return;
    }

    printf("\n----- ADD STUDENT -----\n");

    printf("Enter SAP ID: ");
    scanf("%lld", &students[studentCount].sapID);

    printf("Enter Roll Number: ");
    scanf("%d", &students[studentCount].rollNo);

    printf("Enter Name: ");
    scanf(" %99[^\n]", students[studentCount].name);

    printf("Enter Phone Number: ");
    scanf("%19s", students[studentCount].phone);

    printf("Enter Email ID: ");
    scanf("%99s", students[studentCount].email);

    printf("Enter Year (1-4): ");
    scanf("%d", &students[studentCount].year);

    printf("Enter Current Semester (1-8): ");
    scanf("%d", &students[studentCount].semester);



    for(int i = 0; i < students[studentCount].semester; i++) {

        printf("Enter SGPA for Semester %d: ", i + 1);

        scanf("%f", &students[studentCount].sgpa[i]);
    }


    studentCount++;

    printf("\nStudent added successfully!\n");
}


void displayStudent(struct Student s) {

    printf("\n----------------------------------\n");

    printf("SAP ID       : %lld\n", s.sapID);
    printf("Roll Number  : %d\n", s.rollNo);
    printf("Name         : %s\n", s.name);
    printf("Phone Number : %s\n", s.phone);
    printf("Email ID     : %s\n", s.email);
    printf("Year         : %d\n", s.year);
    printf("Semester     : %d\n", s.semester);

    printf("SGPA:\n");

    for(int i = 0; i < s.semester; i++) {

        printf("Semester %d : %.2f\n",
               i + 1,
               s.sgpa[i]);
    }

    printf("CGPA         : %.2f\n", calculateCGPA(s));

    printf("----------------------------------\n");
}



void searchStudent() {

    long long searchID;
    int found = 0;

    printf("\nEnter SAP ID to search: ");
    scanf("%lld", &searchID);


    for(int i = 0; i < studentCount; i++) {

        if(students[i].sapID == searchID) {

            printf("\nStudent found!\n");

            displayStudent(students[i]);

            found = 1;

            break;
        }
    }


    if(found == 0) {

        printf("\nStudent not found.\n");
    }
}

float calculateCGPA(struct Student s) {

    float sum = 0;

    if(s.semester <= 0) {
        return 0;
    }


    for(int i = 0; i < s.semester; i++) {

        sum = sum + s.sgpa[i];
    }


    return sum / s.semester;
}




void averageCGPAByYear() {

    printf("\n----- AVERAGE CGPA BY YEAR -----\n");


    for(int year = 1; year <= 4; year++) {

        float sum = 0;
        int count = 0;


        for(int i = 0; i < studentCount; i++) {

            if(students[i].year == year) {

                sum = sum + calculateCGPA(students[i]);

                count++;
            }
        }


        if(count > 0) {

            printf("Year %d Average CGPA = %.2f\n",
                   year,
                   sum / count);
        }

        else {

            printf("Year %d: No students available\n",
                   year);
        }
    }
}




void displayAllStudents() {

    if(studentCount == 0) {

        printf("\nNo student records available.\n");

        return;
    }


    printf("\n========== ALL STUDENT RECORDS ==========\n");


    for(int i = 0; i < studentCount; i++) {

        printf("\nStudent %d\n", i + 1);

        displayStudent(students[i]);
    }
}




void deleteStudent() {

    long long deleteID;
    int index = -1;


    printf("\nEnter SAP ID of student to delete: ");
    scanf("%lld", &deleteID);



    for(int i = 0; i < studentCount; i++) {

        if(students[i].sapID == deleteID) {

            index = i;

            break;
        }
    }


    if(index == -1) {

        printf("\nStudent not found.\n");

        return;
    }


    for(int i = index; i < studentCount - 1; i++) {

        students[i] = students[i + 1];
    }


    studentCount--;

    printf("\nStudent deleted successfully!\n");
}



void sortBySAPID() {

    if(studentCount == 0) {

        printf("\nNo student records available.\n");

        return;
    }


    struct Student temp;



    for(int i = 0; i < studentCount - 1; i++) {

        for(int j = 0; j < studentCount - i - 1; j++) {

            if(students[j].sapID > students[j + 1].sapID) {

                temp = students[j];

                students[j] = students[j + 1];

                students[j + 1] = temp;
            }
        }
    }


    printf("\n===== STUDENTS SORTED BY SAP ID =====\n");


    for(int i = 0; i < studentCount; i++) {

        displayStudent(students[i]);
    }
}




void sortByName() {

    if(studentCount == 0) {

        printf("\nNo student records available.\n");

        return;
    }


    struct Student temp;



    for(int i = 0; i < studentCount - 1; i++) {

        for(int j = 0; j < studentCount - i - 1; j++) {

            if(strcmp(students[j].name,
                      students[j + 1].name) > 0) {

                temp = students[j];

                students[j] = students[j + 1];

                students[j + 1] = temp;
            }
        }
    }


    printf("\n===== STUDENTS SORTED BY NAME =====\n");


    for(int i = 0; i < studentCount; i++) {

        displayStudent(students[i]);
    }
}



void academicAdvisor() {

    long long searchID;
    int found = 0;


    printf("\nEnter SAP ID of student: ");
    scanf("%lld", &searchID);


    for(int i = 0; i < studentCount; i++) {

        if(students[i].sapID == searchID) {

            found = 1;


            float cgpa = calculateCGPA(students[i]);


            printf("\n===== AI-ASSISTED ACADEMIC ADVISOR =====\n");

            printf("Student Name : %s\n", students[i].name);
            printf("CGPA         : %.2f\n", cgpa);


            if(cgpa >= 9.0) {

                printf("Category     : Excellent Performance\n");

                printf("Advice       : Maintain your current study pattern and consistency.\n");
            }


            else if(cgpa >= 8.0) {

                printf("Category     : Good Performance\n");

                printf("Advice       : Keep working consistently and focus on weaker subjects.\n");
            }


            else if(cgpa >= 6.0) {

                printf("Category     : Needs Improvement\n");

                printf("Advice       : Give more attention to subjects with lower SGPA and practise regularly.\n");
            }


            else {

                printf("Category     : Requires Immediate Attention\n");

                printf("Advice       : Seek academic support and create a structured improvement plan.\n");
            }


            break;
        }
    }


    if(found == 0) {

        printf("\nStudent not found.\n");
    }
}




int main() {

    int choice;


    do {

        printf("\n========================================\n");
        printf("   STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("========================================\n");

        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Display CGPA of Students\n");
        printf("4. Average CGPA by Year\n");
        printf("5. Display All Students\n");
        printf("6. Delete Student\n");
        printf("7. Display Students Sorted by SAP ID\n");
        printf("8. Display Students Sorted by Name\n");
        printf("9. AI-Assisted Academic Advisor\n");
        printf("10. Exit\n");


        printf("\nEnter your choice: ");
        scanf("%d", &choice);


        switch(choice) {

       
            case 1:

                addStudent();

                break;


  
            case 2:

                searchStudent();

                break;


    
            case 3:

                if(studentCount == 0) {

                    printf("\nNo student records available.\n");
                }

                else {

                    printf("\n===== STUDENT CGPA =====\n");

                    for(int i = 0; i < studentCount; i++) {

                        printf("%s : %.2f\n",
                               students[i].name,
                               calculateCGPA(students[i]));
                    }
                }

                break;


   
            case 4:

                averageCGPAByYear();

                break;



            case 5:

                displayAllStudents();

                break;


  
            case 6:

                deleteStudent();

                break;


        
            case 7:

                sortBySAPID();

                break;


    
            case 8:

                sortByName();

                break;


      
            case 9:

                academicAdvisor();

                break;


       
            case 10:

                printf("\nExiting program...\n");

                break;


            default:

                printf("\nInvalid choice. Please try again.\n");
        }


    } while(choice != 10);


    return 0;
}
