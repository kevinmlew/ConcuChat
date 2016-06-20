/*
 * Logger.cpp
 *
 *  Created on: 9 de abr. de 2016
 *      Author: kevin
 */

#include "Logger.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

string Logger::TYPE_INFO = "INFO";
string Logger::TYPE_DEBUG = "DEBUG";
string Logger::TYPE_ERROR = "ERROR";
bool Logger::MODE_DEBUG = true;
Logger* Logger::instance = NULL;

#define LOG_FILE "concuchat.log"
#define LOCK_FILE "loglock"

Logger::Logger() : lock(LOCK_FILE){
}

Logger* Logger::getInstance(){
	if (!instance) {
		instance = new Logger();
	}
	return instance;
}

void Logger::destruir () {
	if ( instance != NULL ) {
		delete ( instance );
		instance = NULL;
	}
}

bool Logger::esNecesarioLoggear(string typeLog){
	return (Logger::MODE_DEBUG && typeLog == Logger::TYPE_DEBUG);
}

void Logger::insert(string typeLog, string message){
	if (!esNecesarioLoggear(typeLog)) {
		return;
	}
	getInstance()->lock.tomarLock(1);
	//TODO ahora que es un singleton capaz que se podria pasar el open y close al
	//ctor y dtor.
	ofstream logFile;
	logFile.open(LOG_FILE, ios::out | ios::app | ios::binary);
	logFile << "["<< Logger::getDatetime() << "]" << typeLog << ": " << message << endl;
	logFile.close();
	getInstance()->lock.liberarLock(1);
}

void Logger::insert(string typeLog, int cod){
	stringstream ss;
	ss << cod;
	insert(typeLog, ss.str());
}

void Logger::insertError(string message, int errorCode){
	stringstream ss;
	ss << message << endl << "CODIGO DE ERROR: " << errorCode;
	insert(Logger::TYPE_ERROR, ss.str());
}

string Logger::getDatetime() {
	time_t  timev;
	struct tm * timeinfo;
	time(&timev);
	char buffer[80];
	timeinfo = localtime(&timev);
	strftime(buffer,80,"%Y-%m-%d %I:%M:%S",timeinfo);

	return string(buffer);
}


Logger::~Logger() {
}

