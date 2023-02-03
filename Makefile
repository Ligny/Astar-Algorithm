MAIN	=	src/main.cpp

SRC		=	src/Game.cpp	\
			src/Map.cpp	\
			src/Tile.cpp	\
			src/Astar.cpp	\
			src/RawMap.cpp	\

CFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

CXXFLAGS	=	-std=c++17

CPPINCLUDE	=	-I/opt/homebrew/Cellar/sfml/2.5.1_1/include

CPPLIB = -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib

LDLIBS	=	-lcriterion

TESTSRC	=	

NAME	=	astar

TEST_NAME 	= 	tests_run

TEST_FILE 	= 	*.gcno	\
			*.gcda

$(NAME): $(OBJ) $(OBJ)
	g++ $(MAIN) $(SRC) $(CPPINCLUDE) -o $(NAME) $(CPPLIB) $(CXXFLAGS) $(CFLAGS)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

tests_run: CFLAGS += --coverage
tests_run: LDLIBS += -lcriterion
tests_run:	tests_clean
	g++ -o tests_run $(SRC) $(TESTSRC) $(CFLAGS) $(CPPFLAGS) $(LDLIBS)
	./tests_run

tests_clean:	clean
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf tests_run

.PHONY:	all debug clean tests_run fclean re