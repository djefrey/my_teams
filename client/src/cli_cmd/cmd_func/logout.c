/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** logout
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static void handle_logout_transaction(client_t *client, void *data)
{
    UNUSED(client);
    UNUSED(data);
    puts("[INFO] Logged out !");
}

bool logout_cli_cmd(client_t *client, int ac, char **av, list_t *transactions)
{
    logout_cmd_arg_t cmd_arg;

    UNUSED(ac);
    UNUSED(av);
    cmd_arg.transaction = transaction_create(NULL,
    handle_logout_transaction, NULL, transactions)->id;
    client_send_cmd(client->conn, LOGOUT_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}