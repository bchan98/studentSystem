#pragma once
#include <string>
// categorize degree programs as integers
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// make a parallel array of strings to give appropriate degree given index
static const std::string degreeTypeStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };