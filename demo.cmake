add_executable(
  tetris
  demo.cpp
)

# Pull in pico libraries that we need
target_link_libraries(tetris pico_stdlib pico_scroll)

# create map/bin/hex file etc.
pico_add_extra_outputs(tetris)
