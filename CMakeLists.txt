cmake_minimum_required(VERSION 3.25)
project(so_long C)

set(CMAKE_C_STANDARD 99)


# Find the minilibx library
find_library(MLX_LIB mlx)

# Find the X11 library
find_package(X11 REQUIRED)

# Add the include directories for minilibx and X11
include_directories(${X11_INCLUDE_DIR})

add_executable(so_long ./app/so_long.c ./src/handle_key_events.c)
# Link against minilibx and X11
target_link_libraries(so_long ${MLX_LIB} ${X11_LIBRARIES} -lm -L ./libft)
