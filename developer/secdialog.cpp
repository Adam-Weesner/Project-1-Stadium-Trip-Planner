#include "secdialog.h"
#include "ui_secdialog.h"

/**
 * @brief SecDialog::SecDialog
 * @param parent
 */
SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

/**
 * @brief SecDialog::~SecDialog
 * Destructor that hides UI
 */
SecDialog::~SecDialog()
{
    delete ui;
}

/**
 * @brief SecDialog::on_pushButton_clicked
 * Processing for opening the administrator menu. If the password is correct,
 * it will display the administrator menu.
 */
void SecDialog::on_pushButton_clicked()
{
    QString myPass; //CALC - correct password

    //PROCESSING - sets correct password
    myPass = "password";

    //PROCESSING - if password is correct, closes dialog box
    if(ui->lineEdit->text() == myPass)
    {
        SecDialog::set_text(myPass);
        SecDialog::close();
    }
    else
    {
        ui->label->show();
        ui->lineEdit->clear();
    }
}

/**
 * @brief SecDialog::get_text
 * Gets the string for the password input.
 * @return
 */
QString SecDialog::get_text()
{
    return myString;
}

/**
 * @brief SecDialog::set_text
 * Tests input string to see if it's the password.
 * @param someString
 */
void SecDialog::set_text(QString someString)
{
    myString = someString;
}
