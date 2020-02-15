
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN 52

#define MIN(A,B) (A < B ? A : B)
#define MAX(A,B) (A > B ? A : B)

typedef struct trie Trie;
struct trie {
    int frequency;
    Trie *children[26];
};

static Trie *newTrieNode() {
    Trie *new = malloc(sizeof(*new));
    memset(new, 0, sizeof(*new));
    return new;
}

static void freeTrie(Trie *top) {
    if (top == NULL) return;
    for (int i = 0; i < 26; i++) freeTrie(top->children[i]);
    free(top);
}

static Trie *insertTrie(Trie *t, char *word) {
    if (t == NULL) t = newTrieNode();

    if (word[1] == '\0') {
        t->frequency++;
    } else {
        t->children[word[1]-'A'] = insertTrie(t->children[word[1]-'A'], word+1);
    }
    return t;
}

static void reverseString(char *str) {
    char *end = str;
    while (*end != '\0') end++;
    end--;
    while (end > str) {
        char tmp = *str;
        *str = *end;
        *end = tmp;

        str++;
        end--;
    }
}

static int countPairs(Trie *top, int *pairs) {
    if (top == NULL) return 0;
    
    int unpaired = top->frequency;
    for (int i = 0; i < 26; i++) {
        unpaired += countPairs(top->children[i], pairs);
    }

    if (unpaired >= 2) {
        *pairs += 1;
        unpaired -= 2;
    }
    return unpaired;
}

int main(void) {
    int T;
    scanf("%d", &T); getchar();
    for (int t = 1; t <= T; t++) {
        Trie *words[26] = {0};
        int N;
        scanf("%d", &N); getchar();
        while (N > 0) {
            char buf[BUF_LEN] = {0};
            do {
                fgets(buf, BUF_LEN, stdin);
            } while (buf[0] == '\0');
            
            for (int i = 0; buf[i] != '\0'; i++) {
                if (buf[i] == '\n') {
                    buf[i] = '\0';
                    break;
                }
            }
            reverseString(buf);
            words[buf[0]-'A'] = insertTrie(words[buf[0]-'A'], buf);
            N--;
        }

        int pairs = 0;
        for (int i = 0; i < 26; i++) {
            countPairs(words[i], &pairs);
            freeTrie(words[i]);
        }

        printf("Case #%d: %d\n", t, 2*pairs);
    }
    return 0;
}
