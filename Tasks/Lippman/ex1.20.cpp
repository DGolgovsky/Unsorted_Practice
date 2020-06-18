/*
 * ex1.20.cpp
 * 
 * Copyright 2014 Dmitry <dreyd@list.ru>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>

int main() {
	int val1 = 0, val2 = 0, sum = 0;
	std::cout << "Enter two numbers:\n";
	std::cin >> val1 >> val2;
	for (int i = val1; i <= val2; i++)
		sum += i;
	for (int i = val2; i <= val1; i++)
		sum += i;
	std::cout << sum << std::endl;
	return 0;
}
