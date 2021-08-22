/**
 * @file hello_world.hpp
 * @author Jose Vilca Campana <@marcusmors> (alivezeh@gmail.com)
 * @author Krambert <@demonofideas> (alivezeh@gmail.com)
 *
 * @brief say_hello definition
 * @details defines the function say_hello in the hello_world namespace
 * @version 0.1
 * @date 2021-08-22
 *
 * @copyright Copyright (c) 2021
 */

/** ***************************************************************************
 * @mainpage My program
 *
 * @section course_section Course Information
 * @subsection subsection-name subsection title
 * @subsubsection subsubsection-name subsubsection title
 * @section program_section Program Information
 *
 * @section compiling_section Compiling and Usage
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 *****************************************************************************/

#ifndef __HELLO_WORLD_H__
#define __HELLO_WORLD_H__

// Copyright (C) 2021 José Enrique Vilca Campana
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include <string>

/**
 * @brief library namespace
 *
 * @details namespaces details :v
 *
 */
namespace hello_world
{
	/**
	 * @brief outputs "Hello World!" in the stream.
	 *
	 * @details call this function to print "Hello World!", you can also get a pointer referencing to a string with that message.
	 *
	 * @par Summary
	 * Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod
	 * tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam
	 * quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo
	 * consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse
	 * cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat
	 * non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
	 *
	 * @verbatim
 This text will appear
           exactly as it
      is typed including the
 indentation
 @endverbatim
	 * @bug When reading until end of file, the read function returns
	 *      a size one larger than the data set.
	 * @bug Sorting the data never moves the last element if out of order.
	 *
	 * @todo remove unnecessary tags.
	 * @todo remove unnecessary documentation.
	 *
	 * @param[out] t_output testing optional parameter. contains data that was changed in the function.
	 *
	 * @image html ../../docs-building/assets/random_image.svg "example_image"
	 *
	 * @example say_hello_example.cpp
	 *
	 * @ref hello_world "hello_world namespace reference"
	 * \code {.c++}
	 * hello_world::say_hello()
	 * \endcode
	 *
	 * @deprecated
	 * this is a false deprecated text. Just for trying.
	 *
	 */
	void say_hello(std::string *t_output = nullptr);
} // namespace hello_world

#endif // __HELLO_WORLD_H__
