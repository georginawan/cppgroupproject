#include <string>
#include "QDialog"
#include "QListWidget"
#include "courseArrangement_select.h"
#include "ui_courseArrangement_select.h"
using namespace std;

courseArrangement_select::courseArrangement_select(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::courseArrangement_select)
{
    ui->setupUi(this);
}

courseArrangement_select::~courseArrangement_select()
{
    delete ui;
}

void courseArrangement_select::infoToCard(string code, string time, string location, string teacher)
{
    QCheckBox *checkSelect = new QCheckBox(QString::fromStdString(code));
    QLabel *labelTime = new QLabel;
    QLabel *labelLocation = new QLabel;
    QLabel *labelTeacher = new QLabel;
    labelTime->setText(QString::fromStdString(time));
    labelLocation->setText(QString::fromStdString(location));
    labelTeacher->setText(QString::fromStdString(teacher));
    QVBoxLayout *courseInfo = new QVBoxLayout;
    courseInfo->addWidget(labelTime);
    courseInfo->addWidget(labelLocation);
    courseInfo->addWidget(labelTeacher);
}

void courseArrangement_select::on_comboSelect_currentTextChanged(const QString &arg1)
{
    string searchItem = arg1.toStdString();

}

//void courseArrangement_select::on_courseCheck_clicked(bool checked)
//{
//    if (checked) ui->listPresentCourse->addItem();
//}
