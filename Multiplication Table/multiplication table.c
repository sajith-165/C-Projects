#include <stdio.h>

int get_data();
char reply();
void table(int, int, FILE *filePtr);
void SaveTable (int, int, FILE *filePtr);
void output(int, int, char, FILE *filePtr);

int main() // main function
{
    FILE *filePtr; // File pointer
    // Open file in write mode
    filePtr = fopen("multiplication_table.txt", "w");

    // Check if file opened successfully
    if (filePtr == NULL)
    {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("(Columns should be less than 15 for a better display)\n\n");

    // get number of columns
    printf("How far long columns need? ");
    int columns = get_data();

    // get number of rows
    printf("\nHow far long row need? ");
    int row = get_data();

    // Generate table
    table(columns, row, filePtr);

    // ask to save multipilication table
    char option = reply();

    // final output
    output(columns, row, option, filePtr);

    // Close the file
    fclose(filePtr);

    return 0;
}

// Table function Definition
void table(int columns, int row, FILE *filePtr)
{
    printf("\n\n\t\t\t   Multiplication Table: %d x %d\n", columns, row);
    printf("\t\t\t _______________________________\n\n");

    for (int i = 1; i <= row; i++)
    {
        printf("  %-3d-->  | ", i);
        for (int f = 1; f <= columns; f++)
            {
                printf(" %-4d |", i * f); // Print table
            }

        printf("\n"); // Blank line for structure

    }
}

// SaveTable function Definition
void SaveTable (int columns, int row, FILE *filePtr)
{
    fprintf(filePtr, "\n\t\tMultiplication Table: %d x %d\n", columns, row);
    fprintf(filePtr, "\t\t_______________________________\n\n");

        for (int i = 1; i <= row; i++)
        {
        fprintf(filePtr, "  %-3d-->  | ", i); // Write to file
            for (int f = 1; f <= columns; f++)
            {
                fprintf(filePtr, " %-4d |", i * f); // Write to file
            }
        fprintf(filePtr, "\n"); // Newline in file
        }
}

// Get data function Definition
int get_data()
{
    int data;
    while (1)
    {
        if (scanf("%d", &data) != 1 || data <= 0) // Error handling
        {
            printf("Invalid input! Try a positive number: ");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }
        break;
    }
    return data;
}

// ask to save table function
char reply()
{
    printf ("\n\n Are you like to save this table ( y / n ) : ");
    char reply;
        while (1)
        {
            if(scanf (" %c",&reply) != 1 || (reply=='y'||reply=='Y'||reply=='n'||reply=='N') != 1 )
            {
                printf(" Invalid input! Say ( y / n ) : ");
                while (getchar() != '\n'); // Clear buffer
                continue;
            }
        break;
        }
    return reply;

}

// final output
void output(int columns, int row, char option, FILE *filePtr)
{
    if (option == 'y' || option == 'Y' )
        {
            SaveTable(columns, row, filePtr);
            printf("\n Table saved to 'multiplication_table.txt'\n\n");
            printf (" your table save successfully!\n");
            printf ("\t thanks for using program..\n");
        }
    else
        {
            printf ("\n not save your table..\n");
            printf ("\t thanks for using program..\n");
        }
}

