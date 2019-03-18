#include "produtos.h"
#include <glib.h>

/**
\brief Array que contem os produtos.
*/
char* produtos[200000];

/**
\brief AVL que contem os produtos.
*/
GTree* avlP[26];

/**
\brief Número de produtos no array produtos.
*/
int productNumber;

int cmp1(const void* a, const void* b, void* c) {
    (void) c;
    return strcmp((char*) a, (char*) b);
}

int* searchProduct(char* id) {
    return (int*) g_tree_lookup(avlP[id[0] - 'A'], id);
}

int getProductNumber() {
    return productNumber;
}

gboolean productLetter(gpointer key, gpointer value, gpointer data) {
    char* ree = (char*) key;
    int* r = ((int**) data)[0];
    char* id = (char*) ((int**) data)[1];
    (void) value;
    if(ree[0] > *id) return TRUE;
    if(ree[0] == *id) (*r)++;
    return FALSE;
}

int getProductLetter(char id) {
    return g_tree_nnodes(avlP[id - 'A']);
}

void initProducts(int filter, char * path) {
    int i;
    FILE* f = fopen(path, "r");
    char* buff = malloc(10);
    for(i = 'A'; i <= 'Z'; i++)
        avlP[i - 'A'] = g_tree_new_full(&cmp1, NULL, &free, NULL);
    for(i = 0; fgets(buff, 10, f);) {
        if(!filter || verifyProduct(strtok(buff, "\n\r"))) {
            char* product = mkProduct(buff);
            g_tree_insert(avlP[product[0] - 'A'], product, product);
            i++;
        }
    }
    productNumber = i;
    fclose(f);
}

void clearProducts() {
    int i;
    for(i = 0; i < 26; i++)
        g_tree_destroy(avlP[i]);
}
