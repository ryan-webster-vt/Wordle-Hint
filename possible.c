#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int repeatedLetters(char* str, char letter) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == letter) {
            count++;
        }
    }
    return count;
}

void hints(char* hidden, char* guess, char* hint) { 
    int lettersChecked[26] = { 0 };
    int length = strlen(guess);

    for (int i = 0; i < length; i++) {
        hint[i] = 'r';
        if (hidden[i] == guess[i]) {
            hint[i] = 'g';
            lettersChecked[guess[i] - 'a']++;
        }
    }

    for (int i = 0; i < length; i++) {   
        if (hint[i] == 'g') {
            continue;
        }
        int hiddenRepeatedLetters = repeatedLetters(hidden, guess[i]);
        for (int r = 0; r < length; r++) {       
            if (i != r && guess[i] == hidden[r] && 
            lettersChecked[guess[i] - 'a'] < hiddenRepeatedLetters) {
                hint[i] = 'y';
                lettersChecked[guess[i] - 'a']++;
                break;
            }
        }
    }
    hint[length] = '\0';
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("command usage: %s <guess word> <hint>\n", argv[0]);
        return 1;
    }

    char* guess = argv[1];
    char* inputHint = argv[2];
    char next[6];

    bool found = false;
    while (scanf("%5s", next) == 1) {
        char hint[strlen(argv[1]) + 1];
        hints(next, guess, hint);
        if (strcmp(inputHint, hint) == 0) {
            printf("%s ", next);
            found = true;
        }
    }
    if (!found) {
        printf("No possible hidden words found.");
    }
    printf("\n");
    return 0;
}
