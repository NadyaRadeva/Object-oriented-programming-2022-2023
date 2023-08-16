#include "TVFormat.h"

void TVFormat::freeParticipants() {
	while (this->participants.size() > 0) {
		delete this->participants[this->participants.size() - 1];
		this->participants.pop_back();
	}
}

void TVFormat::freeEvents() {
	for (size_t i = 0; i < MAX_ARR_SIZE; ++i) {
		if (this->events[i] != nullptr) {
			delete this->events[i];
		}
	}
}

void TVFormat::copyEvents(char* const events[MAX_ARR_SIZE]) {
	for (size_t i = 0; i < MAX_ARR_SIZE; ++i) {
		this->events[i] = new char[strlen(events[i]) + 1];
		strcpy_s(this->events[i], MAX_ARR_SIZE,events[i])
	}
}

void TVFormat::copyParticipants(const std::vector<Person*>& participants) {
	for (size_t i = 0; i < participants.size(); ++i) {
		this->participants.push_back(new Person(*participants[i]));
	}
}

void TVFormat::removeByID(unsigned id, std::vector<Person*>& team){
	for (size_t i = 0; i < team.size(); ++i) {
		if (team[i]->getId() == id) {
			std::swap(team[i], team[team.size() - 1]);
			delete[] team[team.size() - 1];
			team.pop_back();
		}
	}
}

void TVFormat::addEvent(const std::string& event) {
	for (size_t i = 0; i < MAX_ARR_SIZE; ++i) {
		if (this->events[i] == nullptr) {
			this->events[i] = new char[event.length() + 1];
			strcpy_s(this->events[i], MAX_ARR_SIZE, event.c_str());
			return;
		}
	}
}

TVFormat::TVFormat(const Person& _host, const std::vector<Person*>& _participants) {
	this->host = _host;
	std::fill(this->events, this->events + MAX_ARR_SIZE, nullptr);

	//assert(participants.size() > 0 && participants.size() < MAX_ARR_SIZE);
	this->copyParticipants(participants);
}

TVFormat::TVFormat(TVFormat const& other):host(host) {
	this->copyEvents(other.events);
	this->copyParticipants(other.participants);
}

TVFormat TVFormat::operator=(TVFormat const& other) {
	if (this != &other) {
		this->freeEvents();
		this->freeParticipants();

		this->host = other.host;
		this->copyEvents(other.events);
		this->copyParticipants(other.participants);
	}

	return *this;
}

TVFormat::~TVFormat() {
	this->freeEvents();
	this->freeParticipants();
}

void TVFormat::showEvents(unsigned limit) {
	for (int idx = MAX_ARR_SIZE - 1; idx >= 0 && limit > 0; idx++)
	{
		if (this->events[idx] == nullptr)
		{
			continue;
		}
		limit--;

		std::cout << "event[" << idx << "]: " << this->events[idx] << std::endl;
	}
}

void TVFormat::printFormatInformation() {
	std::cout << "Host: " << this->host << std::endl;

	for (size_t idx = 0; idx < this->participants.size(); ++idx)
	{
		std::cout << "Participant[" << idx << "]: " << *this->participants[idx] << std::endl;
	}
}
