/* This file defines the data structure used in our program.
 * which includes class MainAreas, class courses and class classes.
 */

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE

#include <map>
#include <vector>
#include <cstring>
using namespace std;

class classes {
public:

/*
 * Constructor: classes
 * Usage: classes class1(string x1, vector<string> x2);
 * --------------------------------------------
 * Create a classes object.
 */

    classes();

/*
 * Destructor: ~classes
 * Usage: (usually implicit);
 * --------------------------
 */

    ~classes();

/*
 * Method: get
 * Usage: string x1 = class1.getname()
 *        vector<string> x2 = class1.getinfo();
 * ------------------------------------
 * These method return the section name and further information of a class.
 */

    string getname();
    vector<string> getinfo();


/*
 * Method: set
 * Usage: class1.set(string y1, vector<string> y2);
 * ----------------------------------------
 * Set the name and the infomation of the class object.
 */

    void set(string y1, vector<string> & y2);


/*Instant Variable*/
    string classname;
    vector<string> classinfo;
};


class Courses {
public:

/*
 * Constructor: Courses
 * Usage: Courses course1(string x1,  vector<classes> x2);
 * -----------------------------------------------
 * Create a Courses object.
 */

    Courses();

/*
 * Destructor: ~Courses
 * Usage: (usually implicit);
 * --------------------------
 */

    ~Courses();

/*
 * Method: get
 * Usage: string x1 = course1.getname()
 *        vector<string> x2 = course1.getinfo();
 * ------------------------------------
 * These method return the section name and further information of a class.
 */

    string getname();
    vector<classes> getinfo();


/*
 * Method: set
 * Usage: course1.set(string y1, vector<classes> y2);
 * -------------------------------------------------
 * This method set the name and further content of the course.
 */
    void set(string y1, vector<classes> & y2);




/*Instant Variable*/

    string courseName;
    vector<classes> courseInfo;

};


class MainArealist {
public:

/*
 * Constructor: MainArealist
 * Usage: MainArealist MainArealist1;
 * --------------------------------------------
 * Create a MainArealist object.
 */

    MainArealist(); // ( string x1, vector<Courses> & c1) in plan.h

/*
 * Destructor: ~MainArea
 * Usage: (usually implicit);
 * --------------------------
 *
 */

    ~MainArealist();

/*
 * Method: get
 * Usage: vector<string> x1 = MainArealist1.getnamelist()
 *        vector<Courses> x2 = MainArealist1.getinfo(string AreaName);
 * ------------------------------------
 * These method return the list of MainArea names and further information of a mainarea.
 */

    vector<string> getnamelist();
    vector<Courses> getinfo(string AreaName);


/*
 * Method: setter
 * Usage: ACT.set(string y1, vector<Courses> y2);
 * ----------------------------------------
 * Set the name and the infomation of the MainArea object.
 */

    void set(string y1, vector<Courses> & y2);



/*
 * Method: AddInfo
 * Usage: course1.AddInfo(Courses a);
 * ---------------------------------
 * Add one Course to the vector.
 */

    void AddInfo(string MainArea,Courses a);



/*Instant Variable*/

    map <string, vector<Courses>> MainArealist0;
    vector<Courses> MainlistInfo;
    string MainAreaName;
};


class Plan {
public:

/*
 * Constructor: Plan
 * Usage: Plan P1(string x1, vector<Courses> x2);
 * --------------------------------------------
 * Create a Plan object.
 */

    Plan ();


/*
 * Destructor: ~Plan
 * Usage: (usually implicit);
 * --------------------------
 *
 */

    ~Plan();

/*
 * Method: get
 * Usage: string x1 = P1.getname()
 *        vector x2 = P1.getinfo();
 * ------------------------------------
 * These method return the Plan name and further information of a Plan.
 */

    string getname();
    vector<Courses> getinfo();

/*
 * Method: set
 * ------------------------------------
 *
 */

    void setname(string name);
    void setInfo(vector<Courses> courselist);

private:

/*Instant Variable*/
    string plan0;
    vector<Courses> plan0Info;
};


#endif // DATASTRUCTURE_H
