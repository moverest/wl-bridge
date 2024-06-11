#ifndef __STATE_H_INCLUDED__
#define __STATE_H_INCLUDED__

struct state {
    struct wl_display    *wl_display;
    struct wl_registry   *wl_registry;
    struct wl_compositor *wl_compositor;
};

#endif
