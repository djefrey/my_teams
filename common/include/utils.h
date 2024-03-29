/*
** EPITECH PROJECT, 2022
** teams
** File description:
** utils
*/

#pragma once

#include <stdbool.h>
#include <uuid/uuid.h>
#include "chained_list.h"

int is_not_number(char *s);
int is_sep(char c, char *sep);
char *rm_sep_aft(char *str, char *sep);
char *rm_sep_bef(char *str, char *sep);
int get_len_array(void *arr, size_t size);
char **teams_cl_to_arr(char *str);
bool does_list_contains_uuid(uuid_t uuid, uuid_list_t list);
