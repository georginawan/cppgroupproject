#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

#include "inputdata.h"
#include "datastructure.h"
#include "course_auto.h"

using namespace std;

int stringHourToInteger(string str) {
    if (str.length() > 2) return 0;
    return (int(str[0]) - int('0')) * 10 + (int(str[1])-int('0'));
}

string integerToString(unsigned int i) {
    string s = "";
    while (i > 0) {
        int d = i % 10;
        i = i / 10;
        char c = char(int('0') + d);
        s.insert(0, 1, c);
    }
    return s;
}

void putTime(vector<classes> & c, vector< vector<int> > & t) {
    for (unsigned int i = 0; i < c.size(); i++) {
        for (unsigned int k = 2; k < c[i].getinfo().size(); k += 2) {
            string sday = c[i].getinfo()[k];
            int day = 0;
            if (sday == "Mo") {day = 0;}
            else if (sday == "Fe") {day = 1;}
            else if (sday == "We") {day = 2;}
            else if (sday == "Th") {day = 3;}
            else if (sday == "Fr") {day = 4;};
            string stime = c[i].getinfo()[k+1];
            string sstart = stime.substr(0,5);
            int start = (stringHourToInteger(sstart.substr(0,2)) - 8) * 2;
            if (stringHourToInteger(sstart.substr(3,2)) != 0) start++;
            string send = stime.substr(6,5);
            int end = (stringHourToInteger(send.substr(0,2)) - 8) * 2;
            if (stringHourToInteger(send.substr(3,2)) != 0) end++;
            end--;
            for (int j = start; j <= end; j++) {
                t[unsigned(day)][unsigned(j)] = 1;
            }
        }
    }
}

bool checkConflict(Plan & plan) {
    vector<Courses> p = plan.getinfo();
    unsigned int numberOfClasses = p.size();
    bool conflict = false;
    for (unsigned int i = 0; i < numberOfClasses; i++) {
        vector< vector<int> > timei(5);
        for (unsigned int a = 0; a < 5; a++) {
            timei[a].resize(30,0);
        }
        vector<classes> classesi = p[i].getinfo();
        putTime(classesi, timei);

        for (unsigned int j = i + 1; j < numberOfClasses; j++) {
                vector< vector<int> > timej(5);
                for (unsigned int a = 0; a < 5; a++) {
                    timej[a].resize(30,0);
                }
                vector<classes> classesj = p[i].getinfo();
                putTime(classesj, timej);

                for (unsigned int a = 0; a < 5; a++) {
                    for (unsigned int b = 0; b < 30; b++) {
                        if ((timei[a][b] == 1) && (timej[a][b] == 1)) {
                            conflict = true;
                            break;
                        }
                    }
                    if (conflict) break;
                }
        }
        if (conflict) break;
    }
    return conflict;
}

/*int sumOfCredit(vector<Courses> & plan) {
    int credit = 0;
    set<string> courses; courses.clear();
    for (unsigned int i = 0; i < plan.size(); i++) {
        string name = plan[i].getname().substr(0,7);
        if (courses.contains(name)) continue;
        courses.add(name);
        int classCredit;
        //How to get the credit of one course-------------------------
        credit += classCredit;
    }
    return credit;
}***********************/

int sumOfPriority(Plan & plan, map<string, int> & priorityList) {
    int sum = 0;
    int size = static_cast<int>(plan.getinfo().size());
    for (int i = 0; i < size; i++) {
        string name = plan.getinfo()[static_cast<unsigned int>(i)].getname();
        int classPriority = priorityList[name];
        sum += classPriority;
    }
    return sum;
}

void checkPlan(vector<Courses> & courseList, map<string, int> & priorityList,
               unsigned int presentCourse, Plan & autoPlan,
               vector<Plan> & outputPlans) {
    //int credit = sumOfCredit(autoPlan);******************
    if (courseList.size() > 6) return;
    if (presentCourse <= courseList.size()-1) {
        vector<classes> presentClasses = courseList[presentCourse].getinfo();
        string presentName = courseList[presentCourse].getname();
        int numberOfLectures = 0;
        int numberOfTutorials = 0;
        for (unsigned int i = 0; i < presentClasses.size(); ++i) {
            if (presentClasses[i].getname()[0] == 'L') numberOfLectures++;
            if (presentClasses[i].getname()[0] == 'T') numberOfTutorials++;
        }

        if (numberOfTutorials == 0){
            for (int i = 0; i < numberOfLectures; i++) {
                Courses c;
                vector<classes> c_class(1);
                c_class.push_back(presentClasses[unsigned(i)]);
                c.set(presentName, c_class);

                vector<Courses> p = autoPlan.getinfo();
                p.push_back(c);
                autoPlan.setInfo(p);
                checkPlan(courseList, priorityList, presentCourse + 1, autoPlan, outputPlans);
                p.pop_back();
                autoPlan.setInfo(p);
            }
            if (priorityList[presentName] != 0) {
                checkPlan(courseList, priorityList, presentCourse + 1, autoPlan, outputPlans);
            }
        } else {
            for (int i = 0; i < numberOfLectures; i++) {
                for (int j = 0; j < numberOfTutorials; j++){
                    Courses c;
                    vector<classes> c_class(2);
                    c_class.push_back(presentClasses[unsigned(i)]);
                    c_class.push_back(presentClasses[unsigned(numberOfLectures + j - 1)]);
                    c.set(presentName, c_class);

                    vector<Courses> p = autoPlan.getinfo();
                    p.push_back(c);
                    autoPlan.setInfo(p);
                    checkPlan(courseList, priorityList, presentCourse + 1, autoPlan, outputPlans);
                    p.pop_back();
                    autoPlan.setInfo(p);
                }
                if (priorityList[presentName] != 0) {
                    checkPlan(courseList, priorityList, presentCourse + 1, autoPlan, outputPlans);
                }
            }
        }
        return;
    }
    if (courseList.size() < 3) return;

    if (! checkConflict(autoPlan)) {
        outputPlans.push_back(autoPlan);
    }
}

map<string, vector<string>> outputMap(vector<Plan> & outputPlans, map<string, int> & priorityList) {
    unsigned int numberOfPlans = outputPlans.size();
    vector<int> priority(numberOfPlans);
    for (unsigned int i = 0; i < numberOfPlans; i++) {
        priority[i] = sumOfPriority(outputPlans[i], priorityList);
    }

    for (unsigned int i = 0; i < numberOfPlans; i++) {
        int minPriority = INT_MAX;
        unsigned int pointer = i;
        for (unsigned int j = i; j < numberOfPlans; j++){
            if (priority[j] < minPriority) {
                minPriority = priority[j];
                pointer = j;
            }
        }
        int tempInt = priority[i];
        priority[i] = priority[pointer];
        priority[pointer] = tempInt;
        Plan tempPlan = outputPlans[i];
        outputPlans[i] = outputPlans[pointer];
        outputPlans[pointer] = tempPlan;
    }

    map<string, vector<string>> m; m.clear();
    for (unsigned i = 0; i < numberOfPlans; i++) {
        string planName = string("Plan") + integerToString(i);
        Plan plan = outputPlans[i];
        unsigned int numberOfClasses = plan.getinfo().size();
        vector<string> vstring(numberOfClasses);

        for (unsigned int i = 0; i < numberOfClasses; i++) {
            Courses presentCourse = plan.getinfo()[i];
            string courseName = presentCourse.getname();
            courseName += "-";
            for (unsigned int k = 0; k < presentCourse.getinfo().size(); k++) {
                string className = presentCourse.getinfo()[k].getname();
                courseName += className;
            }
            vstring.push_back(courseName);
        }
        m.insert(pair<string, vector<string>>(planName, vstring));
    }

    return m;
}

map<string, vector<string>> automaticArrangement(const vector<string> & courses, MainArealist & MAL) {
    unsigned int numberOfCourses = courses.size();

    vector<Courses> courseList(courses.size());
    for (unsigned int i = 0; i < numberOfCourses; i++) {
        string classname = courses[i].substr(0,7);
        string areaname = courses[i].substr(0,3);
        areaname = AbbrToFull(areaname);

        for (unsigned int i = 0; i < MAL.getinfo(areaname).size(); ++i) {
            if (MAL.getinfo(areaname)[i].getname() == classname) {
                courseList.push_back(MAL.getinfo(areaname)[i]);
                break;
            }
        }

    }

    map<string, int> priorityList;
    for (unsigned int i = 0; i < numberOfCourses; i++) {
        string classname = courses[i].substr(0,7);
        int priority;
        switch (courses[i][8]) {
            case '5': priority = 5; break;
            case '4': priority = 4; break;
            case '3': priority = 3; break;
            case '2': priority = 2; break;
            case '1': priority = 1; break;
            case '0': priority = 0; break;
            default: priority = INT_MAX; break;
        }
        priorityList[classname] = priority;
    }

    Plan autoPlan;
    autoPlan.setname("auto");
    vector<Courses> initial(courseList.size());
    autoPlan.setInfo(initial);

    vector<Plan> outputPlans(1000);

    checkPlan(courseList, priorityList, unsigned(0), autoPlan, outputPlans);

    map<string, vector<string> > out; out.clear();
    out = outputMap(outputPlans, priorityList);

    return out;
}

void printList(course_auto & ui, map<string, vector<string>> & outputMap){
    unsigned int numberOfPlans = outputMap.size();
    for (unsigned int i = 0; i < numberOfPlans; i++) {
        string planName = string("Plan") + integerToString(i);
        ui.setPlan(planName);
    }
}

void printListContent(course_auto & ui, vector<string> & vstring) {
    ui.setPlanList(vstring);
}

void printSchedual(course_auto & ui, vector<string> & vstring, MainArealist & MAL) {
    unsigned int numberOfCourses = vstring.size();
    for (unsigned int i = 0; i < numberOfCourses; i++) {
        string classInfo = vstring[i];
        string areaName = classInfo.substr(0,3);
        string className = classInfo.substr(0,7);
        string lectureName;
        string tutorialName;
        if (classInfo.find("T")) {
            tutorialName = classInfo.substr(classInfo.find("T"), classInfo.length() - classInfo.find("T"));
            classInfo.erase(classInfo.find("T"), classInfo.length() - classInfo.find("T"));
        }
        if (classInfo.find("L")) {
            lectureName = classInfo.substr(classInfo.find("L"), classInfo.length() - classInfo.find("L"));
            classInfo.erase(classInfo.find("L"), classInfo.length() - classInfo.find("L"));
        }
        vector<Courses> courses = MAL.getinfo(AbbrToFull(areaName));
        vector<classes> c;
        for (unsigned int i = 0; i < courses.size(); i++) {
            if (courses[i].getname() == className) {
                c = courses[i].getinfo();
            }
        }
        for (unsigned int i = 0; i < c.size(); i++) {
            if ((c[i].getname() == lectureName) || (c[i].getname() == tutorialName)) {
                vector<string> timeInfo = c[i].getinfo();
                string printName = className + "-" + c[i].getname();
                for (unsigned int k = 2; k < timeInfo.size(); k += 2) {
                    string sday = timeInfo[k];
                    int col = 0;
                    if (sday == "Mo") {col = 0;}
                    else if (sday == "Fe") {col = 1;}
                    else if (sday == "We") {col = 2;}
                    else if (sday == "Th") {col = 3;}
                    else if (sday == "Fr") {col = 4;};

                    string stime = c[i].getinfo()[k+1];
                    string sstart = stime.substr(0,5);
                    int start = (stringHourToInteger(sstart.substr(0,2)) - 8) * 2;
                    if (stringHourToInteger(sstart.substr(3,2)) != 0) start++;
                    start -= 1;
                    string send = stime.substr(6,5);
                    int end = (stringHourToInteger(send.substr(0,2)) - 8) * 2;
                    if (stringHourToInteger(send.substr(3,2)) != 0) end++;
                    end -= 2;
                    ui.combine(start, col, end-start+1, 1);
                    ui.dragCourse(printName, col, start);
                }
            }
        }
    }
}

void printListContentAndSchedual(course_auto & ui, vector<string> & vstring, MainArealist & MAL) {
    printListContent(ui, vstring);
    printSchedual(ui, vstring, MAL);
}
