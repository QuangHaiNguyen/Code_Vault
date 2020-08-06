#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct word {
    char* data;
};
struct sentence {
    struct word* data;
    int word_count;//the number of words in a sentence
};
struct paragraph {
    struct sentence* data;
    int sentence_count;//the number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//the number of paragraphs in a document
};

char test_string[] = "Learning C is fun.\nLearning pointers is more fun. It is good to have pointers.";
char* work_string;
int main()
{
    struct word* my_words;
    struct document* my_docu;


    int word_count = 0;
    int paragraph_count = 0;
    int sentence_count = 0;
    int char_count = 0;

#if 1
    work_string = (char*)malloc(1000 * sizeof(char));
    strcpy(work_string, test_string);
    my_words = (struct word*)malloc(sizeof(struct word) * 500);

    my_words[word_count].data = strtok(work_string, " ");
    while (my_words[word_count].data != NULL)
    {
        word_count++;
        my_words[word_count].data = strtok(NULL, " .\n");
    }
    for (int i = 0; i < word_count; i++) {
        printf("%d\t%s\n", &my_words[i].data, my_words[i].data);
    }


#endif

    
    return 0;
}