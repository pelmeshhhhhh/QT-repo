#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    centralWidget = new QWidget();
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    QVBoxLayout *buttonLayout = new QVBoxLayout();

    centralWidget->setLayout(mainLayout);

    grammar = new QPushButton("Grammar");
    translate = new QPushButton("Translate");
    profile = new QPushButton("Profile");
    labelScore = new QLabel("0");

    stack = new QStackedWidget;
    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;
    QWidget *page3 = new QWidget;

    message =
        "<h3>Времена в английском языке</h3>"
        "<b>1. Simple (Indefinite) – Простые</b><br>"
        "• <i>Present Simple</i> (I work) – привычки, факты.<br>"
        "• <i>Past Simple</i> (I worked) – завершённые действия в прошлом.<br>"
        "• <i>Future Simple</i> (I will work) – будущие действия, обещания.<br><br>"

        "<b>2. Continuous (Progressive) – Длительные</b><br>"
        "• <i>Present Continuous</i> (I am working) – действие сейчас.<br>"
        "• <i>Past Continuous</i> (I was working) – процесс в прошлом.<br>"
        "• <i>Future Continuous</i> (I will be working) – процесс в будущем."

        "<b>3. Perfect – Завершённые</b><br>"
        "• <i>Present Perfect</i> (I have worked) – результат к настоящему моменту.<br>"
        "• <i>Past Perfect</i> (I had worked) – действие завершилось до другого в прошлом.<br>"
        "• <i>Future Perfect</i> (I will have worked) – завершится к определённому моменту в будущем.<br><br>"

        "<b>4. Perfect Continuous – Длительные завершённые</b><br>"
        "• <i>Present Perfect Continuous</i> (I have been working) – действие длилось и ещё важно сейчас.<br>"
        "• <i>Past Perfect Continuous</i> (I had been working) – процесс до другого момента в прошлом.<br>"
        "• <i>Future Perfect Continuous</i> (I will have been working) – процесс до момента в будущем.";

    onemoremessage =
        "<h3>Артикли в английском языке</h3>"

        "<b>1. Неопределённый артикль: a / an</b><br>"
        "<b>a</b> + слово, начинающееся с согласного звука:<br>"
        "• <i>a book, a university</i> (т.к. \"university\" читается как [juːnɪˈvɜːrsɪti] — начинается с звука \"й\")<br><br>"

        "<b>an</b> + слово, начинающееся с гласного звука:<br>"
        "• <i>an apple, an hour</i> (т.к. \"hour\" читается [ˈaʊər] — \"h\" не произносится)<br><br>"

        "<b>Употребляется:</b><br>"
        "• Когда предмет упоминается <i>впервые</i> (<i>I saw a cat</i>).<br>"
        "• Когда речь о <i>любом</i> предмете из класса (<i>Give me a pen</i>).<br><br>"

        "<b>2. Определённый артикль: the</b><br>"
        "<b>Употребляется:</b><br>"
        "• Когда предмет <i>уже известен</i> (<i>The cat is black</i> — та самая кошка).<br>"
        "• С <i>уникальными</i> объектами (<i>the Sun, the Eiffel Tower</i>).<br>"
        "• С <i>суперлативом</i> (<i>the best movie</i>).<br>"
        "• С <i>музыкальными инструментами</i> (<i>play the piano</i>).<br><br>"

        "<b>3. Нулевой артикль (отсутствие артикля)</b><br>"
        "<b>Когда не ставится:</b><br>"
        "• <i>Множественное число</i> (<i>Cats are cute</i>).<br>"
        "• <i>Неисчисляемые существительные</i> (<i>Love is beautiful</i>).<br>"
        "• <i>Имена собственные</i> (<i>John, Paris</i>).<br>"
        "• <i>Общие понятия</i> (<i>Life is short</i>).<br><br>"

        "<b>Примеры:</b><br>"
        "• <i>I bought <b>a</b> car. <b>The</b> car is red.</i><br>"
        "• <i>She is <b>an</b> artist. She plays <b>the</b> guitar.</i><br>"
        "• <i><b>Ø</b> Coffee is good for you.</i>";

    twomoremessage =
        "<h3>Предлоги в английском языке</h3>"

        "<b>1. Предлоги времени:</b><br>"
        "• <i>at</i> - для точного времени (at 5 o'clock)<br>"
        "• <i>on</i> - для дней и дат (on Monday, on June 5th)<br>"
        "• <i>in</i> - для месяцев, лет, времен года (in July, in 2023, in summer)<br>"
        "• <i>for</i> - продолжительность (for two hours)<br>"
        "• <i>since</i> - с какого-то момента (since 2010)<br><br>"

        "<b>2. Предлоги места:</b><br>"
        "• <i>at</i> - конкретная точка (at the door)<br>"
        "• <i>in</i> - внутри (in the room)<br>"
        "• <i>on</i> - на поверхности (on the table)<br>"
        "• <i>under</i> - под (under the bed)<br>"
        "• <i>between</i> - между (between two buildings)<br><br>"

        "<b>3. Предлоги направления:</b><br>"
        "• <i>to</i> - направление к (go to school)<br>"
        "• <i>into</i> - движение внутрь (go into the house)<br>"
        "• <i>out of</i> - движение изнутри (get out of the car)<br>"
        "• <i>through</i> - сквозь (walk through the park)<br><br>"

        "<b>4. Другие важные предлоги:</b><br>"
        "• <i>with</i> - с (со значением совместности)<br>"
        "• <i>without</i> - без<br>"
        "• <i>by</i> - кем-то/чем-то (книга written by Pushkin)<br>"
        "• <i>about</i> - о (рассказ about animals)<br><br>"

        "<b>Примеры:</b><br>"
        "• <i>We meet <b>at</b> the cafe <b>on</b> Fridays.</i><br>"
        "• <i>The keys are <b>on</b> the table <b>in</b> the kitchen.</i><br>"
        "• <i>She walked <b>through</b> the door <b>into</b> the garden.</i>";

    threemoremessage =
        "<h3>Союзы и местоимения в английском языке</h3>"

        "<h4>1. Союзы (Conjunctions)</h4>"
        "<b>a) Сочинительные союзы:</b><br>"
        "• <i>and</i> - и<br>"
        "• <i>but</i> - но<br>"
        "• <i>or</i> - или<br>"
        "• <i>so</i> - поэтому<br>"
        "• <i>for</i> - так как<br>"
        "• <i>yet</i> - тем не менее<br><br>"

        "<b>b) Подчинительные союзы:</b><br>"
        "• <i>because</i> - потому что<br>"
        "• <i>if</i> - если<br>"
        "• <i>when</i> - когда<br>"
        "• <i>although</i> - хотя<br>"
        "• <i>while</i> - в то время как<br>"
        "• <i>since</i> - с тех пор как<br><br>"
        "<h4>2. Местоимения (Pronouns)</h4>"
        "<b>a) Личные местоимения:</b><br>"
        "• <i>I, you, he, she, it, we, they</i><br><br>"

        "<b>b) Притяжательные:</b><br>"
        "• <i>my, your, his, her, its, our, their</i><br>"
        "• <i>mine, yours, his, hers, ours, theirs</i><br><br>"

        "<b>c) Возвратные:</b><br>"
        "• <i>myself, yourself, himself, herself, itself, ourselves, yourselves, themselves</i><br><br>"

        "<b>d) Указательные:</b><br>"
        "• <i>this, that, these, those</i><br><br>"

        "<b>e) Вопросительные:</b><br>"
        "• <i>who, what, which, whose, whom</i><br><br>";

    // ===== Страница 1 (Grammar) =====
    QVBoxLayout *page1Layout = new QVBoxLayout;
    progressBar1 = new QProgressBar();
    progressBar1->setMinimum(0);
    progressBar1->setMaximum(5);
    page1Layout->addWidget(progressBar1);
    page1Layout->addWidget(new QLabel("Выбери правильный варинат ответа"));
    question = new QLabel("Question");
    radioButtonA = new QRadioButton("A");
    radioButtonB = new QRadioButton("B");
    radioButtonC = new QRadioButton("C");
    radioButtonD = new QRadioButton("D");
    submit1 = new QPushButton("Submit");
    result1 = new QLabel("Result here");
    page1Layout->addWidget(question);
    page1Layout->addWidget(radioButtonA);
    page1Layout->addWidget(radioButtonB);
    page1Layout->addWidget(radioButtonC);
    page1Layout->addWidget(radioButtonD);
    page1Layout->addWidget(submit1);
    page1Layout->addWidget(result1);
    page1->setLayout(page1Layout);

    // ===== Страница 2 (Translate) =====
    QVBoxLayout *page2Layout = new QVBoxLayout();
    progressBar = new QProgressBar();
    progressBar->setMinimum(0);
    progressBar->setMaximum(5);
    page2Layout->addWidget(progressBar);
    page2Layout->addWidget(new QLabel("Переведи предложение"));
    sent = new QLabel("Sentence");
    result = new QLabel("Result here");
    page2Layout->addWidget(sent);
    textEdit = new QTextEdit();
    textEdit->setPlaceholderText("Введите ваш перевод здесь...");
    sentenceLabel = new QLabel;
    sentenceLabel->setWordWrap(true);
    sentenceLabel->setStyleSheet("font-size: 16px; margin-bottom: 20px;");
    page2Layout->addWidget(textEdit);
    submit = new QPushButton("Submit");
    checkButton = new QPushButton("Check");
    page2Layout->addWidget(submit);
    page2Layout->addWidget(checkButton);
    page2Layout->addWidget(result);
    page2->setLayout(page2Layout);

    // ===== Страница 3 (Profile) =====
    QVBoxLayout *page3Layout = new QVBoxLayout;
    QLabel *welcomeLabel = new QLabel("Добро пожаловать в Дудулинго!");
    QFont font = welcomeLabel->font();
    font.setPointSize(20);
    font.setBold(true);
    welcomeLabel->setFont(font);
    welcomeLabel->setStyleSheet("color: green;");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    page3Layout->addWidget(welcomeLabel);
    QLabel *label1 = new QLabel("Твои баллы:");
    QFont font1 = label1->font();
    font1.setPointSize(15);
    label1->setFont(font1);
    label1->setStyleSheet("color: white;");
    label1->setAlignment(Qt::AlignCenter);
    page3Layout->addWidget(label1);
    label2 = new QLabel("0");
    QFont font2 = welcomeLabel->font();
    font2.setPointSize(22);
    font2.setBold(true);
    label2->setFont(font2);
    label2->setStyleSheet("color: white;");
    label2->setAlignment(Qt::AlignCenter);
    page3Layout->addWidget(label2);
    progressBar2 = new QProgressBar();
    progressBar2->setMinimum(0);
    progressBar2->setMaximum(5);
    progressBar3 = new QProgressBar();
    progressBar3->setMinimum(0);
    progressBar3->setMaximum(5);
    page3Layout->addWidget(new QLabel("Grammar"));
    page3Layout->addWidget(progressBar2);
    page3Layout->addWidget(new QLabel("Translation"));
    page3Layout->addWidget(progressBar3);

    page3->setLayout(page3Layout);

    stack->addWidget(page1);
    stack->addWidget(page2);
    stack->addWidget(page3);

    timer = new QTimer();
    timerLabel = new QLabel("3 : 00");

    QObject::connect(grammar, &QPushButton::clicked, this, &MainWindow::setIndex0);
    QObject::connect(grammar, &QPushButton::clicked, this, &MainWindow::showQuestion);
    QObject::connect(translate, &QPushButton::clicked, this, &MainWindow::setIndex1);
    QObject::connect(translate, &QPushButton::clicked, this, &MainWindow::showSentence);
    QObject::connect(submit, &QPushButton::clicked, this, &MainWindow::checkTranslation);
    QObject::connect(submit1, &QPushButton::clicked, this, &MainWindow::checkGrammar);
    QObject::connect(submit, &QPushButton::clicked, this, &MainWindow::checkNotRight);
    QObject::connect(submit1, &QPushButton::clicked, this, &MainWindow::checkNotRight);
    QObject::connect(profile, &QPushButton::clicked, this, &MainWindow::setIndex2);
    QObject::connect(profile, &QPushButton::clicked, this, &MainWindow::updateProfile);
    connect(submit, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(submit1, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimeout);
    shortcut = new QShortcut(QKeySequence("H"), this);
    shortcut->setContext(Qt::ApplicationShortcut);
    QObject::connect(shortcut, &QShortcut::activated, this, &MainWindow::showHelp);

    buttonLayout->addWidget(timerLabel);
    buttonLayout->addWidget(labelScore);
    buttonLayout->addWidget(grammar);
    buttonLayout->addWidget(translate);
    buttonLayout->addWidget(profile);

    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(stack, 1);

    std::vector<size_t> indices(eng.size());
    std::iota(indices.begin(), indices.end(), 0);

    out_index.resize(6);

    std::random_device rd;
    std::mt19937 gen(rd());

    std::sample(indices.begin(), indices.end(), out_index.begin(), 6, gen);

    random_index = out_index[0];
    random_element = eng[random_index];
    sent->setText(random_element);

    std::vector<size_t> ind(ques.size());
    std::iota(ind.begin(), ind.end(), 0);

    out_index1.resize(5);

    std::random_device rd1;
    std::mt19937 gen1(rd1());

    std::sample(ind.begin(), ind.end(), out_index1.begin(), 5, gen1);

    random_index1 = out_index1[0];
    random_element1 = ques[random_index1];

    buttonLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(10);

    stack->setCurrentIndex(2);

    this->setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    db.close(); // Close the specific database connection
    db = QSqlDatabase(); // Reset the database object (optional but good practice)
    QSqlDatabase::removeDatabase("QSQLITE"); // Remove the database connection from the list
}

void MainWindow::showSentence() {
    qDebug() << "Selected indices:";
    for (size_t idx : out_index) {
        qDebug() << idx << ":" << eng[idx] << rus[idx];
    }

    sent->setText(random_element);
}

void MainWindow::checkTranslation() {
    if (rus[random_index] == textEdit->toPlainText()) {
        if (count < 4) {
            count++;
            progressBar->setValue(count);
            progressBar2->setValue(count);
            result->setText("Хорош, слоняра, +10 очков");
            totalScore += 10;
            nowScore += 10;
            labelScore->setText(QString::number(totalScore));
            textEdit->clear();
            random_index = out_index[count - 1];
            random_element = eng[random_index];
            sent->setText(random_element);
        } else if (count == 4) {
            count++;
            progressBar->setValue(count);
            progressBar2->setValue(count);
            result->setText("Молодец, со всем справился");
            nowScore = 0;
            totalScore += 10;
            labelScore->setText(QString::number(totalScore));
            return;
        } else {
            return;
        }
    } else {
        result->setText("Неправильно :(");
        notright--;
    }
}

void MainWindow::showQuestion() {
    question->setText(random_element1);
    radioButtonA->setText(answer[random_index1][0]);
    radioButtonB->setText(answer[random_index1][1]);
    radioButtonC->setText(answer[random_index1][2]);
    radioButtonD->setText(answer[random_index1][3]);
    // progressBar1->setValue(0);
    // progressBar3->setValue(0);
    // result1->setText(" ");
    // count1 = 0;
}

void MainWindow::checkGrammar() {
    if ((variants[random_index1] == 1 && radioButtonA->isChecked()) ||
        (variants[random_index1] == 2 && radioButtonB->isChecked()) ||
        (variants[random_index1] == 3 && radioButtonC->isChecked()) ||
        (variants[random_index1] == 4 && radioButtonD->isChecked())) {
        if (count1 < 4) {
            result1->setText("Так держать!");
            count1 = count1 + 1;
            progressBar1->setValue(count1);
            progressBar3->setValue(count1);
            random_index1 = out_index[count1];
            question->setText(ques[random_index1]);
            radioButtonA->setText(answer[random_index1][0]);
            radioButtonB->setText(answer[random_index1][1]);
            radioButtonC->setText(answer[random_index1][2]);
            radioButtonD->setText(answer[random_index1][3]);
            totalScore += 10;
            labelScore->setText(QString::number(totalScore));
        } else if (count1 == 4) {
            count1 = count1 + 1;
            progressBar1->setValue(count1);
            progressBar3->setValue(count1);
            result1->setText("Ураааааа, всё правильно!");
            nowScore += 10;
            totalScore += 10;
            labelScore->setText(QString::number(totalScore));
            return;
        } else {
            return;
        }
    } else {
        notright--;
        result1->setText("Попробуй ещё раз");
    }
}

void MainWindow::checkNotRight() {
    if (notright < 1) {
        QMessageBox::critical(centralWidget, "Ошибка", "Слишком много неправильных ответов!");
        labelScore->setText(0);
        totalScore = 0;
        nowScore = 0;
        timerLabel->setText("0 : 00");
        timer->stop();
    }
}

void MainWindow::startTimer() {
    if (timerFlag == 0) {
        qDebug() << "1";
        timerFlag = true;
        qDebug() << "1";
        timer->start(1000);
    }
}

void MainWindow::onTimeout() {
    if (timeLeft > 0) {
        int minutes = timeLeft / 60;
        int seconds = timeLeft % 60;
        timerLabel->setText(QString::number(minutes) + " : " + QString::number(seconds).rightJustified(2, '0'));
        timeLeft--;
    } else {
        timer->stop();
        timerLabel->setText("Время вышло!");
        QMessageBox::critical(centralWidget, "Упс!", "Время вышло :)");
    }
}

void MainWindow::showHelp() {
    if (stack->currentIndex() == 0) {
        if (out_index[count1] < 15 || (out_index[count1] < 50 && out_index[count1] > 44)) {
            QMessageBox::information(centralWidget, "Подсказка", message);
        } else if (out_index[count1] < 20 && out_index[count1] > 14) {
            QMessageBox::information(centralWidget, "Подсказка", onemoremessage);
        } else if (out_index[count1] < 25 && out_index[count1] > 19) {
            QMessageBox::information(centralWidget, "Подсказка", twomoremessage);
        } else {
            QMessageBox::information(centralWidget, "Подсказка", threemoremessage);
        }
    } else {
        return;
    }
    return;
}

void MainWindow::setIndex0() {
    stack->setCurrentIndex(0);
}

void MainWindow::setIndex1() {
    stack->setCurrentIndex(1);
}

void MainWindow::setIndex2() {
    stack->setCurrentIndex(2);
}

void MainWindow::updateProfile() {
    label2->setText(QString::number(totalScore));
}
