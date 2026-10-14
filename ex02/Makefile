CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

TARGET = Forms

SRCS = main.cpp Bureaucrat.cpp AForm.cpp \
		ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm $(OBJS)

fclean: clean
	@rm $(TARGET)

re: fclean all