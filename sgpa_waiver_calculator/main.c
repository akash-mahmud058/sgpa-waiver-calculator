#include <stdio.h>

// Function to calculate grade point based on marks
float getGradePoint(float marks) {
    if (marks >= 80 && marks <= 100) return 4.00;
    else if (marks >= 75 && marks < 80) return 3.75;
    else if (marks >= 70 && marks < 75) return 3.50;
    else if (marks >= 65 && marks < 70) return 3.25;
    else if (marks >= 60 && marks < 65) return 3.00;
    else if (marks >= 55 && marks < 60) return 2.75;
    else if (marks >= 50 && marks < 55) return 2.50;
    else if (marks >= 45 && marks < 50) return 2.25;
    else if (marks >= 40 && marks < 45) return 2.00;
    else return 0.00; // F
}

// Function to calculate waiver percentage based on SGPA
float getWaiverPercentage(float sgpa) {
    if (sgpa == 4.00) return 50.0; // 50% waiver
    else if (sgpa >= 3.90 && sgpa <= 3.99) return 30.0; // 30% waiver
    else if (sgpa >= 3.85 && sgpa <= 3.89) return 20.0; // 20% waiver
    else if (sgpa >= 3.80 && sgpa <= 3.84) return 10.0; // 10% waiver
    else return 0.0; // No waiver
}

int main() {
    char name[50];
    char studentID[20];

    // Software name and description
    printf("SGPA Calculator v1.0\n");
    printf("SGPA calculator for Spring 2025 SWE students (Batch 43)\n");
    printf("----------------------------------------\n");

    // Input name and student ID
    printf("Enter your name: ");
    scanf(" %[^\n]", name);

    printf("Enter your Student ID: ");
    scanf(" %[^\n]", studentID);

    // Number of courses
    int numCourses = 5;

    // Arrays to store course details
    char courseCodes[5][10] = {"SE 212", "MAT 102", "PHY 101", "SE 122", "SE 121"};
    int credits[5] = {3, 3, 3, 1, 3}; // Credits for each course
    float marks[5]; // To store marks for each course
    float gradePoints[5]; // To store grade points for each course

    // Input marks for each course
    printf("\nEnter marks for each course (out of 100):\n");
    for (int i = 0; i < numCourses; i++) {
        printf("%s: ", courseCodes[i]);
        scanf("%f", &marks[i]);

        // Check if marks are valid
        if (marks[i] < 0 || marks[i] > 100) {
            printf("Invalid marks! Marks should be between 0 and 100.\n");
            return 1;
        }

        // Calculate grade point for the marks
        gradePoints[i] = getGradePoint(marks[i]);
    }
 printf("----------------------------------------\n");
    // Display results with name and ID
    printf("\nStudent Name: %s\n", name);
    printf("Student ID: %s\n", studentID);
    printf("\n--- Course Details ---\n");
    printf("Code\tCredit\tMarks\tGrade Point\n");
    for (int i = 0; i < numCourses; i++) {
        printf("%s\t%d\t%.2f\t%.2f\n", courseCodes[i], credits[i], marks[i], gradePoints[i]);
    }

    // Calculate SGPA
    float totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; i++) {
        totalGradePoints = totalGradePoints + (gradePoints[i] * credits[i]);
        totalCredits = totalCredits + credits[i];
    }

    float sgpa = totalGradePoints / totalCredits;

    // Display SGPA and total credits
    printf("\nTotal Credits: %d\n", totalCredits);
    printf("SGPA: %.2f\n", sgpa);

    // Calculate and display waiver percentage
    float waiver = getWaiverPercentage(sgpa);
    printf("Tuition Fee Waiver: %.0f%%\n", waiver);

    // Give feedback based on SGPA
    if (sgpa >= 3.75) {
        printf("Remark: Excellent performance!\n");
    } else if (sgpa >= 3.00) {
        printf("Remark: Good performance.\n");
    } else if (sgpa >= 2.00) {
        printf("Remark: You passed, but improvement is needed.\n");
    } else {
        printf("Remark: You have failed. Please work harder.\n");
    }

    return 0;
}
