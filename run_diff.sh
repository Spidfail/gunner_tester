# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_diff.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guhernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 15:29:11 by guhernan          #+#    #+#              #
#    Updated: 2022/02/10 19:39:05 by guhernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_results_ft=$(find $(pwd) -name "details_ft" -type d)
_results_std=$(find $(pwd) -name "details_std" -type d)

rm -f $_results_ft/* $_results_std/*

test_diff() {
	if [ "$(diff -q $1 $2)" ]
	then
		vimdiff "$1" "$2"
	fi
}


#leaks -atExit -- ./gunner_container $_results_std $_results_ft
./gunner_container $_results_std $_results_ft > /dev/null

array_ft=($(ls -d "$_results_ft"/*))
array_std=($(ls -d "$_results_std"/*))

_it=0
_it_end=$(ls $_results_ft | wc -l | sed 's/ //g')

while [ $_it -lt $_it_end ]
do
	test_diff ${array_std[_it]} ${array_ft[_it]}
	((++_it))
done

