#include <stdio.h>
#include <windows.h>

#include "msvbvm.h"

#define stub(fmt, ...) printf("STUB:%s: " fmt, __FUNCTION__, ##__VA_ARGS__)

DWORD ThunRTMain(struct vb_header* vb_header) {
    stub("%p\n", vb_header);
    vb_header->main_function();
    return 0;
}

void __vbaChkstk() {
    stub("\n");
    return;
}

DWORD __vbaExceptHandler(EXCEPTION_RECORD* exception,
                         EXCEPTION_REGISTRATION_RECORD* exception_record,
                         CONTEXT* context,
                         EXCEPTION_REGISTRATION_RECORD** exception_records) {
    printf("Unhandled exception %#x in macho at %#x\n", exception->ExceptionCode, exception->ExceptionAddress);
    return 1;
}
