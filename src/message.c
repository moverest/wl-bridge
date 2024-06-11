#include "message.h"

#include <jansson.h>
#include <stdio.h>

void msg_error_init(struct msg_error *msg, int code, char *human_readale) {
    msg->msg.type = MSG_ERROR;
    msg->code     = code;
    msg->string   = human_readale;
}

json_t *msg_error_build_json(const void *msg) {
    struct msg_error *msg_error = (struct msg_error *)msg;

    json_t *json = json_object();
    json_object_set(json, "code", json_integer(msg_error->code));
    json_object_set(json, "human_readable", json_string(msg_error->string));

    return json;
}

struct msg_interface msg_interfaces[] = {
    [MSG_ERROR] = {.type_str = "error", .build_json = msg_error_build_json},
};

void msg_send(const void *msg) {
    const struct msg     *msg_      = msg;
    struct msg_interface *interface = &msg_interfaces[msg_->type];

    json_t *json = interface->build_json(msg_);
    json_object_set(json, "type", json_string(interface->type_str));

    json_dumpf(json, stdout, 0);
    fputc('\n', stdout);
    fflush(stdout);

    json_decref(json);
}
