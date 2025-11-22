
NAME = megaphone

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
RM = rm -f

SRC_DIR = src
OBJ_DIR = objects

SRCS = megaphone.cpp
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

CYAN = \001\033[36m\002
RESET = \001\033[0m\002

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@printf "\n"
	@printf "$(CYAN)            ___ ___        ___    _____    _     _      ___ ___ \n$(RESET)"
	@printf "$(CYAN) ___ _ _   | | | | |   ___|  _|  |    _| _| |_ _| |_   | | | | |\n$(RESET)"
	@printf "$(CYAN)| -_|_'_|  | | | | |  | . |  _|  |   |_ |_   _|_   _|  | | | | |\n$(RESET)"
	@printf "$(CYAN)|___|_,_|  |___|___|  |___|_|    |_____|  |_|   |_|    |___|___|\n$(RESET)"
	@printf "$(CYAN)                                                                \n$(RESET)"
	@printf "\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
