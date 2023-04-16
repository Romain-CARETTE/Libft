NAME=libft.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror -fsanitize=address -Wno-deprecated-declarations
RM=rm -f
LDFLAGS=-L.
LDLIBS=-lft -lm -lcrypto -lpub -lmagic -lssl -lcrypto
SRC = ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c detach_block.c get_winsize.c  \
ft_lstnew.c ft_itoa.c ft_create_items.c ft_time.c dhexchange.c randomized_string.c get_ip.c get_port.c \
checksum.c read_file.c _strsplit.c random.c ft_llist_splice.c ft_reverse_llist.c __ss_init_llist_crt.c \
__ss_push_back.c __ss_llist_crt_push_front.c callback.c _is_elf.c arr_size.c clear_arr.c __NR_EXIT.c \
__NR_SOCKET.c __NR_SETSOCKOPT.c __NR_BIND.c __NR_LISTEN.c __NR_ACCEPT.c __NR_RT_SIGTIMEDWAIT.c __NR_KILL.c \
initialize_lib_magiclib.c is_file_empty.c create_file_with_content.c ApplySuffixJmpIntel64.c md5.c \
display_md5.c
OBJ = $(SRC:.c=.o)
INC = ./inc/

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
		$(CC) -I. -o $@ -c $? $(CFLAGS) $(LDLIBS)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean clean
