#include "streaming.hpp"

File* Streaming::clone() const {
	return new Streaming(*this);
}