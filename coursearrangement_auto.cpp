#include "QTableWidgetItem"
#include "QDialog"
#include "QTableWidget"
#include <string>
#include "courseArrangement_auto.h"
#include "ui_coursearrangement_auto.h"
using namespace std;

courseArrangement_auto::courseArrangement_auto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::courseArrangement_auto)
{
    ui->setupUi(this);
}

courseArrangement_auto::~courseArrangement_auto()
{
    delete ui;
}

void courseArrangement_auto::courseToShow(string course)
{
    QCheckBox *courseCheck = new QCheckBox(QString::fromStdString(course));
}

void courseArrangement_auto::dragCourse(string course, int col, int row)
{
    QTableWidgetItem *pCell = ui->cousePlanManual->item(row,col);
    pCell->setText(QString::fromStdString(course));
}

void courseArrangement_auto::setOption(string option)
{
    QRadioButton *optionPlan = new QRadioButton;
    optionPlan->setText(QString::fromStdString(option));
}
