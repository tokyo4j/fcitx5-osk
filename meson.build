project('fcitx5-osk', 'cpp')

fcitx5_module = dependency('Fcitx5Module')

shared_module(
  'osk',
  'osk.cpp',
  dependencies: [
    fcitx5_module,
  ]
)

install_data(
  'osk.conf',
  install_dir : get_option('datadir') / 'fcitx5/addon'
)
