#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30


char upCase(char c) { //return the assci val
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

void Gematria(char *word, char *text) {
    printf("Gematria Sequences:");
    int lenWord = strlen(word);
    int geomWord = 0;
    for (int i = 0; i < lenWord; i++) { //calc the geom pf the word
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
        } else { // geomWord > counter.. reset
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

int AtbashHelper(char word[], char text[], int lenT, int lenW) {
    int seqPtr = 0; //"pointer" on the seq
    int counter = 0; // how many words we saw
    int i = 0; //
    char sequence[lenT];
    memset(sequence, 0, lenT);

    while (counter != lenW) {
        if (word[i] == text[i] || word[i] == trans(word[i])) {
            sequence[seqPtr] = text[i];
            i += 1; // i are pointer on the text
            seqPtr += 1;
            counter += 1; //how many words we saw
            continue;
        } else if (text[i] == ' ') { //add the blank space to the sequence
            sequence[seqPtr] = text[i];
            i += 1; // i are pointer on the text
            seqPtr += 1;
            continue;
        } else if (word[i] != text[i] || word[i] != trans(word[i])) {
            return 0;
        }
    }
    sequence[seqPtr] = '~';
    puts(sequence); //print the seq
    return 0;
}

void Atbash(char *word, char *text) {
    printf("Atbash Sequences:");
    int lenW = strlen(word), lenT = strlen(text);
    for (int i = 0; i <= lenT - lenW; i++) {
        AtbashHelper(word, text, lenT, lenW);
    }
}

//check the appearance  of the chars
int checkAn(char *currString, char *wordPtr) {
    int appearance[127];
    memset(appearance, 0, sizeof(appearance));
    int loc;
    for (int i = 0; currString[i] != '\0'; i++) {
        if (currString[i] != ' ') {
            loc = (int)*(currString + i);
            appearance[loc] += 1;
        }
        if (wordPtr[i] != ' ' && strlen(wordPtr) > i) {
            loc = (int) *(wordPtr + i);
            appearance[loc] -= 1;
        }
    }
    for (int i = 0; i < 127; i++) {
        if (appearance[i] != 0) {
            return 0;
        }
    }
    return 1;
}

void Anagram(char word[], char text[]) {
    char *wordPtr; //pointer to the word
    char *textEPtr; //pointer to the end of the text
    char *textSPtr = text; //pointer to the start of the text
    char ans[TXT] = "";

    while (*textSPtr) {
        char currString[TXT] = "";
        int count = 0;
        textEPtr = textSPtr; //init end pointer text
        wordPtr = word;  // init pointer to the word
        while (count < strlen(wordPtr)) { //while we didn't get to substring that equals to the word
            if (*textEPtr == ' ' && !strlen(currString)) {
                break;
            } else if (*textEPtr != ' ') {
                count++;
            }
            strncat(currString, textEPtr, 1); //appended only one char
            textEPtr++;

            if (strlen(wordPtr) == count) {
                if (checkAn(currString, wordPtr)) {
                    strcat(ans, currString);
                    ans[strlen(ans)] = '~';
                    count = 0;
                }
            }

        }
        textSPtr++;
    }
    int size = strlen(ans);
    ans[size - 1] = '\0';
    printf("Anagram Sequences: %s", ans);
}












