#pragma once
#include "File.hpp"


class Audio : public File {
public:
	size_t lenght = 0;
	std::string singer = " ";
	File* clone() const;
	~Audio() = default;
};