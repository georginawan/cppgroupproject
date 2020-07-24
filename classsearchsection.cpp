/*
 * File: classsearchSection.cpp
 * ----------------------------
 *
 *
 */

#include "classsearchsection.h"


vector<Courses> getSelectedCourses(vector<string> selected) {
    string item;
    Courses course0;
    MainArealist Data;
    Data = importdata();
    vector<string> courseFind;
    vector<Courses> courseList;
    vector<Courses> courseFound;
    for (size_t i = 0; i < selected.size(); i++){
        courseFind = getAreaLocation(selected[i]);
        courseList = Data.getinfo(courseFind[0]);
            for (size_t j = 0; j < courseList.size(); j++){
                if (courseList[j].getname() == courseFind[1] ) {
                    course0 = courseList[j];
                }
            }
        courseFound.push_back(course0);
    }
    return courseFound;
}

vector<string> getAreaLocation(string courseName) {
    string Abbr;
    vector<string> courseFind;
    Abbr = courseName.substr(0,3);
    courseFind.push_back(AbbrToFull(Abbr));
    courseFind.push_back(courseName);
    return courseFind;
}
