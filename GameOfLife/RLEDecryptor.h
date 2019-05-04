#pragma once
#include <string>
#include "Cell.h"

class RLEDecryptor
{
public:
	static void decrypt(matrix&, std::string);
	RLEDecryptor();
	~RLEDecryptor();
};

