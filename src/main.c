#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "utils.h"

#include "add.h"

int main_help(int argc, char **argv);

int main_usage();

module_t reg_modules[] = {
    {"add", "add", add},
    {"help", "help", main_help},
    {NULL, NULL, NULL},
};



int main(int argc, char **argv)
{
    if (argc == 1) {
        fprintf(stderr, "error: no args recived!\n");
        main_usage(argv[0]);
        return -1;
    }

    for (int i=0; reg_modules[i].name != NULL; i ++)
    {
        if (strncmp(argv[1], reg_modules[i].name, LEN_MODULE_NAME) == 0)
        {
            return module_call(reg_modules[i].mod_cb, argc-1, argv+1);
        }
    }


    {
        printf("HOME: %s\n", getenv("HOME"));
        printf("PATCH_PATH: %s\n", getenv("PATCH_PATH"));
    }

    return 0;
}

int main_usage(char *prog)
{
    printf("Usage:\n"
            "%6s    [command] <options>\n\n", prog);
    for (int i=0; reg_modules[i].name != NULL;i++)
    {
        printf("\t  %-10s\t%s\n", reg_modules[i].name, reg_modules[i].desc);
    }

    return 0;
}

int main_help(int argc, char **argv)
{
    if (argc==1)
    {
        return main_usage("prog");
    }
    for (int i=0; reg_modules[i].name != NULL; i ++)
    {
        if (strncmp(argv[1], reg_modules[i].name, LEN_MODULE_NAME) == 0)
        {
            if (strncmp(argv[1], "help", LEN_MODULE_NAME) == 0)
            {
                printf("kidding??????\n");
                return -1;
            }
            char *args[] = {argv[1], "-h"};
            return module_call(reg_modules[i].mod_cb, 2, args);
        }
    }
    printf("help: no such command: %s\n", argv[1]);
    return -1;
}

