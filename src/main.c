#include <stdio.h>
#include <windows.h>

#include "msvbvm.h"

#define stub(fmt, ...) printf("STUB:%s: " fmt, __FUNCTION__, ##__VA_ARGS__)

DWORD ThunRTMain(struct vb_header* vb_header) {
    stub("%p\n", vb_header);
    vb_header->main_function();
    return 0;
}
