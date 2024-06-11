project(
  'wl-bridge',
  'c',
  meson_version: '>=0.60.0',
  default_options: ['c_std=c11'],
  license: 'GPL-3.0',
  version: '0.1',
)

add_project_arguments('-D_GNU_SOURCE=200809L', language: 'c')
cc = meson.get_compiler('c')

jansson = dependency('jansson')
wayland_client = dependency('wayland-client')
wayland_protos = dependency('wayland-protocols')
xkbcommon = dependency('xkbcommon')


executable(
  'wl-bridge',
  [
    'src/main.c',
    'src/message.c',
  ],
  dependencies: [
    wayland_client,
    xkbcommon,
    wayland_client,
    jansson,
  ],
  install: true,
)
