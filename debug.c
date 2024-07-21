#include "debug.h"
#include <getopt.h>
#include <stdio.h>

bool debug_mode = false;

void parse_arguments(int argc, char *argv[]) {
    int option;
    const char *short_opts = "d";
    const struct option long_opts[] = {
        {"debug", no_argument, NULL, 'd'},
        {NULL, 0, NULL, 0}
    };

    while ((option = getopt_long(argc, argv, short_opts, long_opts, NULL)) != -1) {
        switch (option) {
            case 'd':
                debug_mode = true;
                break;
            default:
                break;
        }
    }
}
