#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30


char upCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

void Gematria(char *word, char *text) {
    printf("Gematria Sequences:");
    int lenWord = strlen(word);
    int geomWord = 0;
    for (int i = 0; i < lenWord; i++) {
        int tst = upCase(word[i]) - 'A' + 1;
        if (tst < 0 || tst > 27) { //not valid..
            continue;
        }
        geomWord += tst;
    }
    int counter = 0;
    int lenText = strlen(text);
    char sequence[lenText];
    int seqPtr = 0; //"pointer" on the seq
    memset(sequence, 0, lenText);
    for (int j = 0; j < lenText; j++) {
        int tst = upCase(text[j]) - 'A' + 1;
        if (tst < 0 || tst > 27) { //not valid or blankSpace
            sequence[seqPtr] = *(text + j); //add the char to the seq
            seqPtr += 1;
            continue;
        }
        counter += tst;
        if (counter == geomWord) { //if there is something in the string
            sequence[seqPtr] = *(text + j);
            sequence[seqPtr + 1] = '~';
            puts(sequence); //print the seq
            memset(sequence, 0, lenText); //reset
            seqPtr = 0;
            continue;
        } else if (geomWord < counter) {
            sequence[seqPtr] = *(text + j);
            seqPtr += 1;
        } else {
            memset(sequence, 0, lenText); //reset
            seqPtr = 0;
            continue;
        }

    }

}

//transfer to atbash
char trans(char c) {
    if (c >= 'a' && c <= 'z') { //little letter
        int a = c - 'a';
        int b = 'z' - a;
        c = b;
        return c;
    } else {
        int a = c - 'A';
        int b = 'Z' - a;
        c = b;
        return c;
    }
}

int AtbashHelper(char word[], char text[], int n) {
    int seqPtr = 0; //"pointer" on the seq
    char sequence[n + 1];
    memset(sequence, 0, n);
    for (int i = 0; i < n; i++) {
        if (word[i] == text[i] || word[i] == trans(word[i])) {
            sequence[seqPtr] = text[i];
            seqPtr += 1;
            continue;
        } else if (text[i] == ' ') {
            continue; //ignore blank space
        } else if (seqPtr == n) {
            sequence[n + 1] = '~';
            puts(sequence); //print the seq
            return 0;
        }
    }
    return 0;

}

void Atbash(char *word, char *text) {
    printf("Atbash Sequences:");
    int len1 = strlen(word), len2 = strlen(text);
    char sequence[len2 - len1 + 1];
    int seqPtr = 0; //"pointer" on the seq

    for (int i = 0; i <= len2 - len1; i++) {
        AtbashHelper(word, text, len1);
    }

}

void Anagram(char *word, char *text) {
    printf("Anagram Sequences:");

}







