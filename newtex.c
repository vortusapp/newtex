#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
    #include <windows.h>
    #define PATH_SEPARATOR '\\'
    #define PATH_MAX MAX_PATH
#else
    #include <unistd.h>
    #define PATH_SEPARATOR '/'
#endif

void copy_template_to_file(const char* template_path, const char* filename) {
    FILE* source = fopen(template_path, "r");
    FILE* dest = fopen(filename, "w");

    if (!source || !dest) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, dest);
    }

    fclose(source);
    fclose(dest);
}

int main(int argc, char* argv[]) {
    const char* filename = "document.tex";
    const char* type = "assignment";
    char template_path[PATH_MAX];

    if (argc > 1) {
        filename = argv[1];
    }
    if (argc > 2) {
        type = argv[2];
    }

    char exe_path[PATH_MAX];
#ifdef _WIN32
    GetModuleFileName(NULL, exe_path, MAX_PATH);  // Get the full path of the executable
#else
    ssize_t len = readlink("/proc/self/exe", exe_path, sizeof(exe_path) -1);
    if (len != -1) {
        exe_path[len] = '\0';
    } else {
        perror("Error getting executable path");
        exit(EXIT_FAILURE);
    }
#endif

    // Get the user's home directory path
    const char* home_dir = getenv("HOME");
    if (!home_dir) {
        perror("Error getting home directory");
        exit(EXIT_FAILURE);
    }

    // Construct the template path based on the type
    sprintf(template_path, "%s/.config/newtex/templates/%s.tex", home_dir, type);

    FILE *testFile = fopen(template_path, "r");
    if (testFile) {
        fclose(testFile);
        copy_template_to_file(template_path, filename);
        printf("TeX file created as: %s\n", filename);
    } else {
        printf("Error: No template found at path '%s' for type '%s'.\n", template_path, type);
    }

    return 0;
}
