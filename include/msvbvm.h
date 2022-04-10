#ifndef _MSVBVM_H
#define _MSVBVM_H

#include <windows.h>

struct vb_header {
    DWORD magic;
    short runtime_build;
    CHAR language[14];
    CHAR second_languaje[14];
    short runtime_version;
    DWORD language_id;
    DWORD second_language_id;
    void (*main_function)();
    void* project_data;
    DWORD vb_control_flags_1;
    DWORD vb_control_flags_2;
    DWORD threading_mode;
    DWORD thread_count;
    short form_count;
    short external_count;
    DWORD thunk_count;
    void* gui_table;
    void* external_table;
    void* com_information;
    DWORD project_description_offset;
    DWORD project_exe_name;
    DWORD project_help_file;
    DWORD project_name;
};

#endif
