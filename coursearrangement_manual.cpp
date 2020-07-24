#include "QDialog"
#include <string>
#include <map>
#include <vector>
#include "courseArrangement_manual.h"
#include "ui_coursearrangement_manual.h"
using namespace std;

courseArrangement_manual::courseArrangement_manual(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::courseArrangement_manual)
{
    ui->setupUi(this);
}

courseArrangement_manual::~courseArrangement_manual()
{
    delete ui;
}

void courseArrangement_manual::setPlan(string plan, map<string, vector<int> > autoCourses)
{
    QRadioButton *planName = new QRadioButton(QString::fromStdString(plan));

}

void courseArrangement_manual::setPlanList(vector<string> plan)
{
    ui->listWidget->clear();
    for (unsigned i = 0; i < plan.size(); i++) {
        ui->listWidget->addItem(QString::fromStdString(plan[i]));
    }
}
