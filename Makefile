# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guhernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 22:18:19 by guhernan          #+#    #+#              #
#    Updated: 2022/02/10 23:01:13 by guhernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= gunner_container
CC					:= clang++
CSAN				:= -fsanitize=address
CFLAGS				:= -g3 -Wall -Wextra -Werror -std=c++98

OBJ_DIR				:= gunner_objs
SRCS_DIR			:= gunner_srcs

################################################################################

_RES_TEST_DIR		:= gunner_results
_RES_TEST_FT_DIR	:= $(_RES_TEST_DIR)/details_ft
_RES_TEST_STD_DIR	:= $(_RES_TEST_DIR)/details_std
_RES_TEST_DIR_ALL	:= $(_RES_TEST_FT_DIR) $(_RES_TEST_STD_DIR)

_INC_TEST_DIR		:= tests
_INC_TEST_V_DIR		:= $(_INC_TEST_DIR)/vector
_INC_TEST_M_DIR		:= $(_INC_TEST_DIR)/map
_INC_TEST_S_DIR		:= $(_INC_TEST_DIR)/stack

_SRCS_GUNNER		:=
_SRCS_GUNNER_PATH	:=
_INC_GUNNER			:=
_INC_GUNNER_PATH	:=
include $(SRCS_DIR)/include.mk

_INC_TEST_V			:= 
_INC_TEST_V_PATH	:= 
_INC_TEST_M			:=
_INC_TEST_M_PATH	:=
_INC_TEST_S			:=
_INC_TEST_S_PATH	:=
include $(_INC_TEST_DIR)/include.mk


_INC_TESTS_PATH			:= $(_INC_TEST_V_PATH) $(_INC_TEST_M_PATH) $(_INC_TEST_S_PATH)
_INC_TESTS_DIR			:= $(_INC_TEST_V_DIR) $(_INC_TEST_M_DIR) $(_INC_TEST_S_DIR)

################################################################################

_TESTED_CONTAINER		:= $(shell find .. -path '../gunner_tester' -type d -prune -o -name "*.*pp" -type f -print)
_INC_CONTAINER_PATH		:= $(filter %.hpp, $(_TESTED_CONTAINER))
_SRCS_CONTAINER_PATH	:= $(filter %.cpp, $(_TESTED_CONTAINER))

_CONTAINER_DIR			:= $(shell find .. -path '../gunner_tester' -type d -prune -o -path '../.git' -type d -prune -o -path './gunner_results' -type d -prune -o  -type d -print | tr '\n' ' ')

_CONTAINER_DIR_OBJ		:= $(subst ../, ,$(_CONTAINER_DIR))
#_INC_CONTAINER			:= $(notdir $(_INC_CONTAINER_PATH))
#_SRCS_CONTAINER		:= $(notdir $(_SRCS_CONTAINER_PATH))

################################################################################

_INCLUDE_DIR		:= $(addprefix -I,$(_INC_TESTS_DIR) $(_CONTAINER_DIR) $(SRCS_DIR))

_REQUIRED_DIR		:= $(OBJ_DIR) $(RES_TEST_DIR) $(_RES_TEST_DIR_ALL) $(addprefix $(OBJ_DIR)/, $(SRCS_DIR) $(_CONTAINER_DIR_OBJ))

INC					:= $(_INC_TESTS_PATH) $(_INC_GUNNER_PATH) $(_INC_CONTAINER_PATH)
SRCS				:= $(_SRCS_GUNNER_PATH) #$(_SRCS_CONTAINER_PATH)
OBJS				:= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

################################################################################

.PHONY:  all re run clean fclean

all :					$(NAME)

$(NAME) :				$(OBJS) 
	$(CC) $(CSAN) $< -o $@

run:	| $(NAME)
	bash run_diff.sh

gunner_objs/%.o :		%.cpp $(INC) | $(_REQUIRED_DIR)
	$(CC) $(CSAN) $(CFLAGS) $(_INCLUDE_DIR)  -c $< -o $@

$(_REQUIRED_DIR):
		mkdir -p $(_REQUIRED_DIR)

################################

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
