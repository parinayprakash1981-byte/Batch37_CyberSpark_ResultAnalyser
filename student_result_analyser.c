// Student Result and Grade Analyser
// Only basic concepts: variables, arrays, loops, if-else, switch

#include <stdio.h>

int main()
{
    int n, i, j, choice;
    int m;                  // marks of one subject (temporary)

    int roll[50];           // roll number of each student
    int total[50];          // total marks of each student
    float percentage[50];   // percentage of each student
    char grade[50];         // grade of each student (A, B, C, D, F)
    int pass[50];           // 1 = pass, 0 = fail

    // ---------- Step 1: number of students ----------
    printf("How many students (1 to 50)? ");
    scanf("%d", &n);

    while (n < 1 || n > 50)
    {
        printf("Wrong number! Enter between 1 and 50: ");
        scanf("%d", &n);
    }

    // ---------- Step 2: take data of every student ----------
    for (i = 0; i < n; i++)
    {
        printf("\n--- Student %d ---\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &roll[i]);

        // roll number should not repeat
        for (j = 0; j < i; j++)
        {
            if (roll[j] == roll[i])
            {
                printf("Roll number already used! Enter again: ");
                scanf("%d", &roll[i]);
                j = -1;     // check again from the start
            }
        }

        total[i] = 0;
        pass[i] = 1;        // first we think student is pass

        for (j = 1; j <= 5; j++)
        {
            printf("Enter marks of subject %d: ", j);
            scanf("%d", &m);

            while (m < 0 || m > 100)
            {
                printf("Wrong marks! Enter between 0 and 100: ");
                scanf("%d", &m);
            }

            total[i] = total[i] + m;

            if (m < 33)
            {
                pass[i] = 0;    // failed in this subject
            }
        }

        percentage[i] = total[i] / 5.0;   // total out of 500 = total / 5

        if (percentage[i] >= 80)
            grade[i] = 'A';
        else if (percentage[i] >= 70)
            grade[i] = 'B';
        else if (percentage[i] >= 60)
            grade[i] = 'C';
        else if (percentage[i] >= 50)
            grade[i] = 'D';
        else
            grade[i] = 'F';
    }

    // ---------- Step 3: menu ----------
    while (1)
    {
        printf("\n===== STUDENT RESULT ANALYSER =====\n");
        printf("1. Show all students\n");
        printf("2. Search student by roll number\n");
        printf("3. Class topper\n");
        printf("4. Class average\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            for (i = 0; i < n; i++)
            {
                printf("\nRoll: %d\n", roll[i]);
                printf("Total: %d/500\n", total[i]);
                printf("Percentage: %.2f\n", percentage[i]);
                printf("Grade: %c\n", grade[i]);
                if (pass[i] == 1)
                    printf("Result: PASS\n");
                else
                    printf("Result: FAIL\n");
            }
            break;

        case 2:
        {
            int r, found = 0;
            printf("Enter roll number to search: ");
            scanf("%d", &r);

            for (i = 0; i < n; i++)
            {
                if (roll[i] == r)
                {
                    printf("\nRoll: %d\n", roll[i]);
                    printf("Total: %d/500\n", total[i]);
                    printf("Percentage: %.2f\n", percentage[i]);
                    printf("Grade: %c\n", grade[i]);
                    if (pass[i] == 1)
                        printf("Result: PASS\n");
                    else
                        printf("Result: FAIL\n");
                    found = 1;
                }
            }

            if (found == 0)
                printf("Student not found!\n");
            break;
        }

        case 3:
        {
            int top = -1;   // -1 means topper not found yet

            for (i = 0; i < n; i++)
            {
                if (pass[i] == 1)
                {
                    if (top == -1 || total[i] > total[top])
                        top = i;
                }
            }

            if (top == -1)
                printf("No student passed, so no topper.\n");
            else
                printf("\nTopper: Roll %d, Total %d/500, Percentage %.2f\n",
                       roll[top], total[top], percentage[top]);
            break;
        }

        case 4:
        {
            float sum = 0;
            int passed = 0;

            for (i = 0; i < n; i++)
            {
                sum = sum + percentage[i];
                if (pass[i] == 1)
                    passed++;
            }

            printf("\nTotal students: %d\n", n);
            printf("Passed: %d\n", passed);
            printf("Failed: %d\n", n - passed);
            printf("Class average: %.2f\n", sum / n);
            break;
        }

        case 5:
            printf("Thank you!\n");
            return 0;

        default:
            printf("Wrong choice! Enter 1 to 5.\n");
        }
    }
}