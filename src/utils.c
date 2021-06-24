#include "utils.h"

int print_usage(const char *prog, const struct option long_options[], const char **desc, const char *descript)
{
    printf(
        "Usage: \n %s <opt> <arg>\n"
        "%s\n",
        prog, descript);
    int i = 0;
    while (1) {
        if (long_options[i].name != NULL)
            printf("\t-%c, --%-15s    %s\n", long_options[i].val,
                   long_options[i].name, desc[i]);
        else
            break;
        i++;
    }
    return 0;
}

void print_version(int major, int minor, int patch)
{
    fprintf(stdout, "VERSION: %d.%d.%d\n", major, minor, patch);
}

int module_call(int (*mod_cb)(int, char **), int argc, char **argv)
{
    return mod_cb(argc, argv);
}

