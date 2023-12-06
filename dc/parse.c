#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"

int is_num_only(char* string) {
    while (*string != '\0') {
        if (isdigit(*string) == 0) {
            return 0;
        }
        string++;
    }
    return 1;
}

int main() {
    return 0;
}