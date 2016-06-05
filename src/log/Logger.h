/*
 * Logger.h
 *
 *  Created on: 9 de abr. de 2016
 *      Author: kevin
 */

#ifndef LOG_LOGGER_H_
#define LOG_LOGGER_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Logger {
public:
	static void insert(string typeLog, string message);
	static void insertError(string message, int errorCode);
	static void insert(string typeLog, int cod);
	static string getDatetime();
	virtual ~Logger();

	static bool MODE_DEBUG;
	static string TYPE_INFO;
	static string TYPE_DEBUG;
	static string TYPE_ERROR;
};

#endif /* LOG_LOGGER_H_ */
