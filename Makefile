##
## EPITECH PROJECT, 2023
## B-OOP-400-TLS-4-1-raytracer-tom.laiolo
## File description:
## Makefile
##

src 	=	main.cpp \
			math.cpp

obj 	=	$(src:.cpp=.o)

CXXFLAGS =	-Wall -Wextra -Werror -std=c++17 -I./include

NAME 	= 	test

all:	$(NAME)

$(NAME):	$(obj)
	$(CXX) -o $(NAME) $(obj) $(CXXFLAGS)

clean:
	rm -f $(obj)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re