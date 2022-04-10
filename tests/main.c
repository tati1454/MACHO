#include <stdarg.h>
#include <stdio.h>

#define assert(condition, message, ...) \
    _assert(__LINE__, __FILE__, condition, message, ##__VA_ARGS__)

static inline void _assert(int line_number,
                           char* file_name,
                           int condition,
                           char* message,
                           ...) {
    char formatted_message[256];
    va_list args;

    va_start(args, message);

    if (!condition) {
        vsnprintf(formatted_message, 256, message, args);
        printf("FAILED at line %d in %s : %s\n", line_number, file_name,
               formatted_message);
        return;
    }

    printf("PASS at line %d in %s\n", line_number, file_name);
}

int main() {
    assert(1 == 0, "This is an example test.\n");
}
