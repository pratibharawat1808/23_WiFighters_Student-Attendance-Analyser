#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
struct Student{
    int rollNo;
    char name[50];
    int classesHeld;
    int attended;};
struct Student s[MAX];
int count = 0;
int readInt(char message[]){
    char line[100];
    int value;
    while (1){
        printf("%s", message);
        if (fgets(line, sizeof(line), stdin) == NULL)
          return 0;
        if (sscanf(line, "%d", &value) == 1)
          return value;
        printf("Invalid input! Enter a number.\n");}}
void readText(char message[], char text[], int size){
    printf("%s", message);
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0';}
float percentage(int i){
    if (s[i].classesHeld == 0)
        return 0;
    return (s[i].attended * 100.0) /
           s[i].classesHeld;}
int search(int roll){
    for (int i = 0; i < count; i++){
        if (s[i].rollNo == roll)
            return i;}
    return -1;}

void registerStudent(void) {
    int roll;
    char choice;
    do {
        if (count >= MAX) {
            printf("Student limit reached.\n");
            break;}
        roll = readInt("Enter roll number: ");
        if (roll < 0) {
            printf("Invalid roll number.\n");
            continue;}
        if (search(roll) != -1) {
            printf("This roll number is already registered.\n");
            continue;}
        s[count].rollNo = roll;
        readText("Enter student name: ",
                 s[count].name, sizeof(s[count].name));
        if (strlen(s[count].name) == 0) {
            printf("Name cannot be empty.\n");
            continue;}
        s[count].classesHeld = 0;
        s[count].attended = 0;
        count++;
        printf("\nStudent registered successfully!\n");
        printf("Do you want to register another student? (Y/N): ");
        scanf(" %c", &choice);
        while (getchar() != '\n');}
     while (choice == 'Y' || choice == 'y');
}
void removeStudent(){
    int roll = readInt("Enter roll number to remove: ");
    int i = search(roll);
    if (i == -1){
        printf("Student not found!\n");
        return;
    }
    for (int j = i; j < count - 1; j++){
        s[j] = s[j + 1];
    }
    count--;
    printf("Student removed successfully!\n");}
void markAttendance(){
    if (count == 0){
        printf("No students registered!\n");
        return;}
    printf("\n--- MARK ATTENDANCE ---\n");
    for (int i = 0; i < count; i++){
        char line[100];
        char status;
        printf("\nRoll No: %d\n", s[i].rollNo);
        printf("Name: %s\n", s[i].name);
        do{
            readText("Enter P for Present or A for Absent: ",
                     line, sizeof(line));
            status = toupper((unsigned char)line[0]);
            if (strlen(line) != 1 ||
                (status != 'P' && status != 'A')){
                printf("Enter only P or A!\n");}
        } while (strlen(line) != 1 ||
                 (status != 'P' && status != 'A'));
        s[i].classesHeld++;
        if (status == 'P')
            s[i].attended++;
    }
    printf("\nAttendance recorded successfully!\n");
}
void attendanceReport(){
    if (count == 0){
        printf("No student records available!\n");
        return;}
    printf("\n--- ATTENDANCE REPORT ---\n");
    for (int i = 0; i < count; i++){
        printf("\nRoll No: %d", s[i].rollNo);
        printf("\nName: %s", s[i].name);
        printf("\nClasses Held: %d", s[i].classesHeld);
        printf("\nClasses Attended: %d", s[i].attended);
        printf("\nPercentage: %.2f%%\n",
               percentage(i));}}
void defaulterList(){
    int found = 0;
    printf("\n--- DEFAULTER LIST ---\n");
    for (int i = 0; i < count; i++){
        if (s[i].classesHeld > 0 &&
            percentage(i) < 75){
            printf("\n%s | Roll No: %d | %.2f%%\n",
                   s[i].name,
                   s[i].rollNo,
                   percentage(i));
            found = 1;}}
    if (found == 0)
        printf("No defaulters found!\n");}
void searchStudent(){
    int roll = readInt("Enter roll number: ");
    int i = search(roll);
    if (i == -1){
        printf("Student not found!\n");
        return;}
    printf("\nName: %s\n", s[i].name);
    printf("Roll Number: %d\n", s[i].rollNo);
    printf("Classes Held: %d\n", s[i].classesHeld);
    printf("Classes Attended: %d\n", s[i].attended);
    printf("Attendance: %.2f%%\n", percentage(i));}
void studentPortal(){
    printf("\n--- STUDENT PORTAL ---\n");
    searchStudent();}
void adminPortal(){
    int choice;
    do{
        printf("\n--- ADMIN PORTAL ---\n");
        printf("1. Register Student\n");
        printf("2. Remove Student\n");
        printf("3. Mark Attendance\n");
        printf("4. View Attendance Report\n");
        printf("5. View Defaulter List\n");
        printf("6. Search Student\n");
        printf("7. Logout\n");
        choice = readInt("Enter choice: ");
        switch (choice){
            case 1:
                registerStudent();
                break;
            case 2:
                removeStudent();
                break;
            case 3:
                markAttendance();
                break;
            case 4:
                attendanceReport();
                break;
            case 5:
                defaulterList();
                break;
            case 6:
                searchStudent();
                break;
            case 7:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice!\n");}
    } while (choice != 7);}
void saveToFile(){
    FILE *fp = fopen("attendance.txt", "w");
    if (fp == NULL){
        printf("Unable to save file!\n");
        return;}
    for (int i = 0; i < count; i++){
        fprintf(fp, "%d|%s|%d|%d\n",
                s[i].rollNo,
                s[i].name,
                s[i].classesHeld,
                s[i].attended);}
    fclose(fp);
    printf("Records saved successfully!\n");}
void loadFromFile(){
    FILE *fp = fopen("attendance.txt", "r");
    if (fp == NULL)
        return;
    while (count < MAX &&
           fscanf(fp, "%d|%49[^|]|%d|%d\n",
                  &s[count].rollNo,
                  s[count].name,
                  &s[count].classesHeld,
                  &s[count].attended) == 4)
    {count++;}
    fclose(fp);}
int main(){
    int choice;
    loadFromFile();
    while(1){
        printf("\n==============================\n");
        printf(" SMART CAMPUS ATTENDANCE SYSTEM\n");
        printf("==============================\n");
        printf("1. Admin Portal\n");
        printf("2. Student Portal\n");
        printf("3. Save\n");
        choice = readInt("Enter choice: ");
        switch (choice){
            case 1:
                adminPortal();
                break;
            case 2:
                studentPortal();
                break;
            case 3:
                saveToFile();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
