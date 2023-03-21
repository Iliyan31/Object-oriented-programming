#pragma once

class Message {
public:
	Message(int data) : data(data) {};
	int getData() const {
		return this->data;
	}
	const int data;
};