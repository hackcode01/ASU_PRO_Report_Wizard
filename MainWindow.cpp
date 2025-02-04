#include "MainWindow.hpp"

#include "./ui_MainWindow.h"

#include <QtWidgets>
#include <QMenuBar>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QLabel>

MainWindow::MainWindow() {
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(topFiller);
    // layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    createActions();
    createMenus();

    QString message = tr("Контекстное меню доступно при нажатии правой кнопки мыши");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Мастер отчетов АСУ ПРО"));
    setMinimumSize(160, 160);
    resize(480, 320);
}

#ifndef QT_NO_CONTEXTMENU

void MainWindow::contextMenuEvent(QContextMenuEvent *event) {
    QMenu menu(this);
    menu.addAction(cutAct);
    menu.addAction(copyAct);
    menu.addAction(pasteAct);
    menu.exec(event->globalPos());
}

#endif

void MainWindow::newFile() {}

void MainWindow::open() {}

void MainWindow::save() {}

void MainWindow::print() {}

void MainWindow::undo() {}

void MainWindow::redo() {}

void MainWindow::cut() {}

void MainWindow::copy() {}

void MainWindow::paste() {}

void MainWindow::bold() {}

void MainWindow::italic() {}

void MainWindow::leftAlign() {}

void MainWindow::rightAlign() {}

void MainWindow::justify() {}

void MainWindow::center() {}

void MainWindow::setLineSpacing() {}

void MainWindow::setParagraphSpacing() {}

void MainWindow::about() {}

void MainWindow::aboutQt() {}

void MainWindow::createActions() {
    newAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew),
                         tr("&Новый"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Создать новый файл"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

    openAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen),
                          tr("&Открыть..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Открыть существующий файл"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    saveAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave),
                          tr("&Сохранить"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Сохранить документ на диске"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);

    printAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::DocumentPrint),
                           tr("&Печатать..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Распечатать документ на принтере"));
    connect(printAct, &QAction::triggered, this, &MainWindow::print);

    exitAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit),
                          tr("Выход"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Выйти из приложения"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    undoAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo),
                          tr("&Отменить"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Отменить последнюю операцию"));
    connect(undoAct, &QAction::triggered, this, &MainWindow::undo);

    redoAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::EditRedo),
                          tr("&Повторить"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Повторить последнюю операцию"));
    connect(redoAct, &QAction::triggered, this, &MainWindow::redo);

    cutAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::EditCut),
                         tr("&Вырезать"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Вырезать содержимое текущего выделения в буфер обмена"));
    connect(cutAct, &QAction::triggered, this, &MainWindow::cut);

    copyAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::EditCopy),
                          tr("&Копировать"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Копирование содержимого текущего выделения в буфер обмена"));
    connect(copyAct, &QAction::triggered, this, &MainWindow::copy);

    pasteAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::EditPaste),
                           tr("&Вставить"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Вставить содержимое буфера обмена в текущее выделение "));
    connect(pasteAct, &QAction::triggered, this, &MainWindow::paste);

    boldAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::FormatTextBold),
                          tr("&Полужирный"), this);
    boldAct->setCheckable(true);
    boldAct->setShortcut(QKeySequence::Bold);
    boldAct->setStatusTip(tr("Сделать текст жирным"));
    connect(boldAct, &QAction::triggered, this, &MainWindow::bold);

    QFont boldFont = boldAct->font();
    boldFont.setBold(true);
    boldAct->setFont(boldFont);

    italicAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::FormatTextItalic),
                            tr("&Курсив"), this);
    italicAct->setCheckable(true);
    italicAct->setShortcut(QKeySequence::Italic);
    italicAct->setStatusTip(tr("Сделать текст курсивом"));
    connect(italicAct, &QAction::triggered, this, &MainWindow::italic);

    QFont italicFont = italicAct->font();
    italicFont.setItalic(true);
    italicAct->setFont(italicFont);

    setLineSpacingAct = new QAction(tr("Установить &межстрочный интервал..."), this);
    setLineSpacingAct->setStatusTip(tr("Изменение интервала между строками абзаца"));
    connect(setLineSpacingAct, &QAction::triggered, this, &MainWindow::setLineSpacing);

    setParagraphSpacingAct = new QAction(tr("Установить &интервал между абзацами..."), this);
    setParagraphSpacingAct->setStatusTip(tr("Изменить интервал между абзацами"));
    connect(setParagraphSpacingAct, &QAction::triggered,
            this, &MainWindow::setParagraphSpacing);

    aboutAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout),
                           tr("&О программе"), this);
    aboutAct->setStatusTip(tr("Показать окно \'О приложении\'"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    aboutQtAct = new QAction(tr("О &Qt"), this);
    aboutQtAct->setStatusTip(tr("Показать окно \'О библиотеке Qt\'"));
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(aboutQtAct, &QAction::triggered, this, &MainWindow::aboutQt);

    leftAlignAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::FormatJustifyLeft),
                               tr("&Выравнивание по левому краю"), this);
    leftAlignAct->setCheckable(true);
    leftAlignAct->setShortcut(tr("Ctrl+L"));
    leftAlignAct->setStatusTip(tr("Выравнивание выделенного текста по левому краю"));
    connect(leftAlignAct, &QAction::triggered, this, &MainWindow::leftAlign);

    rightAlignAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::FormatJustifyRight),
                                tr("&Выравнивание по правому краю"), this);
    rightAlignAct->setCheckable(true);
    rightAlignAct->setShortcut(tr("Ctrl+R"));
    rightAlignAct->setStatusTip(tr("Выровнять выделенный текст по правому краю"));
    connect(rightAlignAct, &QAction::triggered, this, &MainWindow::rightAlign);

    justifyAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::FormatJustifyFill),
                             tr("&Уточнить"), this);
    justifyAct->setCheckable(true);
    justifyAct->setShortcut(tr("Ctrl+J"));
    justifyAct->setStatusTip(tr("Выровнять выделенный текст"));
    connect(justifyAct, &QAction::triggered, this, &MainWindow::justify);

    centerAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::FormatJustifyCenter),
                            tr("&По центру"), this);
    centerAct->setCheckable(true);
    centerAct->setShortcut(tr("Ctrl+E"));
    centerAct->setStatusTip(tr("Выровнять по центру"));
    connect(centerAct, &QAction::triggered, this, &MainWindow::center);

    alignmentGroup = new QActionGroup(this);
    alignmentGroup->addAction(leftAlignAct);
    alignmentGroup->addAction(rightAlignAct);
    alignmentGroup->addAction(justifyAct);
    alignmentGroup->addAction(centerAct);
    leftAlignAct->setChecked(true);
}


void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&Файл"));
    fileMenu->addAction(newAct);

    fileMenu->addAction(openAct);

    fileMenu->addAction(saveAct);
    fileMenu->addAction(printAct);

    fileMenu->addSeparator();

    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Редактировать"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Помощь"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    formatMenu = editMenu->addMenu(tr("&Формат"));
    formatMenu->addAction(boldAct);
    formatMenu->addAction(italicAct);
    formatMenu->addSeparator()->setText(tr("Выравнивание"));
    formatMenu->addAction(leftAlignAct);
    formatMenu->addAction(rightAlignAct);
    formatMenu->addAction(justifyAct);
    formatMenu->addAction(centerAct);
    formatMenu->addSeparator();
    formatMenu->addAction(setLineSpacingAct);
    formatMenu->addAction(setParagraphSpacingAct);
}
