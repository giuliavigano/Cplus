/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:32:10 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 10:32:11 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();

	void	addContact();
	void	searchContact();
	void	displayContact(int index);
private:
	Contact contacts[8];
	int		contactCount;
	int		nextIndex;

};

#endif