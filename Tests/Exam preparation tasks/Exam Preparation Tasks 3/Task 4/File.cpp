
#include "File.hpp"

File::File(const std::string& name, const std::string& extension, const size_t& size)
	: name(name), extension(extension), size(size) {}

std::string File::getName() const {
	return this->name;
}

std::string File::getExtension() const
{
	return this->extension;
}

size_t File::getSize() const
{
	return this->size;
}

void File::setName(const std::string& name)
{
	this->name = name;
}

void File::setExtension(const std::string& extension)
{
	this->extension = extension
}

void File::setSize(const size_t& size)
{
	this->size = size;
}

void File::print_debug_state() const
{
	std::cout << this->name << " " << this->extension << " " << this->size << "\n";
}
