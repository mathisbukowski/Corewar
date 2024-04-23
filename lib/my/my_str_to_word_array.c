/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>

static int is_delimiter(char c, const char *delimiters)
{
    for (int i = 0; delimiters[i] != '\0'; i++) {
        if (c == delimiters[i] || c == '\t')
            return 1;
    }
    return 0;
}

int is_start_of_word(int in_word, char current_char)
{
    if (!in_word && !is_delimiter(current_char, " ")) {
        return 1;
    }
    return 0;
}

int process_marker(int marker, int *count, int *in_word)
{
    if (marker == 1) {
        (*count)++;
        *in_word = 1;
    } else if (marker == -1) {
        *in_word = 0;
    }
}

int is_start_of_word_or_delimiter(int in_word, char current_char,
    const char *delimiters)
{
    if (is_delimiter(current_char, delimiters)) {
        return -1;
    } else if (!in_word) {
        return 1;
    }
    return 0;
}

int count_words(const char *str, const char *delimiters)
{
    int count = 0;
    int in_word = 0;
    int marker;

    for (int i = 0; str[i] != '\0'; i++) {
        marker = is_start_of_word_or_delimiter(in_word, str[i], delimiters);
        process_marker(marker, &count, &in_word);
    }
    return count;
}

char **my_str_to_word_array(const char *str, const char *delimiters)
{
    int size = count_words(str, delimiters);
    char **words = malloc(sizeof(char *) * (size + 1));
    int index = 0;
    int word_length;

    for (int i = 0; i < size; i++) {
        while (str[index] != '\0' && is_delimiter(str[index], delimiters))
            index++;
        word_length = 0;
        while (str[index + word_length] != '\0' &&
            !is_delimiter(str[index + word_length], delimiters))
            word_length++;
        words[i] = malloc(sizeof(char) * (word_length + 1));
        for (int j = 0; j < word_length; j++)
            words[i][j] = str[index + j];
        words[i][word_length] = '\0';
        index += word_length;
    }
    words[size] = NULL;
    return words;
}
