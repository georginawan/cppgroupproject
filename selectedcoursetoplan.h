/* This file defines the functions related to the manual selection process.*/


#ifndef SELECTEDCOURSETOPLAN_H
#define SELECTEDCOURSETOPLAN_H

#include "classsearchsection.h"

/*
 * fuction: courses singleItem(Courses a)
 * -------------------
 * To divide the classes into the the single item like the combination of one lecture and one tutorial.
 * And return them in the form of "Courses".
 */

vector<Courses> singleItem(Courses a);

/*
 * fuction: bool timeConflict(Courses a,Courses b)
 * ------------------------------------------
 * To judge if the time is conflict betwwen two singleitems.
 */

bool timeConflict(Courses a, Courses b);


/*
 * Plan planConstruct(the input from GUI)
 * --------------------
 * For each selected courses, first divide it as singleItems(vector of Courses which containing only one combanation of lecture and tutorial),
 * then add the Courses which containing only one combanation of lecture and tutorial into the plan if their time is not conflict.
 */

vector<Plan> planConstruct(vector<string> selected);

void findPossiblePlan(vector<Courses> SelectedCoursesList, vector<Plan> & plan0);


#endif // SELECTEDCOURSETOPLAN_H
