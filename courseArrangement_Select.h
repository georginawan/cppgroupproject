#ifndef COURSEARRANGEMENT_H
#define COURSEARRANGEMENT_H

#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class courseArrangement_select;
}

class courseArrangement_select : public QDialog
{
    Q_OBJECT

public:
    explicit courseArrangement_select(QWidget *parent = nullptr);
    ~courseArrangement_select();

public slots:
    void infoToCard(string code, string time, string location, string teacher);

private slots:

    void on_comboSelect_currentTextChanged(const QString &arg1);

    void on_courseCheck_clicked(bool checked);

private:
    Ui::courseArrangement_select *ui;
};

#endif // COURSEARRANGEMENT_H
