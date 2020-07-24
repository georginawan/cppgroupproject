#ifndef COURSEARRANGEMENT_MANUAL_H
#define COURSEARRANGEMENT_MANUAL_H

#include <QDialog>
#include <string>
#include <map>
#include <vector>
using namespace std;

namespace Ui {
class courseArrangement_manual;
}

class courseArrangement_manual : public QDialog
{
    Q_OBJECT

public:
    explicit courseArrangement_manual(QWidget *parent = nullptr);
    ~courseArrangement_manual();

public slots:
    void dragCourse(string course, int col, int row);
    void setPlan(std::string plan, map<string, vector<int> > autoCourses);
    void setPlanList(vector<string> plan);

private:
    Ui::courseArrangement_manual *ui;
    vector<string> *coursesList;
};

#endif // COURSEARRANGEMENT_MANUAL_H
