/*
 * File: inputdata.h
 * -----------------
 * This file defines the functions related to the data processing.
 */


#ifndef INPUTDATA_H
#define INPUTDATA_H

#include "datastructure.h"

MainArealist importdata();

string FullToAbbr(string name);

string AbbrToFull(string name);

map<string,string> Abbrlist();

map<string,string> Fulllist();



#endif // INPUTDATA_H
