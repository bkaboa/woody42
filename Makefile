NAME	= woody_woodpacker
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #-g3 -fsanitize=address

RM		= rm -rf
MK_DIR	= mkdir -p

DIR_BUILD	= _build
DIR_SRCS	= src
SRCS		= main.c
HEADERS		= hdr/woody.h

OBJS		:= $(addprefix $(DIR_BUILD)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(DIR_BUILD)/%.o: $(DIR_SRCS)/%.c $(HEADERS) $(DIR_BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_BUILD):
	$(MK_DIR) $(DIR_BUILD)

clean:
	$(RM) $(DIR_BUILD)

fclean: clean
	$(RM) $(NAME)
