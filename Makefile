##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for infadd prog
##

MAKEFLAGS += --no-print-directory -j

END=\e[0m
GREEN=\e[92m
RED=\x1b[31;01m
YELLOW=\x1b[33;


define rich_echo
[ -t 1 ] && echo -e "\e[1m$(1)\e[0m\t$(2)" || echo -e "$(1)\t$(2)"
endef

SOURCE_DIR		= src
BUILD_DIR		= build

SOURCE			= $(shell find $(SOURCE_DIR) -name "*.cpp")

OBJ		=	$(patsubst $(SOURCE_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCE))

NAME	=	dabtop

CPPFLAGS	+=	-I./include -O2 -W -Wall -Wextra -lncurses

ifneq (,$(findstring debug,$(MAKECMDGOALS)))
	CPPFLAGS += -D__DEBUG -g3
endif

all::	$(NAME)
all::	message

message:
	@echo -e "\e[38;5;33m"
	@figlet $(NAME); exit 0
	@echo -e "\e[0m"
	@echo -e "\e[1m[INFO]\t$(GREEN)Compilation successful ✔$(END)"

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@$(call rich_echo,"CXX","$@")
	@mkdir -p $(@D)
	@$(CXX) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CXX) -o $(NAME) $(OBJ) $(CPPFLAGS)
	@cp dabtop build/dabtop
	@mv build/dabtop build/MyGKrellm
	$(CLEAR)

CLEAR:
	@mkdir -p build
	@mkdir -p debug
	@mv $(OBJ) build
	@[ -f vgcore* ] && mv vgcore.* debug || true

clean:
	@rm -rfv build/* *.plist

debug:
	@$(call rich_echo,"🔨","Debug biniary set")


fclean:	clean
	@rm -fv $(NAME) *.gc*

re::	fclean
re::	all

.PHONY: all clean fclean re debug test DOLIB
