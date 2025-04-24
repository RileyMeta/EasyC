#include <stdio.h>

#include "misc.h"   // Misc Utilities, to not clutter main file

void print_status(int current, int tasks);
void print_task(int current);
void print_options(void);
void hint(int current);
void next(int current);
void back(int current);
void reset(int current);

int main(int argc, char* argv[]) {
    int tasks[22] = {0};
    int task_size = sizeof(tasks) / sizeof(tasks[0]);

    int current_task = 0; // TODO: Fix this to track dynamically

    print_status(current_task, task_size);
    print_task(current_task);
    print_options();

    do {
        char input;
        printf("> ");
        scanf(" %c", &input);

        if (input == 'h') {
            hint(current_task);
       } else if (input == 'n') {
            next(current_task);
        } else if (input == 'b') {
            back(current_task);
        } else if (input == 'r') {
            reset(current_task);
        } else if (input == 'q') {
            clear();
            printf("Thank you for using %s\nYour progress has been saved.\n", argv[0]);
            return 0;
        } else {
            printf("Unknown Input\n");
            continue;
        }
    } while (1);
    return 0;
}

void print_status(int current, int tasks) {
    printf("Tasks: %d / %d\n", current, tasks);
}

void print_task(int current) {
    // TODO: Add dynamic tracking to comments from tasks.config file
}

void print_options() {
    printf("(h) for Hints, (r) Reset current, (n) Next / (b) Back, (q) to Quit\n");
}

void hint(int current) {
    // TODO: Add file reading to this so hints can be loaded automatically
}

void next(int current) {
    // TODO: Make sure current is complete before continuing
    // TODO: Incriment counter and display information
}

void back(int current) {
    // TODO: Decrement counter and display information
}

void reset(int current) {
    // TODO: Reset the current file
    // restore file to original (maybe git/pull each file to restore?)
}
