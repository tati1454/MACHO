#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <winnt.h>

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

DWORD (*p__vbaExceptHandler)
(EXCEPTION_RECORD*,
 EXCEPTION_REGISTRATION_RECORD*,
 CONTEXT*,
 EXCEPTION_REGISTRATION_RECORD**);

static void test_exception_handler() {
    EXCEPTION_RECORD exception;
    memset(&exception, 0, sizeof(exception));
    exception.ExceptionAddress = &exception;
    exception.ExceptionCode = EXCEPTION_ACCESS_VIOLATION;

    EXCEPTION_REGISTRATION_RECORD record;
    EXCEPTION_REGISTRATION_RECORD* recordp[2] = {&record, NULL};
    memset(&record, 0, sizeof(record));
    CONTEXT context;
    memset(&context, 0, sizeof(context));

    DWORD r = p__vbaExceptHandler(&exception, &record, &context, recordp);
    assert(r == 1, "got %#p\n", r);
}

int main() {
    HANDLE module = LoadLibraryA("msvbvm60.dll");
    if (!module)
        printf("Error loading library.\n");
    p__vbaExceptHandler = (DWORD(*)(
        EXCEPTION_RECORD*, EXCEPTION_REGISTRATION_RECORD*, CONTEXT*,
        EXCEPTION_REGISTRATION_RECORD**))GetProcAddress(module,
                                                        "__vbaExceptHandler");
    if (!p__vbaExceptHandler)
        printf("Error GetProcAddress\n");

    test_exception_handler();
}
