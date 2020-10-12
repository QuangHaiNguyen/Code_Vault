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

void PrintDocuIndo(struct document* my_docu);
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
#endif
    
    // we have only one document
    // at the begining the document has only 1 paragraph
    my_docu = (struct document*)malloc(sizeof(struct document));
    my_docu->paragraph_count = 1;

    //we have 1 paragraph in the document
    //At the beginning paragraph has 1 sentence
    my_docu->data = (struct paragraph*)malloc(sizeof(struct paragraph));
    my_docu->data->sentence_count = 1;

    //we have 1 sentence in each paragraph
    //At the beginning, the sentence has only 1 word
    my_docu->data->data = (struct sentence*)malloc(sizeof(struct sentence));
    my_docu->data->data->word_count = 1;

    //my_docu->data->data->data = (struct word*)malloc(1 * sizeof(struct word));

    //reinit to make sure everything is right

    int para_index = 0;
    int sentence_index = 0;
    int word_index = 0;

    my_docu->data[para_index].data[sentence_index].data = my_words;

    printf("%s\n", my_docu->data[0].data[0].data[0]);
    printf("%s\n", my_docu->data[0].data[0].data[1]);
    printf("%s\n", my_docu->data[0].data[0].data[2]);
    printf("%s\n", my_docu->data[0].data[0].data[3]);

    while (test_string[char_count] != '\0')
    {
        if (test_string[char_count] == '.')
        {
            if (test_string[char_count + 1] == ' ') 
            {
                //new sentence
                ++my_docu->data[para_index].sentence_count;
                realloc(my_docu->data[para_index].data, my_docu->data[para_index].sentence_count * sizeof(struct sentence));

                ++sentence_index;
                my_docu->data[para_index].data[sentence_index].word_count = 1;


                //new word
                ++word_index;
                my_docu->data[para_index].data[sentence_index].data = my_words + word_index;

                ++char_count;
            }
            if (test_string[char_count + 1] == '\n')
            {
                //new paragraph
                ++my_docu->paragraph_count;
                realloc(my_docu->data, my_docu->paragraph_count * sizeof(struct paragraph));

                ++para_index;
                my_docu->data[para_index].sentence_count = 1;


                //new sentence
                //reset index since there is new paragraph
                sentence_index = 0;
                my_docu->data[para_index].data = (struct sentence*)malloc(sizeof(struct sentence));
                my_docu->data[para_index].data[sentence_index].word_count = 1;

                //new word
                ++word_index;
                my_docu->data[para_index].data[sentence_index].data = my_words + word_index;
            }
            if (test_string[char_count + 1] == '\0') 
            {
                //do nothing
            }
        }
         
        if (test_string[char_count] == ' ')
        {
            ++word_index;
            ++my_docu->data[para_index].data[sentence_index].word_count;
        }

        ++char_count;
    }


    PrintDocuIndo(my_docu);
    /*
    for (int i = 0; i < my_docu->paragraph_count; i++)
    {
        for (int j = 0; j < my_docu->data[i].sentence_count; j++)
        {
            for (int m = 0; m < my_docu->data[i].data[j].word_count; m++)
            {
                printf("%s ", my_docu->data[i].data[j].data);
            }
            printf(". ");
        }
        printf("\n");
    }
    */
    return 0;
}

void PrintDocuIndo(struct document * my_docu)
{
    printf("paragraph_count: %d\n", my_docu->paragraph_count);
    for (int i = 0; i < my_docu->paragraph_count; i++)
    {
        printf("\tsentence_count: %d\n", my_docu->data[i].sentence_count);
        for (int j = 0; j < my_docu->data[i].sentence_count; j++)
        {
            printf("\t\tword_count: %d\n", my_docu->data[i].data[j].word_count);
        }
    }
    printf("\n");
}