NAME = push_swap

INCLUDES = includes/

SRC = src/

FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

CC = gcc $(FLAGS)

FILES =  \
		utils/lst/list.c utils/lst/list_two.c \
		utils/lst/wrmalloc.c utils/exit.c \
		\
		utils/str/ft_strlen.c utils/str/is.c \
		utils/str/split.c utils/str/atol.c \
		utils/str/ft_strcmp.c \
		\
		operations/swap.c operations/push.c \
		operations/rotate.c \
		main.c parse.c print.c

OBJ = $(addprefix $(SRC), $(FILES))

OBJS = $(OBJ:.c=.o)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $@ -I$(INCLUDES)
	@printf "\n\e[36mpush\e[0m_\e[33mswap \e[92mis ready !\e[0m\e[?25h\n"

%.o: %.c $(INCLUDES)
	@$(CC) -o $@ -c $< -I$(INCLUDES)
	@printf "\e[?25l\e[JCreated \e[92m$(notdir $@)\e[0m\r"

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@printf "All object files [\033[31mX\033[0m]\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(NAME) [\033[31mX\033[0m]\n"

re : fclean all