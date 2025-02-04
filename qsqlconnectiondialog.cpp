#include "qsqlconnectiondialog.h"
#include <ui_qsqlconnectiondialog.h>

#include <QCheckBox>
#include <QMessageBox>
#include <QPushButton>
#include <QSqlDatabase>

QSqlConnectionDialog::QSqlConnectionDialog(QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::QSqlConnectionDialogUi)
{
    m_ui->setupUi(this);

    setWindowTitle(tr("Подключение"));

    QStringList drivers = QSqlDatabase::drivers();

    if (!drivers.contains("QSQLITE"))
        m_ui->databaseCheckBox->setEnabled(false);

    m_ui->comboDriver->addItems(drivers);

    connect(m_ui->okButton, &QPushButton::clicked,
            this, &QSqlConnectionDialog::onOkButton);
    connect(m_ui->cancelButton, &QPushButton::clicked,
            this, &QSqlConnectionDialog::reject);
    connect(m_ui->databaseCheckBox, &QCheckBox::stateChanged,
            this, &QSqlConnectionDialog::onDbCheckBox);
}

QSqlConnectionDialog::~QSqlConnectionDialog()
{
    delete m_ui;
}

QString QSqlConnectionDialog::driverName() const
{
    return m_ui->comboDriver->currentText();
}

QString QSqlConnectionDialog::databaseName() const
{
    return m_ui->editDatabase->text();
}

QString QSqlConnectionDialog::userName() const
{
    return m_ui->editUsername->text();
}

QString QSqlConnectionDialog::password() const
{
    return m_ui->editPassword->text();
}

QString QSqlConnectionDialog::hostName() const
{
    return m_ui->editHostname->text();
}

int QSqlConnectionDialog::port() const
{
    return m_ui->portSpinBox->value();
}

bool QSqlConnectionDialog::useInMemoryDatabase() const
{
    return m_ui->databaseCheckBox->isChecked();
}

void QSqlConnectionDialog::onOkButton()
{
    if (m_ui->comboDriver->currentText().isEmpty()) {
        QMessageBox::information(this, tr("Не выбран драйвер базы данных"),
                                 tr("Пожалуйста, выберите драйвер базы данных"));
        m_ui->comboDriver->setFocus();
    } else {
        accept();
    }
}

void QSqlConnectionDialog::onDbCheckBox()
{
    m_ui->connectionGroupBox->setEnabled(!m_ui->databaseCheckBox->isChecked());
}
