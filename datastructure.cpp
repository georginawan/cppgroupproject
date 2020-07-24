/*
 * File： datastructure.cpp
 * ------------------------
 * This file implements three classes- the classes, Courses and MainArealist in our datastructure.
 */


#include "datastructure.h"


//* class: classes*//

/*
 * Implementation notes: classes constuctor
 * ----------------------------------------
 */

classes:: classes() {
}

classes:: ~classes() {
}

/*
 * Implementation notes: classes:: Getters
 * ----------------------------------------
 * The getters return the value of the corresponding instance variables.
 */

string classes:: getname() {
    return classname;
}

vector<string> classes:: getinfo(){
    return classinfo;
}

/*
 * Implementation notes: classes:: Setter
 * ----------------------------------------
 * For the client to add more information of the course,like the
 * reference number of piority.
 */

void classes:: set(string y1, vector<string> & y2){
    classname = y1;
    classinfo = y2;
}



//* class: Courses*//

/*
 * Implementation notes: Courses constuctor
 * ----------------------------------------
 */
Courses:: Courses(){
}

Courses:: ~Courses(){
}

/*
 * Implementation notes: Courses:: Getters
 * ----------------------------------------
 * The getters return the value of the corresponding instance variables.
 */

string Courses::  getname(){
    return courseName;
}

vector<classes> Courses::  getinfo() {
    return courseInfo;
}

/*
 * Implementation notes: Courses:: Setter
 * ----------------------------------------
 * For the client to add more information of the course,like the
 * reference number of piority.
 */

void Courses:: set(string y1, vector<classes> & y2){
    courseName = y1;
    courseInfo = y2;
}



//* class: MainArealist*//
/*
 * Implementation notes: MainArealist:: constuctor
 * ----------------------------------------
 */
MainArealist:: MainArealist(){
    map <string, vector<Courses>> MainArealist0;
}

MainArealist:: ~MainArealist(){
    MainArealist0.clear();
}

/*
 * Implementation notes: MainArealist:: Getters
 * ----------------------------------------
 * The getters return the value of the corresponding instance variables.
 */

vector<string> MainArealist::getnamelist(){
    vector<string> a;
    map <string, vector<Courses>>::iterator it;

    it = MainArealist0.begin();

    while(it != MainArealist0.end()) {
        a.push_back(it->first);
        it ++;
    }
    return a;
}

vector<Courses> MainArealist::getinfo(string AreaName){

    return MainArealist0[AreaName];
    //before use this function,
    //something like(if (MainArealist0.find(AreaName) != MainArealist0.end() ) should be used
    //to see if the AreaName is valid.
}

void MainArealist::set(string y1, vector<Courses> & y2){
    map<string, vector<Courses>>::iterator it;
    it = MainArealist0.find(y1);
    if(it != MainArealist0.end()) {
        MainArealist0.erase(it);
        MainArealist0.insert(make_pair(y1, y2));
    } else {
        MainArealist0.insert(make_pair(y1, y2));
    }
}


void MainArealist::AddInfo(string MainArea,Courses a){
    MainlistInfo = MainArealist0[MainArea];
    MainlistInfo.push_back(a);
    MainArealist0[MainArea] = MainlistInfo;
}

/*
 * Implementation notes: Plan constuctor
 * ----------------------------------------
 */

Plan:: Plan (){
}

Plan:: ~Plan (){
}

/*
 * Implementation notes: Plan:: Getters
 * ----------------------------------------
 * The getters return the value of the corresponding instance variables.
 */

string Plan::getname(){
    return plan0;
}

vector<Courses> Plan::getinfo() {
    return plan0Info;
}

void Plan::setname(string name) {
    plan0 = name;

}

void Plan::setInfo(vector<Courses> courselist) {
    plan0Info = courselist;
}
