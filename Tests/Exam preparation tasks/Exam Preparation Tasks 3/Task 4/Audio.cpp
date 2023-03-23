
#include "Audio.hpp"

File* Audio::clone() const {
	return new Audio(*this);
}