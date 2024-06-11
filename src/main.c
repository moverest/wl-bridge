#include "message.h"
#include "state.h"

#include <jansson.h>
#include <wayland-client-protocol.h>
#include <wayland-util.h>

int main() {
    struct state state = {
        .wl_display    = NULL,
        .wl_registry   = NULL,
        .wl_compositor = NULL,
    };

    state.wl_display = wl_display_connect(NULL);
    if (state.wl_display == NULL) {
        struct msg_error msg;
        msg_error_init(&msg, 0, "Unable to connect to Wayland display.");
        msg_send(&msg);
    }

    struct msg_error msg;
    msg_error_init(&msg, 1, "No error!");
    msg_send(&msg);

    wl_display_disconnect(state.wl_display);

    return 0;
}
