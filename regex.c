#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main(void) {
    regex_t regex;
    int reti;
    char msg[100];
    reti = regcomp(&regex, "GET /\\S\\S* HTTP/1.0", 0);
    if (reti == 0) {
        printf("Regex Succesfully compiled!\n");
    }
    else {
        fprintf(stderr, "Error while compiling regex!\n");
        return EXIT_FAILURE;
    }
    
    
    char buffer[1024];
    int bytes_read;
    while (fgets(buffer, sizeof(buffer), stdin)) {
        reti = regexec(&regex, buffer, 0, NULL, 0);
        if (reti == 0) {
            puts("Matched!");
        }
        else if (reti == REG_NOMATCH) {
            puts ("No Match!");
        }
        else {
            regerror(reti, &regex, msg, sizeof(msg));
            fprintf(stderr, "Regex match failed : %s \n", msg);
        }
    }
    regfree(&regex);
    return EXIT_SUCCESS;
}
