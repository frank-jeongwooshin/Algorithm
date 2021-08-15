#pragma once
#include <iostream>
#include <stdexcept>
#include <exception>

#include "Database.h"

class UserInterface
{
public:
	UserInterface();
	void run();

	int displayMenu();
	void doHire(Records::Database& db);
	void doFire(Records::Database& db);
	void doPromote(Records::Database& db);
	void doDemote(Records::Database& db);

private:
	Records::Database mEmployeeDb;
	bool done;
};

