project (
  'Snake', 
  'cpp',
  version : '0.1.0',
  default_options : ['cpp_std=c++23']
  )

sfml_system_deps   = dependency('sfml-system')
sfml_window_deps   = dependency('sfml-window')
sfml_graphics_deps = dependency('sfml-graphics')

game_files = [
  'src/main.cpp',
  'src/gengine/engine.cpp',
  'src/gameobject/gameobject.cpp'
  ]

executable(
  'game',
  game_files,
  install : true,
  dependencies : [
    sfml_system_deps,
    sfml_window_deps,
    sfml_graphics_deps
    ]
  )
