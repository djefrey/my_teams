/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** responses
*/

#include "teams.h"
#include "responses.h"

void client_send_success(client_t *client, uint64_t transaction)
{
    response_t response = COMMAND_OK;

    client_send_value(client, response, sizeof(response_t));
    client_send_value(client, transaction, sizeof(uint64_t));
}

void client_send_error(client_t *client, uint64_t transaction, error_t error)
{
    response_t response = ERROR_OCCURED;

    client_send_value(client, response, sizeof(response_t));
    client_send_value(client, transaction, sizeof(uint64_t));
    client_send_value(client, error, sizeof(error_t));
}

void client_send_unknown_cmd(client_t *client)
{
    response_t response = UNKNOWN_COMMAND;

    client_send_value(client, response, sizeof(response_t));
}
