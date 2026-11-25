#23_WiFighters_Student-Attendance-Analyser

Smart Campus Attendance Management System

1. Project Overview

The Smart Campus Attendance Management System is a menu-driven C program developed to manage student attendance records. It provides separate Admin and Student portals to make attendance tracking easier and more organized.

2. Problem Statement

Maintaining student attendance manually can be time-consuming. This project provides a computerized system to register students, record attendance, calculate attendance percentages and identify students with low attendance.

3. Objectives

- Maintain student records.
- Record daily attendance.
- Calculate student attendance percentages.
- Identify students with attendance below 75%.
- Allow students to check their attendance.
- Store records using file handling.

4. Features

Admin Portal

1. Register a new student.
2. Remove an existing student.
3. Mark students as Present or Absent.
4. View attendance reports.
5. View the defaulter list.
6. Search for a student.
7. Logout.

Student Portal

1. Search using roll number.
2. View personal details.
3. Check classes held and attended.
4. View attendance percentage.

File Handling

- Save student records in "attendance.txt".
- Load previously saved records when the program starts.

5. Attendance Calculation

Attendance Percentage = (Classes Attended / Classes Held) × 100

Students having attendance below 75% are included in the defaulter list.

Attendance is calculated from the student's registration date in this system.

6. Algorithm

1. Start the program.
2. Load previously saved student records.
3. Display the main menu.
4. Allow the user to select Admin Portal, Student Portal or Save.
5. In Admin Portal, provide options to register, remove, search students, mark attendance and view reports.
6. Calculate attendance percentage for each student.
7. Display students whose attendance is below 75%.
8. In Student Portal, accept the student's roll number and display their attendance details.
9. Save records to the file when requested.
10. Repeat the menu.

7. C Programming Concepts Used
- Variables and data types
- Conditional statements
- Loops
- Arrays
- Strings
- Functions
- Structures
- File handling
- Input validation

8. Compilation and Execution

Source file: "Project.c"

Compile:

"gcc Project.c"

Run:

"./Project.c"

9. Team Details

Team Name: 23_WiFighters

Team Members:
1. Pratibha Rawat
2. Kanika Saini
3. Abhijeet Chandra

10. Conclusion
The Smart Campus Attendance Management System demonstrates how C programming concepts can be used to develop a simple and useful attendance management application. It helps organize student records and makes attendance tracking easier.

Output Screenshots
Program output screenshots are uploaded separately in the GitHub repository under the "Output_Screenshots" folder.
