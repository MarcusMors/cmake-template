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

#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
// #include "catch.hpp"
#include <catch2/catch_all.hpp>

#include <string>

//user made libraries
#include <hello-world/hello_world.hpp>

TEST_CASE("Hello World!")
{
	const char HELLO_WORLD[]{"Hello world!"};
	std::string output_hello_world{""};
	std::string *output_hello_world_ptr = &output_hello_world;
	hello_world::say_hello(output_hello_world_ptr);

	bool test{true};
	for (int i = 0; i < sizeof(HELLO_WORLD); i++)
	{
		if (output_hello_world[i] != HELLO_WORLD[i])
		{
			test = false;
		}
	}
	REQUIRE(test == true);
}
