#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>

void (*int_func)(int);

bool init_library()
{
    void *hdl = dlopen("./libShared.so", RTLD_LAZY);
    if( NULL == hdl )
        return false;
	int_func = (void (*)(int))dlsym(hdl, "int_func");
    if( NULL == int_func )
        return false;
    return true;
}

int main()
{
    if( init_library() )
        int_func(8);
    else
        printf("Library was not loaded\n");
    return 0;
}

