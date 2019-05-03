#pragma once
#include <string>
#include "Cell.h"

class RLEDecryptor
{
public:
	static void decrypt(Matrix<Cell>&, std::string);
	RLEDecryptor();
	~RLEDecryptor();
};

