/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Day 09 Task 02
*/

#ifndef MY_H
    #define MY_H
    #include <stdlib.h>
void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char **my_str_to_word_array(const char *str, const char *delimiters);
char *my_strdup(char const *src);
void *my_realloc(void *ptr, size_t new_size, size_t old_size);
void *my_memcpy(void *dest, const void *src, size_t n);
int my_atoi(const char *str);
int my_strchr(char *str, char c);
char *my_itoa(int num);
#endif
