#ifndef DATABASESERVICE_HPP
#define DATABASESERVICE_HPP

#include <QWidget>
#include <QSqlTableModel>

QT_FORWARD_DECLARE_CLASS(QSqlError)

QT_BEGIN_NAMESPACE
namespace Ui {
    class DatabaseService;
}
QT_END_NAMESPACE

class DatabaseService {
    //Q_OBJECT
public:
    DatabaseService(QWidget *parent = nullptr);
    ~DatabaseService();

    QSqlError addConnection(const QString &driver, const &databaseName,
                            const QString &host, const QString &user,
                            const QString &password, int port);
};

#endif
