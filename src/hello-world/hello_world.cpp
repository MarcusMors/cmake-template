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

#include <iostream>
#include <string>
#include <sstream>
//user made libs
#include <hello-world/hello_world.hpp>

using namespace std;

void hello_world::say_hello(std::string *t_output)
{
	const char msg[] = "Hello world!";
	cout << msg << endl;
	if (t_output)
	{
		std::ostringstream oss{};
		oss << msg;
		*t_output = oss.str();
	}
}
