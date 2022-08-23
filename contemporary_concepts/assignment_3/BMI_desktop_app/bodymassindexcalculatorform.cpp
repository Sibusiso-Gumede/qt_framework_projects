#include "bodymassindexcalculatorform.h"
#include "bodymassindexcalculator.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLCDNumber>
#include <QFormLayout>
#include <QMessageBox>

//The implementation of the BodyMassIndexCalculatorForm.

BodyMassIndexCalculatorForm::BodyMassIndexCalculatorForm(QWidget* parent)
    : QDialog(parent), m_Model(new BodyMassIndexCalculator)
{
    //Set the title of the window.
    setWindowTitle("BMI Calculator");

    //Create the widgets.
    m_Weight_Field = new QLineEdit;
    m_Height_Field = new QLineEdit;
    m_Calculate_Button = new QPushButton(tr("Calculate"));
    m_BMI_Display = new QLCDNumber;
    m_ClearAll_Button = new QPushButton(tr("Clear All"));
    m_ErrorMessage = new QMessageBox(this);

    //Customize the widgets.
    m_BMI_Display->setFrameStyle(QFrame::Panel | QFrame::Plain);
    m_BMI_Display->setLineWidth(1);
    m_ErrorMessage->setWindowTitle("Input error");
    m_ErrorMessage->setText("The values entered are invalid. Please enter valid numerical characters.");

    //The layout format.
    QFormLayout* form = new QFormLayout;
    form->deleteLater();//Since the "QFormLayout" object is not declared as a data member,
                        //it cannot be deleted through the destructor. Therefore,
                        //the deleteLater() function is used in this case.

    //Add the widgets to the layout format.
    form->addRow(tr("Enter weight in kilograms"), m_Weight_Field);
    form->addRow(tr("Enter height in meters"), m_Height_Field);
    form->addRow(tr(""), m_Calculate_Button);
    form->addRow(tr("BMI"), m_BMI_Display);
    form->addRow(tr(""), m_ClearAll_Button);

    //Reparent all the widgets with the current host object,
    //and ensure that the layout is successfully reparented.
    setLayout(form);
    Q_ASSERT((form->parent() == this) && (m_Weight_Field->parent() == this));

    //Connect the signals with the slots.
    connect(m_Calculate_Button, SIGNAL(clicked()), this, SLOT(calculate()));
    connect(m_ClearAll_Button, SIGNAL(clicked()), this, SLOT(clearAll()));
}

BodyMassIndexCalculatorForm::~BodyMassIndexCalculatorForm()
{
    //Clear up memory.
    delete m_Weight_Field;
    delete m_Height_Field;
    delete m_Calculate_Button;
    delete m_BMI_Display;
    delete m_ClearAll_Button;
    delete m_ErrorMessage;
    delete m_Model;
}

void BodyMassIndexCalculatorForm::updateUserInterface(double r, bool noError)
{
    //If there is an error then display a message,
    //else just display the result of the calculation on the LCD widget.
    if(!noError){
        if(m_ErrorMessage->exec() == QMessageBox::Ok){
            //When "Ok" is clicked; clear the invalid values in the
            //input widgets.
            clearAll();
        }
    }
    else
        m_BMI_Display->display(r);
}

void BodyMassIndexCalculatorForm::calculate()
{
    //Check if the values entered are valid numerical characters.
    //If both the values are valid; proceed to calculate and display
    //the result on the LCD widget.
    bool ok1, ok2;//flags
    double w, h, result = 0.00;
    w = m_Weight_Field->text().toDouble(&ok1);
    h = m_Height_Field->text().toDouble(&ok2);
    if(ok1 && ok2){
        result = m_Model->calculateBMI(w, h);
        updateUserInterface(result);
    }
    //else, the updateUserInterface function
    //will proceed to display an error message.
    else
        updateUserInterface(result, false);
}

void BodyMassIndexCalculatorForm::clearAll()
{
    //Reset the values in the input widgets.
    m_Weight_Field->clear();
    m_Height_Field->clear();
    m_BMI_Display->display(0);
}
