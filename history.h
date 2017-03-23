//CIS17B, Spring 2017 Jon LaRock and Greg Hanna

#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>

class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;

class history : public QDialog
{
    Q_OBJECT

public:
    history();

private:
    void createHorizontalGroupBox();
    void createGridGroupBox();

    enum { NumGridRows = 3, NumButtons = 4 };

    QGroupBox *horizontalGroupBox;
    QGroupBox *gridGroupBox;
    QLabel *labels[NumGridRows];
    QLineEdit *lineEdits[NumGridRows];
    QPushButton *buttons[NumButtons];
    QDialogButtonBox *buttonBox;

    QMenu *fileMenu;
    QAction *exitAction;
};
#endif // HISTORY_H
