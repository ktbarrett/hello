#ifndef HELLO_HPP
#define HELLO_HPP

#include <string>


/** Hello
 *
 * Contains example functions.
 */
namespace hello {

/** Says hello
 *
 * @param name Says hello to the given name. If no name is given, it says hello to the world.
 * @returns The greeting as a string.
 */
std::string hello(char const * name = "World");

/** Answers an important question
 *
 * @returns Answer to the Ultimate Question of Life, the Universe, and Everything.
 */
int return_answer_to_life();

}

#endif
