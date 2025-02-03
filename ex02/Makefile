# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrian <adrian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 20:29:24 by aduenas-          #+#    #+#              #
#    Updated: 2025/02/02 18:02:27 by adrian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= tipeIdentify
CPP		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
OBJS	= $(SRC:.cpp=.o)
SRC		= main.cpp Base.cpp
HEADERS	= Base.hpp A.hpp B.hpp C.hpp

%.o: %.cpp $(HEADERS) Makefile
	$(CPP) $(CFLAGS) -c $< -o $@
all: $(NAME) Makefile
$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re:fclean all
.PHONY: all clean fclean re
