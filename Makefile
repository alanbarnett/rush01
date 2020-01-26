# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 17:22:15 by snechaev          #+#    #+#              #
#    Updated: 2020/01/25 18:25:22 by snechaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  ft_gkrellm

OBJS = main.o\
		AMonitorDisplay.o\
		AMonitorModule.o\
		MultiStrMonitorModule.o\
		NcursesDisplay.o\
		Keyboard.o\
		OSMonitorModule.o\
		CPUloadModule.o\
		NameMonitorModule.o\
		DateMonitorModule.o\

		
CXX = clang++
#CXXFLAGS =-g -lsfml-graphics -lsfml-window -lsfml-system -lncurses
CXXFLAGS =-g -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(OBJS) -lncurses

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:     fclean all