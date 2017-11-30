/*
 * 1.4.3.cpp
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
	std::cout << "Enter two numbers: " << std::endl;
	int v1, v2;
	std::cin >> v1 >> v2; // прочитать введенные данные
	// использовать меньшее число как нижнюю границу суммируемого
	// диапазона, а большее число - как верхнюю
	int lower, upper;
	if (v1 <= v2) {
		lower = v1;
		upper = v2;
	} else {
		lower = v2;
		upper = v1;
	}
	int sum = 0;
	// суммировать значения от нижней до верхней
	// границы включительно
	for (int val = lower; val <= upper; val++)
		sum += val; // sum = sum + val
	std::cout << "Sum of " << lower
			  << " to " << upper
			  << " inclusive is "
			  << sum << std::endl;
	return 0;
}
