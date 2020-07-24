/*
 * File: automaticarrangement.h
 * ----------------------------
 * This file defines the functions needed for automatic course arrangement.
 */

#ifndef AUTOARRANGEMENT_H
#define AUTOARRANGEMENT_H

#include <iostream>
#include <vector>
#include "inputdata.h"

#include "course_auto.h"
using namespace std;

/* Tool: stringHourToInteger(string str)
 *       integerToString(unsigned int i)
 *       putTime(vector<classes> & c, vector< vector<int>> & t
 * -----------------------------------------------------------
 * These methods offer needed tools for subejctive functions.
 * stringHourToInteger transforms string-type hour data into int-type.
 * integerToString transforms unsigned-int-type object into string.
 * putTime transform string-type time data stored in classes objects into a 5*30 grid(formed by double vector).
 */
int stringHourToInteger(string str);
string integerToString(unsigned int i);
void putTime(vector<classes> & c, vector< vector<int> > & t);

/* Method: checkConflict(Plan plan)
 * Usage: bool conflict = checkConflict(plan)
 * ------------------------------------------
 * This method returns whether the chosen plan is conflict in time.
 * If there exists conflict, it will return true; otherwise, flase.
 */
bool checkConflict(Plan & plan);
/* Method: sumOfCredit(Plan & plan)
 *         sumOfPriority(Plan & plan, map<string, int> & priorityList)
 * Usage: int sumC = sumOfCredit(plan)
 *        int sumP = sumOfPriority(plan, priorityList)
 * ---------------------------------------------------
 * These methods return the sum of credit and priority of a chosen plan.
 */
/*int sumOfCredit(vector<Courses> & plan);*/
int sumOfPriority(Plan & plan, map<string, int> & priorityList);

/* Method: checkPlan(vector<Courses> & courseList //The list of all courses chosen by client
 *                   map<string, int> & priorityList //The map of the priority of every course
 *                   unsigned int presentCourse //The pointer to the current course,
 *                                                when it reachs the end,
 *                                                the function will check the plan
 *                   Plan & autoPlan //The plan formed by selected classes from the list
 *                   vector<Plan> & outputPlans //All valid found plans)
 * ---------------------------------------------------------------------
 * This function uses DFS to search all possible plan gotten from courselist.
 * All valid plans will be recorded into the parameter outputPlans.
 */
void checkPlan(vector<Courses> & courseList, map<string, int> & priorityList,
               unsigned int presentCourse, Plan & autoPlan,
               vector<Plan> & outputPlans);

/* Method: outputMap(vector<Plan> & outputPlans, map<string, int> & priorityList)
 * Usage: map<string, vector<string>> oMap = outputMap(outputPlans, priorityList)
 * ------------------------------------------------------------------------------
 * This method is used only in automaticArrangement.
 * This method transforms the Plan-type plans into a map-type object, which is
 * used in the main.cpp for later steps.
 */
map<string, vector<string>> outputMap(vector<Plan> & outputPlans, map<string, int> & priorityList);

/* Method: automaticArrangement(const vector<string> & courses, MainArealist & MAL)
 * Usage: map<string, vector<string>> oMap = automaticArrangement(courses, MAL)
 * ----------------------------------------------------------------------------
 * This method is the connector to the main.cpp.
 * It will be called in main.cpp to automatic arrangement the chosen courses.
 */
map<string, vector<string>> automaticArrangement(const vector<string> & courses, MainArealist & MAL);

/* Print Process: printList(course_auto & ui, map<string, vector<string>> & outputMap);
 *                printListContent(course_auto & ui, vector<string> & vstring);
 *                printSchedual(course_auto & ui, vector<string> & vstring);
 * -------------------------------------------------------
 * These methods are used to print the plan list onto UI.
 */
void printList(course_auto & ui, map<string, vector<string>> & outputMap);
void printListContent(course_auto & ui, vector<string> & vstring);
void printSchedual(course_auto & ui, vector<string> & vstring, MainArealist & MAL);
void printListContentAndSchedual(course_auto & ui, vector<string> & vstring, MainArealist & MAL);

#endif // AUTOARRANGEMENT_H
