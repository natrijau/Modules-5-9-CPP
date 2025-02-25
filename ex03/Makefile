EXEC = forms
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
OBJDIR = obj
SRCDIR = src
INCDIR = include/Bureaucrat.hpp include/AForm.hpp include/RobotomyRequestForm.hpp include/ShrubberyCreationForm.hpp include/PresidentialPardonForm.hpp include/Intern.hpp
SRC = $(SRCDIR)/main.cpp $(SRCDIR)/Bureaucrat.cpp $(SRCDIR)/AForm.cpp $(SRCDIR)/RobotomyRequestForm.cpp $(SRCDIR)/ShrubberyCreationForm.cpp $(SRCDIR)/PresidentialPardonForm.cpp $(SRCDIR)/Intern.cpp
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(EXEC)

clean:
	rm -rf $(OBJDIR) *.txt

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re