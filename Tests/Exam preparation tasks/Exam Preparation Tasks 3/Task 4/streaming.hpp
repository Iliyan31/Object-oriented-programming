#pragma once

#include "File.hpp"

class Streaming : public File {
public:
	std::string source = " ";
	File* clone() const;
	~Streaming() = default;
};