# AI-Assisted Student Record and Result Management System

A console-based, menu-driven program written in C. It stores student details and SGPA values, calculates CGPA, sorts records, and gives simple academic advice from a student's CGPA.

## Repository structure

```
student-record-ai-c/
├── 590036370.c          # C source code
├── README.md            # this file
├── Ai_Usage_Log(1).md   # how AI tools were used
└── tests/
    ├── sample_input.txt     # sample data: 5 students and menu choices
    └── sample_output.txt    # output of the program for that input
```

## Features (menu options)

| Option | What it does |
|--------|--------------|
| 1. Add Student | Stores SAP ID, Roll No., Name, Phone, Email, Year, Semester and SGPA for all 8 semesters |
| 2. Search Student | Finds a student by SAP ID and displays the full record |
| 3. Calculate Student CGPA | Shows the CGPA of one student (average of the available SGPA values) |
| 4. Display Average CGPA by Year | Average CGPA of the students in each year (1 to 4) |
| 5. Display All Students | Shows every record |
| 6. Delete Student | Deletes a student by SAP ID |
| 7. Display Students by SAP ID | Shows all records in increasing order of SAP ID |
| 8. Display Students by Name | Shows all records in increasing order of name (not case-sensitive) |
| 9. AI-Assisted Academic Advisor | Gives advice from the student's CGPA using if-else |
| 10. Exit | Closes the program |

## How to enter a student

Option 1 asks for these in order: SAP ID, Roll No., name, 10-digit phone, email, year (1-4), current semester, then the SGPA for each of the 8 semesters. Type `-1` for a semester with no result. After a successful entry the program prints `Student added successfully. Total students stored: N.`

## Checks made on input

- SAP ID and Roll No. must be unique
- Phone must be exactly 10 digits
- Email must look like `name@domain.ext`
- Year must be 1 to 4, and the semester must belong to that year
- SGPA must be between 0 and 10, or `-1` if not available
- Wrong or empty input is rejected and asked again

## Academic advisor

The advice is chosen by the C program from the student's CGPA:

| CGPA | Advice |
|------|--------|
| 9.0 and above | Excellent Performance: Maintain your current study pattern. |
| 7.5 to below 9.0 | Good Performance: Keep practicing and aim higher. |
| 6.0 to below 7.5 | Needs Improvement: Focus on subjects with lower SGPA. |
| Below 6.0 | Requires Immediate Attention: Make a study schedule and seek faculty guidance. |

The sample output shows all four cases (CGPA 9.25, 8.03, 6.65 and 5.13).

## Development and GitHub workflow

The project was built one feature at a time, with a commit for each stage:

1. Initial C program: structure, input helpers and menu
2. Student record functions: add, search, display all, delete
3. Sorting/CGPA functions: CGPA, yearly average, sort by SAP ID and name
4. AI-assisted advisor + documentation: academic advisor, README, AI usage log, sample tests

A GitHub Issue ("Test search function") was created for testing the search feature and closed after testing.

## AI usage

AI tools were used while building this project. The details are in [Ai_Usage_Log(1).md](Ai_Usage_Log%281%29.md) and in this commit: https://github.com/nithya-rgb/assignment/commit/5cb3f30afcceaa2e9abcc60f5beda6f0d704fe4c
