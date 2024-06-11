#ifndef __MESSAGE_H_INCLUDED__
#define __MESSAGE_H_INCLUDED__

#include <jansson.h>

enum msg_type {
    MSG_ERROR = 0,
};

struct msg {
    enum msg_type type;
};

struct msg_error {
    struct msg msg;
    int        code;
    char      *string;
};

struct msg_interface {
    char *type_str;
    json_t *(*build_json)(const void *msg);
};

extern struct msg_interface msg_interfaces[];

void msg_send(const void *msg);

void msg_error_init(struct msg_error *msg, int code, char *human_readable);

#endif
