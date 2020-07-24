/*
 * File: inputdata.cpp
 * -------------------
 * This file includes the implementation of the function importdata().
 */

#include "inputdata.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


MainArealist importdata() {
    ifstream stream;
    string MainAreaFile;
    MainAreaFile = "MainAreaFile.txt";
    stream.open(MainAreaFile.c_str());

    /* Get the string title for the MainArea */
    string line;
    size_t location;
    MainArealist DataBase;
    vector<Courses> Info;
    while (getline(stream, line)) {
        if (line.length() > 0) {
            location = line.find("-");
            DataBase.set(line.substr(0,location-1),Info);
        }
    }

    stream.close();

    /* Get the content for the MainArea */
    ifstream courseFile;
    string course;
    course = "courseFile.txt";
    courseFile.open(course.c_str());

    string CourseToArea;
    vector<classes> classList;
    vector<Courses> courseList;
    vector<string> info;
    string courseName;
    string className;
    Courses b;
    classes c;
    size_t i = 0;



    while (getline(stream, line)) {
        if (line.length() > 0) {
            if(line[0] == '>') {
                classList.clear();
                i = 0;
                CourseToArea = AbbrToFull(line.substr(1,4));
                courseName = line.substr(1,line.length()-1);
                b.set(courseName,classList);
                DataBase.AddInfo(CourseToArea,b);
                continue;
            }

            if (line[line.length()-1] == ')') {
                info.clear();
                className = line;
                continue;
            }

            if (line.find("Bldg")) {
                info[0] = line;
                continue;
            }

            if (line.find(',')) {
                if(line.length() < 15) {
                    info[2] = line.substr(0,1);
                    info[3] = line.substr(3,line.length()-1);
                } else {
                    info[2] = line.substr(0,1);
                    info[3] = line.substr(3,15);
                    info[4] = line.substr(16,17);
                    info[5] = line.substr(18,line.length()-1);

                }
                continue;
            }

            info[1] = line;
            c.set(className,info);
            classList[i] = c;
            i += 1;
            b.set(courseName,classList);
            DataBase.AddInfo(CourseToArea,b);
        }
    }
    courseFile.close();
    return DataBase;

}

map<string,string> Fulllist() {
    ifstream stream;
    string MainAreaFile;
    MainAreaFile = "MainAreaFile.txt";
    stream.open(MainAreaFile.c_str());

    string line;
    size_t location;
    MainArealist DataBase;
    vector<Courses> Info;
    map<string,string> listA;
    while (getline(stream, line)) {
        if (line.length() > 0) {
            location = line.find("-");
            listA.insert(pair<string,string> (line.substr(0,location-1),line.substr(location+1,line.length()-1)));
        }
    }

    stream.close();
    return listA;
}

map<string,string> Abbrlist() {
    ifstream stream;
    string MainAreaFile;
    MainAreaFile = "MainAreaFile.txt";
    stream.open(MainAreaFile.c_str());

    string line;
    size_t location;
    MainArealist DataBase;
    vector<Courses> Info;
    map<string,string> listA;
    while (getline(stream, line)) {
        if (line.length() > 0) {
            location = line.find("-");
            listA.insert(pair<string,string> (line.substr(location+1,line.length()-1),line.substr(0,location-1)));
        }
    }

    stream.close();
    return listA;
}


string FullToAbbr(string name){
        map<string,string> listA;
        string AbbrName;
        listA = Fulllist();

        map<string,string>::iterator iter;
        iter = listA.find(name);
        if(iter != listA.end()) {
            AbbrName = iter->second;
        }
        return AbbrName;

}

string AbbrToFull(string name){
        map<string,string> listA;
        string Fullname;
        listA = Abbrlist();

        map<string,string>::iterator iter;
        iter = listA.find(name);
        if(iter != listA.end()) {
            Fullname = iter->second;
        }
        return Fullname;
}

