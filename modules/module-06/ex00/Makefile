EXEC = convert
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
OBJDIR = obj
SRCDIR = src
INCDIR = include/ScalarConverter.hpp
SRC = $(SRCDIR)/main.cpp $(SRCDIR)/ScalarConverter.cpp
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(EXEC)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re