#ifndef BODYMASSINDEXCALCULATORFORM_H
#define BODYMASSINDEXCALCULATORFORM_H

#include <QDialog>
class QLineEdit;
class QPushButton;
class QLCDNumber;
class BodyMassIndexCalculator;
class QMessageBox;

class BodyMassIndexCalculatorForm: public QDialog
{
    Q_OBJECT
public:
    explicit BodyMassIndexCalculatorForm(QWidget* parent = nullptr);
    ~BodyMassIndexCalculatorForm();
    void updateUserInterface(double r = 0.00, bool noError = true);
protected slots:
    void calculate();//Calculate the BMI.
    void clearAll();//Clear widgets.
private:
    //Widgets
    QLineEdit* m_Weight_Field;
    QLineEdit* m_Height_Field;
    QPushButton* m_Calculate_Button;
    QLCDNumber* m_BMI_Display;
    QPushButton* m_ClearAll_Button;
    QMessageBox* m_ErrorMessage;
    //The model instance(Aggregation as a pointer member).
    BodyMassIndexCalculator* m_Model;

};
#endif // BODYMASSINDEXCALCULATORFORM_H
