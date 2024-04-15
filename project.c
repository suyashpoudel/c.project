#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

// Function prototypes
void readStudentDetails(struct Student *s);
void displayStudentDetails(const struct Student *s);
void saveStudentDetails(const struct Student *s);
void readFromFile(struct Student *s);

int main() {
    // Declare a variable of type struct Student
    struct Student s;

    // Call function to read student details from user
    readStudentDetails(&s);

    // Call function to display student details
    displayStudentDetails(&s);

    // Call function to save student details to file
    saveStudentDetails(&s);

    // Call function to read student details from file and display them
    readFromFile(&s);

    return 0;
}

// Function to read student details from the user
void readStudentDetails(struct Student *s) {
    // Prompt the user to enter details
    printf("Enter Roll Number: ");
    // Read roll number from the user
    scanf("%d", &s->rollNumber);
    // Prompt the user to enter name
    printf("Enter Name: ");
    // Read name from the user
    scanf("%s", s->name);
    // Prompt the user to enter marks
    printf("Enter Marks: ");
    // Read marks from the user
    scanf("%f", &s->marks);
}

// Function to display student details
void displayStudentDetails(const struct Student *s) {
    // Display student details
    printf("\nStudent Details:\n");
    printf("Roll Number: %d\n", s->rollNumber);
    printf("Name: %s\n", s->name);
    printf("Marks: %.2f\n", s->marks);
}

// Function to save student details to a file
void saveStudentDetails(const struct Student *s) {
    // Open file in write mode
    FILE *file = fopen("student_details.txt", "w");
    // Check if file opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1); // Exit the program with error code
    }
    // Write student details to the file
    fprintf(file, "%d %s %.2f\n", s->rollNumber, s->name, s->marks);
    // Close the file
    fclose(file);
    // Display success message
    printf("Student details saved to file successfully.\n");
}

// Function to read student details from a file
void readFromFile(struct Student *s) {
    // Open file in read mode
    FILE *file = fopen("student_details.txt", "r");
    // Check if file opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1); // Exit the program with error code
    }
    // Display message indicating reading from file
    printf("\nReading student details from file:\n");
    // Read student details from file
    fscanf(file, "%d %s %f", &s->rollNumber, s->name, &s->marks);
    // Close the file
    fclose(file);
    // Display the student details read from file
    displayStudentDetails(s);
}




