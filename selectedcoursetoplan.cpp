/*
 * File: selectedcoursetoplan.cpp
 * ------------------------------
 *
 */

#include "selectedcoursetoplan.h"
#include <stdlib.h>

vector<Courses> singleItem(Courses a) {
    Courses singleCourse;
    vector<Courses> result;
    vector<classes> Lectures;
    vector<classes> Tutorials;
    vector<classes> classList;
    vector<classes> singleCombination;

    classList = a.getinfo();
    size_t n = classList.size();

    for (size_t i = 0; i < n; i++) {
        if (classList[i].getname()[0] == 'L') {
            Lectures.push_back(classList[i]);
        } else {
            Tutorials.push_back(classList[i]);
        }
    }

    for (size_t j = 0; j < Lectures.size(); j++) {
        if (Tutorials.size() != 0) {
            for (size_t z = 0; z < Tutorials.size(); z++) {
                singleCombination.push_back(Lectures[j]);
                singleCombination.push_back(Tutorials[z]);
                singleCourse.set(a.getname(), singleCombination);
                result.push_back(singleCourse);
                continue;
            }
        } else {
            singleCombination.push_back(Lectures[j]);
            singleCourse.set(a.getname(), singleCombination);
            result.push_back(singleCourse);
        }
    }
    return result;
}


bool timeConflict(Courses a, Courses b) {
    vector<vector<string>> dateList;
    vector<vector<string>> dateList1;
    vector<string> date;
    vector<classes> classList;

    for (size_t i = 0; i < a.getinfo().size(); i++) {
        date.push_back(a.getinfo()[i].getinfo()[2]);
        date.push_back(a.getinfo()[i].getinfo()[3]);
        dateList.push_back(date);
        if (a.getinfo()[i].getinfo().size() > 4) {
            date.clear();
            date.push_back(a.getinfo()[i].getinfo()[4]);
            date.push_back(a.getinfo()[i].getinfo()[5]);
            dateList.push_back(date);
        }
    }

    for (size_t j = 0; j < b.getinfo().size(); j++) {
        date.push_back(b.getinfo()[j].getinfo()[2]);
        date.push_back(b.getinfo()[j].getinfo()[3]);
        dateList1.push_back(date);
        if (b.getinfo()[j].getinfo().size() > 4) {
            date.clear();
            date.push_back(b.getinfo()[j].getinfo()[4]);
            date.push_back(b.getinfo()[j].getinfo()[5]);
            dateList1.push_back(date);
        }
    }
    int id = 0;
    for (size_t i = 0; i < dateList.size(); i++) {
        for (size_t j = 0; j < dateList1.size(); j++) {
            if (dateList[i][1] == dateList[j][1]) {
                int hour00 = atoi(dateList[i][2].substr(0,1).c_str());
                int hour01 = atoi(dateList[i][2].substr(6,7).c_str());
                int hour10 = atoi(dateList1[i][2].substr(0,1).c_str());
                int hour11 = atoi(dateList1[i][2].substr(6,7).c_str());
                if (hour00 < hour10 && hour10 <hour01) {
                    id = 1;
                }
                if (hour10 < hour00 && hour00 < hour11) {
                    id = 1;
                }
                if (hour01 == hour10) {
                    int minute00 = atoi(dateList[i][2].substr(9,10).c_str());
                    int minute01 = atoi(dateList1[i][2].substr(3,4).c_str());
                    if (minute00 > minute01) {
                        id = 1;
                    }
                }
                if (hour00 == hour11) {
                    int minute00 = atoi(dateList[i][2].substr(3,4).c_str());
                    int minute01 = atoi(dateList1[i][2].substr(9,10).c_str());
                    if (minute00 < minute01) {
                        id = 1;
                    }
                }
            }
        }
    }
    if (id == 1) {
        return true;
    } else {
        return false;
    }
}


vector<Plan> planConstruct(vector<string> selected) {
    vector<Courses> SelectedCoursesList;
    vector<Courses> PlanInfo;
    vector<Plan> plan0;

    SelectedCoursesList = getSelectedCourses(selected);
    findPossiblePlan(SelectedCoursesList, plan0);

    return plan0;
}


void findPossiblePlan(vector<Courses> SelectedCoursesList, vector<Plan> & plan0) {
    vector<Courses> SingleItemList0;
    vector<Courses> visited;
    SingleItemList0 = singleItem(SelectedCoursesList[0]);
    Plan Plan1;

    if (SelectedCoursesList.size() == 0) {
        Plan1.setInfo(visited);
        plan0.push_back(Plan1);
    }

    for (size_t i = 0; i < SingleItemList0.size(); i++) {
        if(visited.size() > 0) {
            for (size_t j = 0; j < visited.size(); j++) {
                if(timeConflict(visited[j], SingleItemList0[i]) != false) {
                    visited.push_back(SingleItemList0[i]);
                    SelectedCoursesList.erase(SelectedCoursesList.begin());
                    findPossiblePlan(SelectedCoursesList, plan0);
                }
            }
        } else {
            visited.push_back(SingleItemList0[i]);
            SelectedCoursesList.erase(SelectedCoursesList.begin());
            findPossiblePlan(SelectedCoursesList, plan0);
        }
    }
}



