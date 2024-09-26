NAME	= woody_woodpacker
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #-g3 -fsanitize=address

RM		= rm -rf
MK_DIR	= mkdir -p

DIR_BUILD	= _build
DIR_SRCS	= src
SRCS		=	main.c \
				parsing/parser.c \
				utils/print.c \
				utils/libFile.c

OBJS	:= $(addprefix $(DIR_BUILD)/, $(SRCS:.c=.o))
DEPS	:= $(addprefix $(DIR_BUILD)/, $(SRCS:.c=.d))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(DIR_BUILD)/%.o: $(DIR_SRCS)/%.c $(DIR_BUILD)/%.d
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_BUILD)/%.d: $(DIR_SRCS)/%.c
	@$(MK_DIR) $(dir $@)
	$(CC) $(CFLAGS) -MM -MT $(basename $@).o  $< -o $@

$(DIR_BUILD):
	$(MK_DIR) $(DIR_BUILD)

clean:
	$(RM) $(DIR_BUILD)

fclean: clean
	$(RM) $(NAME)

re: fclean
	@$(MAKE) all

ifeq ($(MAKECMDGOALS),)
include $(DEPS)
endif
ifeq ($(MAKECMDGOALS),all)
include $(DEPS)
endif
ifeq ($(MAKECMDGOALS),$(NAME))
include $(DEPS)
endif
