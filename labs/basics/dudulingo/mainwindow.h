#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QMenuBar>
#include <QLabel>
#include <QPushButton>
#include <QSplitter>
#include <QTextEdit>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QApplication>
#include <QSql>
#include <QSqlQuery>
#include <QString>
#include <QSqlError>
#include <QDebug>
#include <QRadioButton>
#include <QProgressBar>
#include <QTimer>
#include <QShortcut>
#include <random>
#include <set>
#include <algorithm>
#include "vectors.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showSentence();
    void showQuestion();
    void checkTranslation();
    void checkGrammar();
    void checkNotRight();
    void startTimer();
    void onTimeout();
    void showHelp();
    void setIndex0();
    void setIndex1();
    void setIndex2();
    void updateProfile();

private:
    QWidget *centralWidget;
    QSqlDatabase db;
    QPushButton *grammar;
    QLabel *sent;
    QPushButton *translate;
    QPushButton *submit;
    QPushButton *submit1;
    QPushButton *profile;
    QLabel *sentenceLabel;
    int currentSentenceId;
    QString currentCorrectAnswer;
    QTextEdit *textEdit;
    QPushButton *checkButton;
    QSqlQuery createQuery;
    QSqlQuery countQuery;
    QString random_element;
    QString random_element1;
    size_t random_index;
    size_t random_index1;
    QLabel *result;
    QLabel *result1;
    int totalScore = 0;
    int nowScore = 0;
    QLabel *labelScore;
    std::set<size_t> indexes;
    std::vector<size_t> out_index;
    std::vector<size_t> out_index1;
    int count = 0;
    int count1 = 0;
    int notright = 7;
    QRadioButton *radioButtonA;
    QRadioButton *radioButtonB;
    QRadioButton *radioButtonC;
    QRadioButton *radioButtonD;
    QProgressBar *progressBar;
    QProgressBar *progressBar1;
    QProgressBar *progressBar2;
    QProgressBar *progressBar3;
    QLabel *question;
    QTimer *timer;
    int timeLeft = 179;
    QLabel *timerLabel;
    bool timerFlag = false;
    QStackedWidget *stack;
    QString message;
    QString onemoremessage;
    QString twomoremessage;
    QString threemoremessage;
    QShortcut *shortcut;
    QLabel *label2;
};
#endif // MAINWINDOW_H
