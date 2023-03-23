
#include "MultimediaPlayer.hpp"

MultimediaPlayer::MultimediaPlayer(const MultimediaPlayer& m)
{
	this->files.clear();
	for (int i = 0; i < m.files.size(); i++) {
		this->addFile(m.files[i]);
	}
}

MultimediaPlayer& MultimediaPlayer::operator=(const MultimediaPlayer& m)
{
	if (this != &m) {
		this->files.clear();
		for (int i = 0; i < m.files.size(); i++) {
			this->addFile(m.files[i]);
		}
	}
	return *this;
}

MultimediaPlayer::~MultimediaPlayer()
{
	for (int i = 0; i < this->files.size(); i++) {
		delete this->files[i];
	}
	this->files.clear();
}

void MultimediaPlayer::print_all_files_states(const int& index) {
	for (int i = 0; i, this->files.size(); i++) {
		Audio* audio = dynamic_cast<Audio*>(this->files[i]);
		Video* video = dynamic_cast<Video*>(this->files[i]);
		Streaming* str = dynamic_cast<Streaming*>(this->files[i]);

		if (audio) {
			///
		}
	}
}

void MultimediaPlayer::addFile(File* f)
{
	this->files.push_back(f->clone());
}

void MultimediaPlayer::removeFile(File* f)
{
	for (int i = 0; i < this->files.size(); i++) {
		if (this->files[i]->getName() == f->getName()) {
			this->files.erase(this->files.begin() + i);
		}
	}
}
