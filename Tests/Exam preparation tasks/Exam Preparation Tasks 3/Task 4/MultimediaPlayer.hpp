#pragma once
#include"Audio.hpp"
#include "streaming.hpp"
#include"Video.hpp"


class MultimediaPlayer {
public:
	MultimediaPlayer() = default;
	MultimediaPlayer(const MultimediaPlayer& m);
	MultimediaPlayer& operator=(const MultimediaPlayer& m);
	~MultimediaPlayer(); 

	void print_all_files_states(const int& index);

	void addFile(File* f);
	void removeFile(File* f);
private:
	std::vector<File*> files;

};