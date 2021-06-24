#ifndef CT_UTILS
#define CT_UTILS

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#define LEN_MODULE_NAME 255
#define LEN_MODULE_DESC 1024

int         print_usage(const char *prog, const struct option long_options[], const char **desc, const char *descript);
void        print_version(int major, int minor, int patch);

typedef int module_cb(int argc, char **argv);

int         module_call(int (*mod_cb)(int, char **), int argc, char **argv);

typedef struct module {
    char *name;
    char *desc;
    int (*mod_cb)(int, char **);
} module_t;
#endif
