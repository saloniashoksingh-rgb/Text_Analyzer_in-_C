


#include <stdio.h>

// Function 1: Count total words
int countWords(char text[])
{
    int inWord = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] != ' ' &&
            text[i] != '\n' &&
            text[i] != '\t')
        {
            if (inWord == 0)
            {
                words++;
                inWord = 1;
            }
        }
        else
        {
            inWord = 0;
        }
    }

    return words;
}

// Function 2: Count vowels
int countVowels(char text[])
{
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];

        if (ch == 'a' || ch == 'e' ||
            ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' ||
            ch == 'I' || ch == 'O' || ch == 'U')
        {
            count++;
        }
    }

    return count;
}

// Function 3: Count consonants
int countConsonants(char text[])
{
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];

        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z'))
        {
            if (!(ch == 'a' || ch == 'e' ||
                  ch == 'i' || ch == 'o' ||
                  ch == 'u' || ch == 'A' ||
                  ch == 'E' || ch == 'I' ||
                  ch == 'O' || ch == 'U'))
            {
                count++;
            }
        }
    }

    return count;
}

// Function 4: Find and print all longest words
void findLongestWord(char text[], char longest[])
{
    int length = 0;
    int maxLength = 0;

    // First pass: Find the maximum word length
    for (int i = 0; ; i++)
    {
        char ch = text[i];

        if (ch != ' ' && ch != '\n' &&
            ch != '\t' && ch != '\0')
        {
            length++;
        }
        else
        {
            if (length > maxLength)
            {
                maxLength = length;
            }

            length = 0;
        }

        if (ch == '\0')
        {
            break;
        }
    }

    if (maxLength == 0)
    {
        longest[0] = '\0';
        printf("Longest Word(s): None\n");
        return;
    }

    // Second pass: Print all longest words
    printf("Longest Word(s): ");

    length = 0;
    int printed = 0;

    for (int i = 0; ; i++)
    {
        char ch = text[i];

        if (ch != ' ' && ch != '\n' &&
            ch != '\t' && ch != '\0')
        {
            length++;
        }
        else
        {
            if (length == maxLength)
            {
                int start = i - length;

                // Print comma only before the next word
                if (printed > 0)
                {
                    printf(", ");
                }

                for (int j = 0; j < length; j++)
                {
                    printf("%c", text[start + j]);
                }

                printed++;
            }

            length = 0;
        }

        if (ch == '\0')
        {
            break;
        }
    }

    printf("\n");

    // Store the first longest word in the array
    longest[0] = '\0';
    length = 0;

    for (int i = 0; ; i++)
    {
        char ch = text[i];

        if (ch != ' ' && ch != '\n' &&
            ch != '\t' && ch != '\0')
        {
            length++;
        }
        else
        {
            if (length == maxLength)
            {
                int start = i - length;

                for (int j = 0; j < length; j++)
                {
                    longest[j] = text[start + j];
                }

                longest[length] = '\0';
                break;
            }

            length = 0;
        }

        if (ch == '\0')
        {
            break;
        }
    }
}

// Function 5: Display character frequency
void showFrequency(char text[])
{
    int freq[256] = {0};

    // Count the frequency of each character
    for (int i = 0; text[i] != '\0'; i++)
    {
        unsigned char ch = text[i];

        if (ch != ' ' && ch != '\n' && ch != '\t')
        {
            freq[ch]++;
        }
    }

    printf("\nCharacter Frequency:\n");

    // Display each character only once
    for (int i = 0; text[i] != '\0'; i++)
    {
        unsigned char ch = text[i];

        if (ch != ' ' && ch != '\n' &&
            ch != '\t' && freq[ch] > 0)
        {
            printf("%c : %d\n", ch, freq[ch]);

            // Mark the character as already printed
            freq[ch] = 0;
        }
    }
}

// Main function
int main()
{
    char text[1000];
    char longest[1000];

    printf("===== TEXT ANALYZER =====\n");
    printf("Enter your text:\n");

    fgets(text, 1000, stdin);

    printf("\n===== ANALYSIS RESULT =====\n");

    printf("Total Words: %d\n", countWords(text));
    printf("Total Vowels: %d\n", countVowels(text));
    printf("Total Consonants: %d\n", countConsonants(text));

    findLongestWord(text, longest);

    showFrequency(text);

    return 0;
}