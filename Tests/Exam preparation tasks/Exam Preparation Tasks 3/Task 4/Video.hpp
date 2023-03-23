#pragma once
#include "Audio.hpp"
#include <vector>


class Video : public File {
public:
	std::string subtitles = " ";
	std::vector<Audio> audios;
	File* clone() const;
	~Video() = default;
};