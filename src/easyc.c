#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

// Function Prototypes
void print_status(int current, int total, char *exercise);
void print_options(void);
void reset(char *exercise);
void show_hint(int exercise);
void next(int current);
void back(int current);
void restart(int current);
char *get_location(int current, char *location);
int get_current_exercise(void);
int get_latest_exercise(void);

// Command Line Arguments
void help_menu(void);
void version_info(void);
void initialize_exercises(char *file);
void clean_exercises(void);
void run_exercise(int current_exercise);
void check_all(void);
void reset(char *exercise);

// Version of this software
const char VERSION[] = "0.1";

typedef struct {
    char filename[256];
    int keep_running;
} WatcherArgs;

int main(int argc, char* argv[]) {
    int exercises = 22; // TODO: Make this dynamic to all tests in exercises.config
    char exercise[256] = "00_intro";
    int current_exercise = get_current_exercise();
    int latest_exercise = get_latest_exercise();
    char location[256];
    char response;

    if (argc > 1) {
        if (strcmp(argv[1], "--help") == 0) {
            help_menu();
            return 0;
        } else if (strcmp(argv[1], "-V") == 0 || strcmp(argv[1], "--version") == 0) {
            version_info();
            return 0;
        } else if (strcmp(argv[1], "init") == 0) {
            if (!argv[2]) {
                clean_exercises();
            } else {
                initialize_exercises(argv[2]);
            }
            return 0;
        } else if (strcmp(argv[1], "run") == 0) {
            run_exercise(current_exercise);
            return 0;
        } else if (strcmp(argv[1], "check-all") == 0) {
            check_all();
            return 0;
        } else if (strcmp(argv[1], "reset") == 0) {
            if (!argv[2]) {
                printf("Usage: easyc reset [EXERCISE]\n");
                return 1;
            } else {
                reset(argv[2]);
                return 0;
            }
        } else if (strcmp(argv[1], "hint") == 0) {
            if (!argv[2]) {
                // Hint for "latest" incomplete exercise
                show_hint(latest_exercise);
                return 0;
            } else {
                show_hint(current_exercise);
                return 0;
            }
        }
    }

    get_location(1, location);
    print_status(current_exercise, exercises, location);

    print_options();

    do {
        response = getchar();

        if (response == 'n') {
            next(++current_exercise);
        } else if (response == 'b') {
            back(--current_exercise);
        } else if (response == 'h') {
            show_hint(current_exercise);
        } else if (response == 'r') {
            restart(current_exercise);
        } else if (response == 'q') {
            printf("Exiting...");
            return 0;
        } else {
            printf("Invalid Input: %s not recognized", response);
        }
    } while (1);

    return 0;
}

void print_status(int current, int total, char *exercise) {
    char location[256];
    // Print the location of the exercise after the tasks and number of tasks
    snprintf(location, sizeof(location), "%s", exercise);
    printf("Tasks: %d / %d \t%s\n", current, total, location);
}

void print_options(void) {
    printf("(h) Hint, (b) Back / (n) Next, (r) Reset, (q) Quit\n");
}

// Command Line Arguments
void help_menu(void) {
    printf("EasyC is a collection of small exercises to get you used to writing and reading C code\n");
    printf("\n\033[4mUsage:\033[0m easyc [OPTIONS] [COMMAND]\n");
    printf("\n\033[4mCommands:\033[0m\n");
    printf("  init       Initialize the official EasyC exercises\n");
    printf("  run        Run a single exercise. Runs the next pending exercise if the exercise name is not specified\n");
    printf("  check-all  Check all the exercises, marking them as done or pending accordingly\n");
    printf("  reset      Reset a single exercise\n");
    printf("  hint       Show a hint. Shows the hint of the next pending exercise if the exercise name is not specified\n");
    printf("  help       Print this message or the help of the given subcommand(s)\n");
    printf("\n\033[4mOptions:\033[0m\n");
    printf("      --manual-run  Manually run the current exercise using `r` in the watch mode. Only use this if EasyC fails to detect exercise file changes\n");
    printf("  -h, --help        Prints this help menu\n");
    printf("  -V, --version     Print version\n");
}

void version_info(void) {
    printf("EasyC %s\n", VERSION);
}

void initialize_exercises(char *file) {
    // Pull a fresh copy of the exercises with git
    // Use argv[2] (file pointer) as folder choice
}

void clean_exercises() {
    // Pull a fresh copy of the exercises with git to argv[2] location
}

void run_exercise(int current_exercise) {
    // Run the Makefile of a specific exercise
}

void check_all(void) {
    // Check every exercise for completion
    // Change config: 1 = completed, 0 = incomplete
}

void reset(char *exercise) {
    // Restore the exercise to it's Original version
}

void restart(int current) {
    // restart the current activity, restore to original (pull single from git?)
}

void show_hint(int exercise) {
    // Display the current.hint from exercises.config
}

void next(int current) {
    // next(++current): Advance to the next exercise IF and only if the user has completed or acknowledged
}

void back(int current) {
    // back(--current): Show the previous exercise
}

int get_current_exercise(void) {
    // Return the active exercise number or name
}

int get_latest_exercise(void) {
    // TODO: Find the most recent (can be, but probably isn't the currently active) finished exercise
}

char *get_location(int current, char *location) {
    // Display the location (in location[256]) for the exercise itself in the Taskbar
}
