cmake_minimum_required(VERSION 3.25)
project(so_long C)

set(CMAKE_C_STANDARD 99)

# Find the minilibx library
find_library(MLX_LIB mlx)

# Find the X11 library
find_package(X11 REQUIRED)

# Add the include directories for minilibx and X11
include_directories(
        ${X11_INCLUDE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/libft/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Create a list of source files
set(SOURCES app/so_long.c
        src/handle_key_events.c src/read_map.c src/validate_map.c src/memory_management.c)

# Add all source files from libft to the SOURCES list
file(GLOB LIBFT_SOURCES "libft/*.c")
list(APPEND SOURCES ${LIBFT_SOURCES})

# Create a library target for libft
add_library(ft STATIC ${LIBFT_SOURCES} libft/ft_strfull.c libft/ft_includes_char.c)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Link against minilibx and X11
target_link_libraries(${PROJECT_NAME} ${MLX_LIB} ${X11_LIBRARIES} -lm ft)
