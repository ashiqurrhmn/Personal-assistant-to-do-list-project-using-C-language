#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASKS 100

// Structure to represent a task
typedef struct
{
    int id;
    char description[1000];
    int completed;
    char date[20];
    char dateCheck[20];
} Task;

// Function to add a new task
void addTask(Task* tasks, int* numTasks)
{
    system("cls");
    while (1)
    {
        char c;
        printf("Press 'Y' or 'y' to add a task or press 'N' or 'n' to return: ");

        fflush(stdin);
        scanf("%c", &c);

        if (c == 'n' || c == 'N')
        {
            break;
        }
        else if (c == 'Y' || c == 'y')
        {
            if (*numTasks >= MAX_TASKS)
            {
                printf("Cannot add more tasks. Maximum limit reached.\n");
                return;
            }

            Task newTask;
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", newTask.date);
            printf("Enter the task number: ");
            scanf("%d", &newTask.id);
            printf("Enter the task description: ");
            scanf(" %[^\n]", newTask.description);

            newTask.completed = 0;

            tasks[*numTasks] = newTask;
            (*numTasks)++;
            printf("\n\nTask added successfully.\n\n");
            printf("\n\nWant to add more tasks?\n\n");
        }
    }
}

// Function to update a task
void updateTask(Task* tasks, int numTasks)
{
    system("cls");
    printf("Here are the tasks list:\n");
    for (int i = 0; i < numTasks; i++)
    {
        printf("Date:%s\n%d: %s\n\n", tasks[i].date, tasks[i].id, tasks[i].description);
    }
    int taskId, i;
    printf("Enter the task number to update: ");
    scanf("%d", &taskId);

    for (i = 0; i < numTasks; i++)
    {
        if (tasks[i].id == taskId)
        {
            printf("Enter the updated description for task %d: ", taskId);
            scanf(" %[^\n]", tasks[i].description);
            printf("\n\nTask %d has been updated.\n\n\n", taskId);
            system("pause");
            return;
        }
    }
    printf("%d task not found.\n\n\n", taskId);
    system("pause");
}

// Function to mark a task as completed
void completeTask(Task* tasks, int numTasks)
{
    system("cls");
    printf("Here are the tasks list:\n");
    for (int i = 0; i < numTasks; i++)
    {
        printf("Date:%s\n%d: %s\n\n", tasks[i].date, tasks[i].id, tasks[i].description);
    }
    int taskId, i;

    printf("Enter the task number to mark as completed: ");
    scanf("%d", &taskId);

    for (i = 0; i < numTasks; i++)
    {
        if (tasks[i].id == taskId)
        {
            tasks[i].completed = 1;
            printf("\n\nTask %d has been marked as completed.\n\n\n", taskId);
            system("pause");
            return;
        }
    }
    printf("%d task not found.\n", taskId);
    system("pause");
}

// Function to display all tasks
void displayTasks(Task* tasks, int numTasks)
{
    system("cls");

    for (int i = 0; i < numTasks; i++)
    {
        printf("Date:%s\n%d: %s\n\n", tasks[i].date, tasks[i].id, tasks[i].description);
    }

    printf("\n\n\n");
    system("pause");
}

// Function to check if the given date matches the target date
int checkTargetDate(char* date, int targetDay, int targetMonth, int targetYear)
{
    int day, month, year;
    sscanf(date, "%d-%d-%d", &year, &month, &day);

    if (day == targetDay && month == targetMonth && year == targetYear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void upcomingAndCompletedTasks(Task* tasks, int numTasks)
{
    system("cls");

    for (int i = 0; i < numTasks; i++)
    {
        printf("Date:%s\n%d: %s (%s)\n\n",tasks[i].date, tasks[i].id, tasks[i].description, tasks[i].completed ? "Completed" : "Upcoming");
    }
    printf("\n\n\n");
    system("pause");
}

// Function to cancel a task
void removeTask(Task* tasks, int* numTasks)
{
    system("cls");
    printf("Here are the tasks list:\n");
    for (int i = 0; i < *numTasks; i++)
    {
        printf("Date:%s\n%d: %s\n\n",tasks[i].date, tasks[i].id, tasks[i].description);
    }
    int taskId, i;

    printf("Enter the task number to remove: ");
    scanf("%d", &taskId);

    for (i = 0; i < *numTasks; i++)
    {
        if (tasks[i].id == taskId)
        {
            // Shift the remaining tasks to fill the gap
            for (int j = i; j < *numTasks - 1; j++)
            {
                tasks[j] = tasks[j + 1];
            }

            (*numTasks)--;
            printf("\n\nTask %d has been canceled.\n\n\n", taskId);
            system("pause");
            return;
        }
    }
    printf("%d task not found.\n", taskId);
    system("pause");
}
// Function to save upcoming and completed tasks to a file
void saveTasksToFile(Task* tasks, int numTasks)
{
    FILE* file = fopen("tasks.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < numTasks; i++)
    {
        fprintf(file, "Date:%s\n%d: %s (%s)\n\n", tasks[i].date, tasks[i].id, tasks[i].description, tasks[i].completed ? "Completed" : "Upcoming");
    }

    fclose(file);
    printf("\n\nTasks saved to file successfully.\n");
}



void home()
{
    //home page
    system("color 5F");
    printf("\n\n\n\n");

    printf("\t~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n\n");
    printf("\t   } : } : } : } "
           ": } : } : } :   "
           "WELCOME TO TEAM RAWS'S PROJECT"
           "  : { : { : { "
           ": { : { : { : {\n\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");

    //tap for next page
    system("pause");
}

int main()
{
    Task tasks[MAX_TASKS];
    int numTasks = 0;
    int choice;
    home();
    while (1)
    {
        system("cls");
        system("Color 4"); //color

        //system("cls");//for cleaning console
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Mark Task as Complete\n");
        printf("4. Update Task\n");
        printf("5. Check tasks for Specific Date\n");
        printf("6. Display Upcoming and Completed Tasks\n");
        printf("7. Cancel Task\n");
        printf("8. Save Latest Tasks to File and Exit the program\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTask(tasks, &numTasks);
            break;
        case 2:
            displayTasks(tasks, numTasks);
            break;
        case 3:
            completeTask(tasks, numTasks);
            break;
        case 4:
            updateTask(tasks, numTasks);
            break;
        case 5:
            {
                int day, month, year;
                printf("Enter the target date (YYYY-MM-DD): ");
                scanf("%d-%d-%d", &year, &month, &day);

                system("cls");
                printf("Tasks scheduled for %d-%02d-%02d:\n", year, month, day);
                int found = 0;
                for (int i = 0; i < numTasks; i++)
                {
                    if (checkTargetDate(tasks[i].date, day, month, year))
                    {
                        printf("Date:%s\n%d: %s (%s)\n\n",tasks[i].date, tasks[i].id, tasks[i].description, tasks[i].completed ? "Completed" : "Upcoming");
                        found = 1;
                    }
                }
                if (!found)
                {
                    printf("No tasks found for the specified date.\n");
                }
                printf("\n\n\n");
                system("pause");
            }
            break;
        case 6:
            upcomingAndCompletedTasks(tasks, numTasks);
            break;
        case 7:
            removeTask(tasks, &numTasks);
            break;
        case 8:
            saveTasksToFile(tasks, numTasks);
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
            system("pause");
        }
    }

    return 0;
}

