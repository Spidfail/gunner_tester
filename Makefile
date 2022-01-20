# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guhernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 14:10:20 by guhernan          #+#    #+#              #
#    Updated: 2022/01/20 17:24:33 by guhernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					:= gunner
MAIN					:= main.cpp
SRCS					:= ITester.hpp
TESTED_MAP				:= 
TESTED_VEC				:= 
TESTED_STK				:= 
TESTED_SET				:= 
#OBJS					:= ??

DIR_SRCS				:= srcs
DIR_TESTED				:= targets
SUBDIR_TESTED_MAP		:= map
SUBDIR_TESTED_VEC		:= vector
SUBDIR_TESTED_STK		:= stack
SUBDIR_TESTED_SET		:= set
DIR_RESULTS				:= gunner_results
SUBDIR_RESULTS			:= details_std details_ft
#DIR_OBJS				:= objs

##################################################################################

TO_MAIN					:= ./$(DIR_SRCS)/
TO_SRCS					:= ./$(DIR_SRCS)/
TO_TESTED_MAP			:= ./$(DIR_TESTED)/$(SUBDIR_TESTED_MAP)/
TO_TESTED_VEC			:= ./$(DIR_TESTED)/$(SUBDIR_TESTED_VEC)/
TO_TESTED_STK			:= ./$(DIR_TESTED)/$(SUBDIR_TESTED_STK)/
TO_TESTED_SET			:= ./$(DIR_TESTED)/$(SUBDIR_TESTED_SET)/
TO_RESULTS				:= ./$(DIR_RESULTS)/

PATH_TO_INCLUDE			:=

include srcs/Include.mk
include targets/Include.mk
include gunner_results/Include.mk

PATH_TO_MAIN			:= $(addprefix $(TO_MAIN), $(MAIN))
PATH_TO_SRCS			:= $(addprefix $(TO_SRCS), $(SRCS))
PATH_TO_RESULTS			:= $(addprefix $(TO_RESULTS), $(SUBDIR_RESULTS))

PATH_TO_TESTED_MAP		:= $(addprefix $(TO_TESTED_MAP), $(TESTED_MAP))
PATH_TO_TESTED_VEC		:= $(addprefix $(TO_TESTED_VEC), $(TESTED_VEC))
PATH_TO_TESTED_STK		:= $(addprefix $(TO_TESTED_STK), $(TESTED_STK))
PATH_TO_TESTED_SET		:= $(addprefix $(TO_TESTED_SET), $(TESTED_SET))

PATH_TO_TESTED			:= $(PATH_TO_TESTED_MAP) \
						   $(PATH_TO_TESTED_VEC) \
						   $(PATH_TO_TESTED_STK) \
						   $(PATH_TO_TESTED_SET)


#PATH_TO_OBJS			:= $(addprefix ./$(DIR_OBJS)$(PATH_INTER_OBJS), $(OBJS))

##################################################################################

CC						:= clang++
CPPFLAGS				:= -Wshadow
OPTIFLAGS				:= -O3
CFLAGS					:= -Wall -Werror -Wextra $(CPPFLAGS) $(OPTIFLAGS)

INCFLAGS				:= -include $(addprefix ./$(DIR_TESTED)/, $(PATH_TO_INCLUDE))

.PHONY : clean fclean re


##################################################################################
##################################################################################


all : $(NAME)

$(NAME) : $(PATH_TO_SRCS)/$(SRCS) $(PATH_TO_MAIN) | $(PATH_TO_RESULTS)
	$(CC) $(CFLAGS) $(INCFLAGS) $(MAIN) $(PATH_TO_MAIN) $(PATH_TO_SRCS) $(PATH_TO_TESTED) -o $@

$(PATH_TO_RESULTS) :
	mkdir -p $@

##################################################################################

clean:
	rm $(RM) $(NAME)

fclean: clean
	rm -rf $(PATH_TO_RESULTS)

re : fclean all


##################################################################################
