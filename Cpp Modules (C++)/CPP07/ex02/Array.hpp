/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:10:52 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/26 19:04:08 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>
class Array
{
	private:
		T *data;
		unsigned int _size;
	public:
		Array()
		{
			this->_size = 0;
			this->data = new T[0];
		};
		Array(unsigned int n)
		{
			this->_size = n;
			this->data = new T[this->_size];
		};
		Array(const Array &other)
		{
			this->_size = other._size;
			this->data = new T[this->_size]; 
			for (unsigned int i(0); i < this->_size; i++)
			{
				this->data[i] = other.data[i];
			}
		};
		Array& operator=(const Array &other)
		{
			if (this == &other)
				return (*this);
			delete[] this->data;
			this->_size = other._size;
			this->data = new T[this->_size];
			for (unsigned int i(0); i < this->_size; i++)
			{
				this->data[i] = other.data[i];
			}
			return (*this);
		};

		T& operator[](unsigned int i) const
		{
			if (i >= this->_size)
				throw OutOfBoundsException();
			return this->data[i];
		};
		
		unsigned int size(void) const
		{
			return _size;
		};
		
		~Array()
		{
			delete[] this->data;
		};
		
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw(){
					return "Index is out of bounds";
				} 
		};
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr)
{
	for (unsigned int i(0); i < arr.size(); i++)
	{
		out << i << ") " << arr[i] << "  ";
	}
	return out;
}

#endif