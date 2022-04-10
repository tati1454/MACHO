#include <stdio.h>
#include <windows.h>

#include "msvbvm.h"

DWORD ThunRTMain(struct vb_header* vb_header) {
    vb_header->main_function();
    return 0;
}
