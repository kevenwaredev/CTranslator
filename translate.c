#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 50

typedef struct {
    char english[MAX_LEN];
    char portuguese[MAX_LEN];
} Dictionary;

void loadDictionary(Dictionary dict[], int *size) {
    strcpy(dict[0].english, "hello");
    strcpy(dict[0].portuguese, "olá");

    strcpy(dict[1].english, "world");
    strcpy(dict[1].portuguese, "mundo");

    strcpy(dict[2].english, "good morning");
    strcpy(dict[2].portuguese, "bom dia");

    strcpy(dict[3].english, "good night");
    strcpy(dict[3].portuguese, "boa noite");

    strcpy(dict[4].english, "how are you?");
    strcpy(dict[4].portuguese, "como você está?");

    *size = 5; 
}

char* translate(Dictionary dict[], int size, char *word) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(dict[i].english, word) == 0) {
            return dict[i].portuguese;
        }
    }
    return NULL;
}

int main() {
    Dictionary dict[MAX_WORDS];
    int dictSize;
    char word[MAX_LEN];
    loadDictionary(dict, &dictSize);
    printf("Digite uma palavra ou frase em inglês: ");
    fgets(word, MAX_LEN, stdin);
    word[strcspn(word, "\n")] = 0;
    char *translation = translate(dict, dictSize, word);
    if (translation) {
        printf("Tradução: %s\n", translation);
    } else {
        printf("Tradução não encontrada.\n");
    }
    return 0;
}
