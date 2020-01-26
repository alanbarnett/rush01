# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 17:22:15 by snechaev          #+#    #+#              #
#    Updated: 2020/01/26 19:05:17 by abarnett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=	ft_gkrellm

OBJS :=	main.o\
		AMonitorDisplay.o\
		AMonitorModule.o\
		MultiStrMonitorModule.o\
		NcursesDisplay.o\
		GraphicsDisplay.o\
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

SFML_DIR :=		SFML-2.5.1-macos-clang
SRC_DIRS :=		srcs
INCLUDE_DIRS :=	includes $(SFML_DIR)/include

CXX =		clang++
CXXFLAGS +=	-g -Wall -Wextra -Werror $(foreach dir,$(INCLUDE_DIRS),-I$(dir))
LDFLAGS +=	-L$(SFML_DIR)/lib
LDLIBS +=	-lncurses $(SFML_DIR)/lib/libsfml-window.dylib $(SFML_DIR)/lib/libsfml-graphics.dylib $(SFML_DIR)/lib/libsfml-system.dylib -rpath @executable_path/$(SFML_DIR)/lib

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS)

%.o:		%.cpp Makefile
	$(CXX) $(CXXFLAGS) -MMD -MT $@ -o $@ -c $<

-include $(DEPS)

clean:
	@ rm -f $(OBJS)
	@ rm -f $(DEPS)

fclean:		clean
	@ rm -f $(NAME)

re:     fclean all
