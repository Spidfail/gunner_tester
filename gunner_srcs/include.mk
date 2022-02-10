# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    include.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guhernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 17:08:38 by guhernan          #+#    #+#              #
#    Updated: 2022/02/10 18:23:57 by guhernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_SRCS_GUNNER 		:= main.cpp
_INC_GUNNER			:= VectorTester.hpp \
					   VectorTesterUtils.hpp \
					   ITester.hpp \
					   ft_random.hpp 

_SRCS_GUNNER_PATH	:= $(addprefix $(SRCS_DIR)/, $(_SRCS_GUNNER))
_INC_GUNNER_PATH	:= $(addprefix $(SRCS_DIR)/, $(_INC_GUNNER))
