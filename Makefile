NAME = push_swap
NAME_BNS = checker
SOURCES =  push_swap.c cheak_numbers.c cheak_error.c ft_split.c garbage_collector.c utils_1.c utils_2.c push.c reverse_rotate.c rotate.c swap.c sort_nb.c utils_3.c alg_sort.c 
SRC_BNS	= bonus/cheak_numbers_bonus.c bonus/ckeak_error_bonus.c bonus/ft_split_bonus.c bonus/garbage_collector_bonus.c bonus/get_next_line_bonus.c bonus/main_bonus.c bonus/push_bonus.c bonus/reverse_rotate_bonus.c bonus/rotate_bonus.c bonus/swap_bonus.c bonus/utils_1_bonus.c bonus/utils_2_bonus.c bonus/utils_3_bonus.c bonus/utils_gnl_bonus.c    
OBJ = $(SOURCES:.c=.o)
OBJ_BNS = $(SRC_BNS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

bonus: $(OBJ_BNS)
	$(CC) $(CFLAGS) $(OBJ_BNS) -o $(NAME_BNS)

%_bonus.o: %_bonus.c bonus/checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BNS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BNS)

re: fclean all