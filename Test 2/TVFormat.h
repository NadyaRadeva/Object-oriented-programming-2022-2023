#ifndef _TVFORMAT_H
#define _TVFORMAT_H

#include "Person.h"
#include<vector>
#include<string>

class TVFormat {
	static const int MAX_ARR_SIZE = 128;

	void freeParticipants();
	void freeEvents();
	void copyEvents(char* const events[MAX_ARR_SIZE]);
	void copyParticipants(const std::vector<Person*>& participants);

protected:
	Person host;
	char* events[MAX_ARR_SIZE];
	std::vector<Person*> participants;

	void removeByID(unsigned id, std::vector<Person*>& team);
	void addEvent(const std::string& event);

public:
	TVFormat(const Person& _host, const std::vector<Person*>& _participants);
	TVFormat(TVFormat const& other);
	TVFormat operator=(TVFormat const& other);
	virtual ~TVFormat();

	void  showEvents(unsigned limit);
	void printFormatInformation();
	virtual void doEvent() = 0;
};

#endif // !_TVFORMAT_H
