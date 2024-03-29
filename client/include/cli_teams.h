/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** teams
*/

#pragma once

#include <uuid/uuid.h>
#include "conn.h"
#include "transaction.h"
#include "chained_list.h"
#include "cmd_ids.h"

#define UNUSED(var) ((void) var)

typedef enum use_state_e {
    NO_USE_STATE,
    TEAM_USE_STATE,
    CHANNEL_USE_STATE,
    THREAD_USE_STATE,
} use_state_t;

typedef struct use_s {
    use_state_t state;
    uuid_t team;
    uuid_t channel;
    uuid_t thread;
} use_t;

typedef struct client_s {
    conn_t *conn;
    use_t *use;
    bool connected;
    bool logout;
    uuid_t uuid;
    char *command;
    int len_command;
} client_t;

typedef struct message_s {
    uuid_t uuid;
    uuid_t user;
    char msg[MAX_BODY_LENGTH];
    time_t time;
} message_t;

bool handle_server_msg(client_t *client, list_t *transations);
bool handle_user_cmd(client_t *client, list_t *transactions);

void client_send_cmd_id(conn_t *conn, command_id_t cmd);
void client_send_data(conn_t *conn, void *data, size_t size);
void client_send_cmd(conn_t *conn, command_id_t cmd, void *data, size_t size);
void handle_create_team_transaction(client_t *client, void *data);
void handle_create_channel_transaction(client_t *client, void *data);
void handle_create_thread_transaction(client_t *client, void *data);
void handle_create_comment_transaction(client_t *client, void *data);
void handle_info_user_transaction(client_t *client, void *data);
void handle_info_team_transaction(client_t *client, void *data);
void handle_info_channel_transaction(client_t *client, void *data);
void handle_info_thread_transaction(client_t *client, void *data);
void handle_list_team_transaction(client_t *client, void *data);
void handle_list_channel_transaction(client_t *client, void *data);
void handle_list_thread_transaction(client_t *client, void *data);
void handle_list_comment_transaction(client_t *client, void *data);
