#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 1000

void toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++) str[i] = tolower(str[i]);
}

void cleanWord(char *word)
{
    int i = 0, j = 0;
    while (word[i])
    {
        if (isalnum(word[i])) word[j++] = tolower(word[i]);
        i++;
    }
    word[j] = '\0';
}

int main()
{
    char paragraph[MAX_LENGTH];
    char words[MAX_WORDS][50]; 
    int count[MAX_WORDS] = {0};
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, MAX_LENGTH, stdin);

    char *token = strtok(paragraph, " \n\t.,;:!?\"()[]{}");

    while (token != NULL)
    {
        char clean[50];
        strcpy(clean, token);
        cleanWord(clean);

        if (strlen(clean) == 0)
        {
            token = strtok(NULL, " \n\t.,;:!?\"()[]{}");
            continue;
        }

        int found = 0;

        for (int i = 0; i < wordCount; i++)
        {
            if (strcmp(words[i], clean) == 0)
            {
                count[i]++;
                found = 1;
                break;
            }
        }

        if (!found && wordCount < MAX_WORDS)
        {
            strcpy(words[wordCount], clean);
            count[wordCount] = 1;
            wordCount++;
        }

        token = strtok(NULL, " \n\t.,;:!?\"()[]{}");
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) printf("%s : %d\n", words[i], count[i]);

    return 0;
}
