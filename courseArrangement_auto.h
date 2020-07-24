#ifndef COURSARRANGEMENT_AUTO_H
#define COURSARRANGEMENT_AUTO_H

#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class courseArrangement_auto;
}

class courseArrangement_auto : public QDialog
{
    Q_OBJECT

public:
    explicit courseArrangement_auto(QWidget *parent = nullptr);
    ~courseArrangement_auto();

public slots:
    void courseToShow(string course);
    void dragCourse(string course, int col, int row);
    void setOption(string option);

private slots:
    void on_courseSelect_clicked(bool checked);

private:
    Ui::courseArrangement_auto *ui;
};

#endif // COURSARRANGEMENT_AUTO_H
