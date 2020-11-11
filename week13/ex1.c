#include <stdio.h>
#include <stdbool.h>

// vary this to process as many processes and
// resource types, as needed
#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

// change this to open another files
#define FILE_INPUT "input_dl.txt"
#define FILE_OUTPUT "output_dl.txt"

int main() {
    FILE *file_input  = fopen(FILE_INPUT, "r");
    FILE *file_output = fopen(FILE_OUTPUT, "w");

    int E[MAX_RESOURCES], A[MAX_RESOURCES];
    int C[MAX_PROCESSES][MAX_RESOURCES], R[MAX_PROCESSES][MAX_RESOURCES];

    // boring input starts here
    int i, j;
    for (i = 0; i < MAX_RESOURCES; i++)
        fscanf(file_input, "%d", &E[i]);
    for (i = 0; i < MAX_RESOURCES; i++)
        fscanf(file_input, "%d", &A[i]);

    for (i = 0; i < MAX_PROCESSES; i++) {
        for (j = 0; j < MAX_RESOURCES; j++)
            fscanf(file_input, "%d", &C[i][j]);
    }

    for (i = 0; i < MAX_PROCESSES; i++) {
        for (j = 0; j < MAX_RESOURCES; j++)
            fscanf(file_input, "%d", &R[i][j]);
    }

    // here we go
    bool changes_made = true;
    bool processed[MAX_PROCESSES];
    int nprocessed = 0;

    for (i = 0; i < MAX_PROCESSES; i++)
        processed[i] = false;

    while (changes_made && nprocessed < MAX_PROCESSES) {
        changes_made = false;

        for (i = 0; i < MAX_PROCESSES; i++) {
            if (processed[i])
                continue;

            bool processable = true;
            for (j = 0; j < MAX_RESOURCES; j++) {
                if (R[i][j] > C[i][j] && A[j] < R[i][j] - C[i][j]) {
                    processable = false;
                    break;
                }
            }

            if (processable) {
                changes_made = true;
                nprocessed++;
                processed[i] = true;

                for (j = 0; j < MAX_RESOURCES; j++)
                    A[j] += C[i][j];
                break;
            }
        }
    }

    // output only, don't even read this
    if (changes_made) {
        fprintf(file_output, "U r lucky! No deadlock detected!");
    } else {
        fprintf(file_output, "Oops, here is deadlock in following processes (counting from 1):\n");
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (!processed[i])
                fprintf(file_output, "%d ", i+1);
        }
    }
    return 0;
}
