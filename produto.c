#include "produto.h"

int verifyProduct(char* id) {
    char c1, c2;
    int n;
    sscanf(id, "%c%c%d%*s", &c1, &c2, &n);
    return strlen(id) == 6 && c1 <= 'Z' && c1 >='A' && c2 <= 'Z' && c2 >='A' && n >= 1000 && n <= 9999;
}

char* mkProduct(char* id) {
    char* product = malloc(strlen(id) + 1);
    strcpy(product, strtok(id, "\n\r"));
    return product;
}
