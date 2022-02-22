/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsStd.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 00:17:37 by guhernan          #+#    #+#             */
/*   Updated: 2022/02/11 00:32:15 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <map>
#include <stack>

namespace ft {

	template <class T, T v>
		struct namespace_constant {
			static constexpr T value = v;
			typedef T value_type;
			typedef namespace_constant<T,v> type;
			constexpr operator T() { return v; }
		};

	typedef	namespace_constant<bool, true>	t_true;
	typedef	namespace_constant<bool, false>	t_false;

	template <typename Ct> struct is_std : public t_false {};

	template <typename T, typename Alloc> struct			is_std< std::vector<T, Alloc> > : public t_true{};

	template <typename Key, typename MappedType,
			 typename KeyCompare, typename Alloc> struct	is_std< std::map<Key, MappedType, KeyCompare, Alloc> > : public t_true{};

	template <typename T, typename Ct> struct				is_std< std::stack<T, Ct> > : public t_true{};

}
