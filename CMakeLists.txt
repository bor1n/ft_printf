cmake_minimum_required(VERSION 3.19)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(libft)
add_executable(ft_printf ft_printf.c includes/ft_printf.h ft_printf_c.c ft_printf_d.c ft_printf_s.c util.c ft_printf_u.c ft_printf_x.c ft_printf_p.c util2.c ft_printf_helper.c)
target_link_libraries(ft_printf PUBLIC libft)