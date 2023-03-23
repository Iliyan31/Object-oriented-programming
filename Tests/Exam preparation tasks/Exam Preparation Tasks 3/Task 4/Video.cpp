
#include "Video.hpp"

File* Video::clone() const {
	return new Video(*this);
}