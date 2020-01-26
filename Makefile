# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 17:22:15 by snechaev          #+#    #+#              #
#    Updated: 2020/01/26 19:03:57 by abarnett         ###   ########.fr        #
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
		NameMonitorModule.o\
		CPUMonitorModule.o\
		RAMMonitorModule.o\
		DateMonitorModule.o\
		UnicornMonitorModule.o\
		UsageMonitorModule.o\
		NetworkMonitorModule.o\
		NetworkStat.o\
		Utils.o
DEPS :=	$(patsubst %.o,%.d,$(OBJS))
		
CXX = clang++
#CXXFLAGS =-g -lsfml-graphics -lsfml-window -lsfml-system -lncurses
CXXFLAGS =-g -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(OBJS) -lncurses

%.o:		%.cpp Makefile
	$(CXX) $(CXXFLAGS) -MMD -MT $@ -o $@ -c $<

-include $(DEPS)

clean:
	@ rm -f $(OBJS)
	@ rm -f $(DEPS)

fclean:		clean
	@ rm -f $(NAME)

re:     fclean all
