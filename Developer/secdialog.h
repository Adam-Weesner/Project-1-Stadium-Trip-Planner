#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief SecDialog
     * -constructor
     * @param parent
     */
    explicit SecDialog(QWidget *parent = 0);

    /**
     * destructor
     */
    ~SecDialog();

    /**
     * @brief get_text
     * returns text in line edit
     * @return
     */
    QString get_text();

    /**
     * @brief set_text
     * - sets text in line edit with parameter passed in
     * @param someString
     */
    void set_text(QString someString);

private slots:

    /**
     * @brief on_pushButton_clicked
     * - closed window after user enters password if correct,
     *   stays open if not correct
     */
    void on_pushButton_clicked();

private:
    Ui::SecDialog *ui;      ///< pointer to gui
    QString        myString;///< stores user input
};

#endif // SECDIALOG_H
