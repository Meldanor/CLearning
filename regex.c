#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

int extractFileFromGET(char *fileBuffer, char *request) {
    // Start of the file part
    char *start = request + 4;

    // Search for the end of the file part
    char *end = NULL;
    end = strchr(start, ' ');
    // No SPACE found (impossible)
    if (end == NULL)
        return EXIT_FAILURE;
    // Copy file part from request to fileBuffer
    int size = (end - start) - 1;
    for(; size >= 0; --size) {
        fileBuffer[size] = start[size];
    }

    return EXIT_SUCCESS;
}

int main(void) {
    char *request = "GET /common/index.html HTTP/1.0\n";
    char fileBuffer[256];
    int res;
    res = extractFileFromGET(fileBuffer, request);
    if (res == EXIT_FAILURE)
        return EXIT_FAILURE;
    
    puts("Result:");
    puts(fileBuffer);
        
}

int main2(void) {
    regex_t regex;
    int reti;
    char msg[100];
    reti = regcomp(&regex, "GET /\\S\\S* HTTP/1.0[\r\n]", 0);
    if (reti == 0) {
        printf("Regex Succesfully compiled!\n");
    }
    else {
        fprintf(stderr, "Error while compiling regex!\n");
        return EXIT_FAILURE;
    }
    
    // GET /index.html HTTP/1.0

    int bytes_read;
    char *buffer = "GET /index.html HTTP/1.0\n";
    puts("With ending...");
    printf("%s", buffer);
    int len = strlen(buffer);
    reti = regexec(&regex, buffer, 0, NULL, 0);
    if (reti == 0) {
        puts("Matched!");
    }
    else if (reti == REG_NOMATCH) {
        puts ("No Match!");
    }
    
    
    buffer = "GET /index.html HTTP/1.0";
    puts("Without ending...");
    reti = regexec(&regex, buffer, 0, NULL, 0);
    printf("%s", buffer);
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
    
    regfree(&regex);
    return EXIT_SUCCESS;
}
