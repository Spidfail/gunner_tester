# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    include.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guhernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 17:08:38 by guhernan          #+#    #+#              #
#    Updated: 2022/02/11 00:34:37 by guhernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_SRCS_GUNNER 		:= main.cpp
_INC_GUNNER			:= NEWGunner.hpp \
					   IsStd.hpp \
					   ft_random.hpp \
					   PrintText.hpp \
					   VectorTesterUtils.hpp

_SRCS_GUNNER_PATH	:= $(addprefix $(SRCS_DIR)/, $(_SRCS_GUNNER))
_INC_GUNNER_PATH	:= $(addprefix $(SRCS_DIR)/, $(_INC_GUNNER))
