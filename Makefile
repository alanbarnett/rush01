NAME =  ft_gkrellm

OBJS = main.o\
		AMonitorDisplay.o\
		AMonitorModule.o\
		MultiStrMonitorModule.o\
		NcursesDisplay.o\
		Keyboard.o\
		OSMonitorModule.o\
		CPUloadModule.o\
		
CXX = clang++
CXXFLAGS =-g -lsfml-graphics -lsfml-window -lsfml-system -lncurses

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:     fclean all