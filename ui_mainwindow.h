/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *widgetSiteBody;
    QVBoxLayout *verticalLayout;
    QPushButton *btTEMPTopAd;
    QFrame *line_12;
    QStackedWidget *stackedWidget;
    QWidget *pageMain;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_4;
    QPushButton *btnTEMPLogo;
    QScrollArea *scrollAreaProducts;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelSortBy;
    QPushButton *btnTEMPRadioSort;
    QPushButton *btnTEMPLeftAd;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditSearch;
    QComboBox *comboBoxSearch;
    QPushButton *btnSearch;
    QFrame *line_6;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnTEMPCart;
    QFrame *line_5;
    QLabel *labelCart;
    QHBoxLayout *horizontalLayout_2;
    QFrame *line_7;
    QPushButton *btnTEMPUserImg;
    QLabel *labelUserLogIn;
    QFrame *line_8;
    QPushButton *btnSignUpMain;
    QFrame *line;
    QFrame *line_4;
    QFrame *line_3;
    QWidget *pageLogIn;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnTEMPLeftAd_3;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *labelWelcomeBack;
    QFormLayout *formLayout_2;
    QLabel *labelEmailLogin;
    QLabel *labelPasswordLogin;
    QLineEdit *lineEditLoginEmail;
    QLineEdit *lineEditLoginPassword;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnLogIn;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_13;
    QPushButton *btnTEMPRightAd_2;
    QWidget *pageSignUp;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnTEMPLeftAd_2;
    QFrame *line_10;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelCreateAcc;
    QFormLayout *formLayout;
    QLabel *labelFName;
    QLineEdit *lineEditFName;
    QLabel *labelLName;
    QLineEdit *lineEditLName;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QLabel *labelPhoneNum;
    QLineEdit *lineEditPhoneNum;
    QLabel *labelCity;
    QLineEdit *lineEditCity;
    QLabel *labelAddress;
    QLineEdit *lineEditAddress;
    QLabel *labelPesel;
    QLineEdit *lineEditPesel;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QLabel *labelRepeatPassword;
    QLineEdit *lineEditRepeatPassword;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonSignUp;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QFrame *line_11;
    QPushButton *btnTEMPRightAd;
    QWidget *pageCheckout;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btnTEMPLeftAd_5;
    QFrame *line_17;
    QVBoxLayout *verticalLayout_12;
    QLabel *labelCheckout;
    QFrame *line_19;
    QScrollArea *scrollAreaCheckout;
    QWidget *scrollAreaWidgetContents_3;
    QFormLayout *formLayout_3;
    QLabel *labelCartInfo;
    QLabel *labelCreature1;
    QLabel *labelCreature2;
    QFrame *line_20;
    QFormLayout *formLayout_4;
    QLabel *labelCardNum;
    QLabel *labelPin;
    QLabel *labelExpiryDate;
    QLineEdit *lineEditCardNum;
    QLineEdit *lineEditPin;
    QLineEdit *lineEditExpiryDate;
    QLabel *labelNumOnBack;
    QLineEdit *lineEditNumOnBack;
    QFormLayout *formLayout_5;
    QCheckBox *checkBoxCheckout1;
    QCheckBox *checkBoxCheckout2;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btnCheckout;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_4;
    QFrame *line_18;
    QPushButton *btnTEMPRightAd_4;
    QWidget *pageCart;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnTEMPLeftAd_4;
    QFrame *line_15;
    QVBoxLayout *verticalLayout_10;
    QLabel *labelMyCart;
    QFrame *line_14;
    QScrollArea *scrollAreaCart;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnGoToCheckout;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QFrame *line_16;
    QPushButton *btnTEMPRightAd_3;
    QFrame *line_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1185, 656);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        widgetSiteBody = new QWidget(MainWindow);
        widgetSiteBody->setObjectName("widgetSiteBody");
        widgetSiteBody->setEnabled(true);
        verticalLayout = new QVBoxLayout(widgetSiteBody);
        verticalLayout->setObjectName("verticalLayout");
        btTEMPTopAd = new QPushButton(widgetSiteBody);
        btTEMPTopAd->setObjectName("btTEMPTopAd");

        verticalLayout->addWidget(btTEMPTopAd);

        line_12 = new QFrame(widgetSiteBody);
        line_12->setObjectName("line_12");
        line_12->setFrameShadow(QFrame::Shadow::Plain);
        line_12->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line_12);

        stackedWidget = new QStackedWidget(widgetSiteBody);
        stackedWidget->setObjectName("stackedWidget");
        pageMain = new QWidget();
        pageMain->setObjectName("pageMain");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pageMain->sizePolicy().hasHeightForWidth());
        pageMain->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(pageMain);
        verticalLayout_4->setObjectName("verticalLayout_4");
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        btnTEMPLogo = new QPushButton(pageMain);
        btnTEMPLogo->setObjectName("btnTEMPLogo");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnTEMPLogo->sizePolicy().hasHeightForWidth());
        btnTEMPLogo->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(btnTEMPLogo, 0, 0, 1, 1);

        scrollAreaProducts = new QScrollArea(pageMain);
        scrollAreaProducts->setObjectName("scrollAreaProducts");
        scrollAreaProducts->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 946, 451));
        scrollAreaProducts->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(scrollAreaProducts, 2, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        labelSortBy = new QLabel(pageMain);
        labelSortBy->setObjectName("labelSortBy");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelSortBy->sizePolicy().hasHeightForWidth());
        labelSortBy->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(labelSortBy);

        btnTEMPRadioSort = new QPushButton(pageMain);
        btnTEMPRadioSort->setObjectName("btnTEMPRadioSort");

        verticalLayout_2->addWidget(btnTEMPRadioSort);

        btnTEMPLeftAd = new QPushButton(pageMain);
        btnTEMPLeftAd->setObjectName("btnTEMPLeftAd");
        sizePolicy1.setHeightForWidth(btnTEMPLeftAd->sizePolicy().hasHeightForWidth());
        btnTEMPLeftAd->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(btnTEMPLeftAd);


        gridLayout_4->addLayout(verticalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEditSearch = new QLineEdit(pageMain);
        lineEditSearch->setObjectName("lineEditSearch");

        horizontalLayout->addWidget(lineEditSearch);

        comboBoxSearch = new QComboBox(pageMain);
        comboBoxSearch->setObjectName("comboBoxSearch");

        horizontalLayout->addWidget(comboBoxSearch);

        btnSearch = new QPushButton(pageMain);
        btnSearch->setObjectName("btnSearch");

        horizontalLayout->addWidget(btnSearch);

        line_6 = new QFrame(pageMain);
        line_6->setObjectName("line_6");
        line_6->setFrameShadow(QFrame::Shadow::Plain);
        line_6->setFrameShape(QFrame::HLine);

        horizontalLayout->addWidget(line_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        btnTEMPCart = new QPushButton(pageMain);
        btnTEMPCart->setObjectName("btnTEMPCart");

        verticalLayout_3->addWidget(btnTEMPCart);

        line_5 = new QFrame(pageMain);
        line_5->setObjectName("line_5");
        line_5->setFrameShadow(QFrame::Shadow::Plain);
        line_5->setFrameShape(QFrame::HLine);

        verticalLayout_3->addWidget(line_5);

        labelCart = new QLabel(pageMain);
        labelCart->setObjectName("labelCart");

        verticalLayout_3->addWidget(labelCart);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        line_7 = new QFrame(pageMain);
        line_7->setObjectName("line_7");
        line_7->setFrameShadow(QFrame::Shadow::Plain);
        line_7->setFrameShape(QFrame::HLine);

        horizontalLayout_2->addWidget(line_7);

        btnTEMPUserImg = new QPushButton(pageMain);
        btnTEMPUserImg->setObjectName("btnTEMPUserImg");

        horizontalLayout_2->addWidget(btnTEMPUserImg);

        labelUserLogIn = new QLabel(pageMain);
        labelUserLogIn->setObjectName("labelUserLogIn");

        horizontalLayout_2->addWidget(labelUserLogIn);

        line_8 = new QFrame(pageMain);
        line_8->setObjectName("line_8");
        line_8->setFrameShadow(QFrame::Shadow::Plain);
        line_8->setFrameShape(QFrame::HLine);

        horizontalLayout_2->addWidget(line_8);

        btnSignUpMain = new QPushButton(pageMain);
        btnSignUpMain->setObjectName("btnSignUpMain");

        horizontalLayout_2->addWidget(btnSignUpMain);


        horizontalLayout->addLayout(horizontalLayout_2);


        gridLayout_4->addLayout(horizontalLayout, 0, 2, 1, 1);

        line = new QFrame(pageMain);
        line->setObjectName("line");
        line->setFrameShadow(QFrame::Shadow::Plain);
        line->setFrameShape(QFrame::HLine);

        gridLayout_4->addWidget(line, 1, 0, 1, 3);

        line_4 = new QFrame(pageMain);
        line_4->setObjectName("line_4");
        line_4->setFrameShadow(QFrame::Shadow::Plain);
        line_4->setFrameShape(QFrame::HLine);

        gridLayout_4->addWidget(line_4, 0, 1, 1, 1);

        line_3 = new QFrame(pageMain);
        line_3->setObjectName("line_3");
        line_3->setFrameShadow(QFrame::Shadow::Plain);
        line_3->setFrameShape(QFrame::HLine);

        gridLayout_4->addWidget(line_3, 2, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_4);

        stackedWidget->addWidget(pageMain);
        pageLogIn = new QWidget();
        pageLogIn->setObjectName("pageLogIn");
        verticalLayout_7 = new QVBoxLayout(pageLogIn);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        btnTEMPLeftAd_3 = new QPushButton(pageLogIn);
        btnTEMPLeftAd_3->setObjectName("btnTEMPLeftAd_3");
        sizePolicy1.setHeightForWidth(btnTEMPLeftAd_3->sizePolicy().hasHeightForWidth());
        btnTEMPLeftAd_3->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(btnTEMPLeftAd_3);

        line_2 = new QFrame(pageLogIn);
        line_2->setObjectName("line_2");
        line_2->setFrameShadow(QFrame::Shadow::Plain);
        line_2->setFrameShape(QFrame::HLine);

        horizontalLayout_7->addWidget(line_2);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(15);
        verticalLayout_8->setObjectName("verticalLayout_8");
        labelWelcomeBack = new QLabel(pageLogIn);
        labelWelcomeBack->setObjectName("labelWelcomeBack");
        QFont font;
        font.setPointSize(18);
        labelWelcomeBack->setFont(font);
        labelWelcomeBack->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_8->addWidget(labelWelcomeBack);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        labelEmailLogin = new QLabel(pageLogIn);
        labelEmailLogin->setObjectName("labelEmailLogin");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelEmailLogin);

        labelPasswordLogin = new QLabel(pageLogIn);
        labelPasswordLogin->setObjectName("labelPasswordLogin");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelPasswordLogin);

        lineEditLoginEmail = new QLineEdit(pageLogIn);
        lineEditLoginEmail->setObjectName("lineEditLoginEmail");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditLoginEmail);

        lineEditLoginPassword = new QLineEdit(pageLogIn);
        lineEditLoginPassword->setObjectName("lineEditLoginPassword");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEditLoginPassword);


        verticalLayout_8->addLayout(formLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        btnLogIn = new QPushButton(pageLogIn);
        btnLogIn->setObjectName("btnLogIn");
        sizePolicy1.setHeightForWidth(btnLogIn->sizePolicy().hasHeightForWidth());
        btnLogIn->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        btnLogIn->setFont(font1);

        horizontalLayout_8->addWidget(btnLogIn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_8->addLayout(horizontalLayout_8);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_8->addItem(verticalSpacer_2);

        verticalLayout_8->setStretch(2, 1);
        verticalLayout_8->setStretch(3, 3);

        horizontalLayout_7->addLayout(verticalLayout_8);

        line_13 = new QFrame(pageLogIn);
        line_13->setObjectName("line_13");
        line_13->setFrameShadow(QFrame::Shadow::Plain);
        line_13->setFrameShape(QFrame::HLine);

        horizontalLayout_7->addWidget(line_13);

        btnTEMPRightAd_2 = new QPushButton(pageLogIn);
        btnTEMPRightAd_2->setObjectName("btnTEMPRightAd_2");
        sizePolicy1.setHeightForWidth(btnTEMPRightAd_2->sizePolicy().hasHeightForWidth());
        btnTEMPRightAd_2->setSizePolicy(sizePolicy1);
        QFont font2;
        btnTEMPRightAd_2->setFont(font2);

        horizontalLayout_7->addWidget(btnTEMPRightAd_2);


        verticalLayout_7->addLayout(horizontalLayout_7);

        stackedWidget->addWidget(pageLogIn);
        pageSignUp = new QWidget();
        pageSignUp->setObjectName("pageSignUp");
        verticalLayout_6 = new QVBoxLayout(pageSignUp);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btnTEMPLeftAd_2 = new QPushButton(pageSignUp);
        btnTEMPLeftAd_2->setObjectName("btnTEMPLeftAd_2");
        sizePolicy1.setHeightForWidth(btnTEMPLeftAd_2->sizePolicy().hasHeightForWidth());
        btnTEMPLeftAd_2->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(btnTEMPLeftAd_2);

        line_10 = new QFrame(pageSignUp);
        line_10->setObjectName("line_10");
        line_10->setFrameShadow(QFrame::Shadow::Plain);
        line_10->setFrameShape(QFrame::HLine);

        horizontalLayout_3->addWidget(line_10);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName("verticalLayout_5");
        labelCreateAcc = new QLabel(pageSignUp);
        labelCreateAcc->setObjectName("labelCreateAcc");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelCreateAcc->sizePolicy().hasHeightForWidth());
        labelCreateAcc->setSizePolicy(sizePolicy3);
        labelCreateAcc->setFont(font);
        labelCreateAcc->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(labelCreateAcc);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelFName = new QLabel(pageSignUp);
        labelFName->setObjectName("labelFName");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelFName);

        lineEditFName = new QLineEdit(pageSignUp);
        lineEditFName->setObjectName("lineEditFName");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditFName);

        labelLName = new QLabel(pageSignUp);
        labelLName->setObjectName("labelLName");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelLName);

        lineEditLName = new QLineEdit(pageSignUp);
        lineEditLName->setObjectName("lineEditLName");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditLName);

        labelEmail = new QLabel(pageSignUp);
        labelEmail->setObjectName("labelEmail");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelEmail);

        lineEditEmail = new QLineEdit(pageSignUp);
        lineEditEmail->setObjectName("lineEditEmail");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditEmail);

        labelPhoneNum = new QLabel(pageSignUp);
        labelPhoneNum->setObjectName("labelPhoneNum");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelPhoneNum);

        lineEditPhoneNum = new QLineEdit(pageSignUp);
        lineEditPhoneNum->setObjectName("lineEditPhoneNum");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditPhoneNum);

        labelCity = new QLabel(pageSignUp);
        labelCity->setObjectName("labelCity");

        formLayout->setWidget(4, QFormLayout::LabelRole, labelCity);

        lineEditCity = new QLineEdit(pageSignUp);
        lineEditCity->setObjectName("lineEditCity");

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditCity);

        labelAddress = new QLabel(pageSignUp);
        labelAddress->setObjectName("labelAddress");

        formLayout->setWidget(5, QFormLayout::LabelRole, labelAddress);

        lineEditAddress = new QLineEdit(pageSignUp);
        lineEditAddress->setObjectName("lineEditAddress");

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEditAddress);

        labelPesel = new QLabel(pageSignUp);
        labelPesel->setObjectName("labelPesel");

        formLayout->setWidget(6, QFormLayout::LabelRole, labelPesel);

        lineEditPesel = new QLineEdit(pageSignUp);
        lineEditPesel->setObjectName("lineEditPesel");

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEditPesel);

        labelPassword = new QLabel(pageSignUp);
        labelPassword->setObjectName("labelPassword");

        formLayout->setWidget(7, QFormLayout::LabelRole, labelPassword);

        lineEditPassword = new QLineEdit(pageSignUp);
        lineEditPassword->setObjectName("lineEditPassword");

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEditPassword);

        labelRepeatPassword = new QLabel(pageSignUp);
        labelRepeatPassword->setObjectName("labelRepeatPassword");

        formLayout->setWidget(8, QFormLayout::LabelRole, labelRepeatPassword);

        lineEditRepeatPassword = new QLineEdit(pageSignUp);
        lineEditRepeatPassword->setObjectName("lineEditRepeatPassword");

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEditRepeatPassword);


        verticalLayout_5->addLayout(formLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pushButtonSignUp = new QPushButton(pageSignUp);
        pushButtonSignUp->setObjectName("pushButtonSignUp");
        sizePolicy1.setHeightForWidth(pushButtonSignUp->sizePolicy().hasHeightForWidth());
        pushButtonSignUp->setSizePolicy(sizePolicy1);
        pushButtonSignUp->setFont(font1);

        horizontalLayout_6->addWidget(pushButtonSignUp);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 2);
        horizontalLayout_6->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(verticalSpacer);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 1);
        verticalLayout_5->setStretch(3, 1);

        horizontalLayout_3->addLayout(verticalLayout_5);

        line_11 = new QFrame(pageSignUp);
        line_11->setObjectName("line_11");
        line_11->setFrameShadow(QFrame::Shadow::Plain);
        line_11->setFrameShape(QFrame::HLine);

        horizontalLayout_3->addWidget(line_11);

        btnTEMPRightAd = new QPushButton(pageSignUp);
        btnTEMPRightAd->setObjectName("btnTEMPRightAd");
        sizePolicy1.setHeightForWidth(btnTEMPRightAd->sizePolicy().hasHeightForWidth());
        btnTEMPRightAd->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(btnTEMPRightAd);


        verticalLayout_6->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(pageSignUp);
        pageCheckout = new QWidget();
        pageCheckout->setObjectName("pageCheckout");
        verticalLayout_11 = new QVBoxLayout(pageCheckout);
        verticalLayout_11->setObjectName("verticalLayout_11");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        btnTEMPLeftAd_5 = new QPushButton(pageCheckout);
        btnTEMPLeftAd_5->setObjectName("btnTEMPLeftAd_5");
        sizePolicy1.setHeightForWidth(btnTEMPLeftAd_5->sizePolicy().hasHeightForWidth());
        btnTEMPLeftAd_5->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(btnTEMPLeftAd_5);

        line_17 = new QFrame(pageCheckout);
        line_17->setObjectName("line_17");
        line_17->setFrameShadow(QFrame::Shadow::Plain);
        line_17->setFrameShape(QFrame::HLine);

        horizontalLayout_9->addWidget(line_17);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        labelCheckout = new QLabel(pageCheckout);
        labelCheckout->setObjectName("labelCheckout");
        sizePolicy3.setHeightForWidth(labelCheckout->sizePolicy().hasHeightForWidth());
        labelCheckout->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setPointSize(13);
        labelCheckout->setFont(font3);
        labelCheckout->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_12->addWidget(labelCheckout);

        line_19 = new QFrame(pageCheckout);
        line_19->setObjectName("line_19");
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(line_19->sizePolicy().hasHeightForWidth());
        line_19->setSizePolicy(sizePolicy4);
        line_19->setMinimumSize(QSize(75, 0));
        line_19->setFrameShadow(QFrame::Shadow::Plain);
        line_19->setFrameShape(QFrame::HLine);

        verticalLayout_12->addWidget(line_19);

        scrollAreaCheckout = new QScrollArea(pageCheckout);
        scrollAreaCheckout->setObjectName("scrollAreaCheckout");
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(scrollAreaCheckout->sizePolicy().hasHeightForWidth());
        scrollAreaCheckout->setSizePolicy(sizePolicy5);
        scrollAreaCheckout->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 953, 162));
        scrollAreaCheckout->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_12->addWidget(scrollAreaCheckout);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setVerticalSpacing(0);
        labelCartInfo = new QLabel(pageCheckout);
        labelCartInfo->setObjectName("labelCartInfo");
        sizePolicy3.setHeightForWidth(labelCartInfo->sizePolicy().hasHeightForWidth());
        labelCartInfo->setSizePolicy(sizePolicy3);
        QFont font4;
        font4.setPointSize(12);
        labelCartInfo->setFont(font4);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelCartInfo);

        labelCreature1 = new QLabel(pageCheckout);
        labelCreature1->setObjectName("labelCreature1");
        sizePolicy3.setHeightForWidth(labelCreature1->sizePolicy().hasHeightForWidth());
        labelCreature1->setSizePolicy(sizePolicy3);
        QFont font5;
        font5.setPointSize(14);
        labelCreature1->setFont(font5);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, labelCreature1);

        labelCreature2 = new QLabel(pageCheckout);
        labelCreature2->setObjectName("labelCreature2");
        sizePolicy3.setHeightForWidth(labelCreature2->sizePolicy().hasHeightForWidth());
        labelCreature2->setSizePolicy(sizePolicy3);
        labelCreature2->setFont(font5);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, labelCreature2);

        line_20 = new QFrame(pageCheckout);
        line_20->setObjectName("line_20");
        line_20->setMinimumSize(QSize(175, 0));
        line_20->setBaseSize(QSize(0, 0));
        line_20->setFrameShadow(QFrame::Shadow::Plain);
        line_20->setFrameShape(QFrame::HLine);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, line_20);


        verticalLayout_12->addLayout(formLayout_3);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        labelCardNum = new QLabel(pageCheckout);
        labelCardNum->setObjectName("labelCardNum");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, labelCardNum);

        labelPin = new QLabel(pageCheckout);
        labelPin->setObjectName("labelPin");

        formLayout_4->setWidget(1, QFormLayout::LabelRole, labelPin);

        labelExpiryDate = new QLabel(pageCheckout);
        labelExpiryDate->setObjectName("labelExpiryDate");

        formLayout_4->setWidget(2, QFormLayout::LabelRole, labelExpiryDate);

        lineEditCardNum = new QLineEdit(pageCheckout);
        lineEditCardNum->setObjectName("lineEditCardNum");

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEditCardNum);

        lineEditPin = new QLineEdit(pageCheckout);
        lineEditPin->setObjectName("lineEditPin");

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineEditPin);

        lineEditExpiryDate = new QLineEdit(pageCheckout);
        lineEditExpiryDate->setObjectName("lineEditExpiryDate");

        formLayout_4->setWidget(2, QFormLayout::FieldRole, lineEditExpiryDate);

        labelNumOnBack = new QLabel(pageCheckout);
        labelNumOnBack->setObjectName("labelNumOnBack");

        formLayout_4->setWidget(3, QFormLayout::LabelRole, labelNumOnBack);

        lineEditNumOnBack = new QLineEdit(pageCheckout);
        lineEditNumOnBack->setObjectName("lineEditNumOnBack");

        formLayout_4->setWidget(3, QFormLayout::FieldRole, lineEditNumOnBack);


        verticalLayout_12->addLayout(formLayout_4);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName("formLayout_5");
        checkBoxCheckout1 = new QCheckBox(pageCheckout);
        checkBoxCheckout1->setObjectName("checkBoxCheckout1");

        formLayout_5->setWidget(0, QFormLayout::LabelRole, checkBoxCheckout1);

        checkBoxCheckout2 = new QCheckBox(pageCheckout);
        checkBoxCheckout2->setObjectName("checkBoxCheckout2");

        formLayout_5->setWidget(1, QFormLayout::LabelRole, checkBoxCheckout2);


        verticalLayout_12->addLayout(formLayout_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);

        btnCheckout = new QPushButton(pageCheckout);
        btnCheckout->setObjectName("btnCheckout");
        sizePolicy1.setHeightForWidth(btnCheckout->sizePolicy().hasHeightForWidth());
        btnCheckout->setSizePolicy(sizePolicy1);
        QFont font6;
        font6.setPointSize(15);
        btnCheckout->setFont(font6);

        horizontalLayout_10->addWidget(btnCheckout);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);


        verticalLayout_12->addLayout(horizontalLayout_10);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_12->addItem(verticalSpacer_4);

        verticalLayout_12->setStretch(2, 15);
        verticalLayout_12->setStretch(3, 1);
        verticalLayout_12->setStretch(4, 1);
        verticalLayout_12->setStretch(5, 1);
        verticalLayout_12->setStretch(7, 1);

        horizontalLayout_9->addLayout(verticalLayout_12);

        line_18 = new QFrame(pageCheckout);
        line_18->setObjectName("line_18");
        line_18->setFrameShadow(QFrame::Shadow::Plain);
        line_18->setFrameShape(QFrame::HLine);

        horizontalLayout_9->addWidget(line_18);

        btnTEMPRightAd_4 = new QPushButton(pageCheckout);
        btnTEMPRightAd_4->setObjectName("btnTEMPRightAd_4");
        sizePolicy1.setHeightForWidth(btnTEMPRightAd_4->sizePolicy().hasHeightForWidth());
        btnTEMPRightAd_4->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(btnTEMPRightAd_4);


        verticalLayout_11->addLayout(horizontalLayout_9);

        stackedWidget->addWidget(pageCheckout);
        pageCart = new QWidget();
        pageCart->setObjectName("pageCart");
        verticalLayout_9 = new QVBoxLayout(pageCart);
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        btnTEMPLeftAd_4 = new QPushButton(pageCart);
        btnTEMPLeftAd_4->setObjectName("btnTEMPLeftAd_4");
        sizePolicy1.setHeightForWidth(btnTEMPLeftAd_4->sizePolicy().hasHeightForWidth());
        btnTEMPLeftAd_4->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(btnTEMPLeftAd_4);

        line_15 = new QFrame(pageCart);
        line_15->setObjectName("line_15");
        line_15->setFrameShadow(QFrame::Shadow::Plain);
        line_15->setFrameShape(QFrame::HLine);

        horizontalLayout_4->addWidget(line_15);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        labelMyCart = new QLabel(pageCart);
        labelMyCart->setObjectName("labelMyCart");
        sizePolicy3.setHeightForWidth(labelMyCart->sizePolicy().hasHeightForWidth());
        labelMyCart->setSizePolicy(sizePolicy3);
        labelMyCart->setFont(font3);

        verticalLayout_10->addWidget(labelMyCart);

        line_14 = new QFrame(pageCart);
        line_14->setObjectName("line_14");
        sizePolicy4.setHeightForWidth(line_14->sizePolicy().hasHeightForWidth());
        line_14->setSizePolicy(sizePolicy4);
        line_14->setMinimumSize(QSize(75, 0));
        line_14->setFrameShadow(QFrame::Shadow::Plain);
        line_14->setFrameShape(QFrame::HLine);

        verticalLayout_10->addWidget(line_14);

        scrollAreaCart = new QScrollArea(pageCart);
        scrollAreaCart->setObjectName("scrollAreaCart");
        sizePolicy1.setHeightForWidth(scrollAreaCart->sizePolicy().hasHeightForWidth());
        scrollAreaCart->setSizePolicy(sizePolicy1);
        scrollAreaCart->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 953, 331));
        scrollAreaCart->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_10->addWidget(scrollAreaCart);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        btnGoToCheckout = new QPushButton(pageCart);
        btnGoToCheckout->setObjectName("btnGoToCheckout");
        sizePolicy1.setHeightForWidth(btnGoToCheckout->sizePolicy().hasHeightForWidth());
        btnGoToCheckout->setSizePolicy(sizePolicy1);
        QFont font7;
        font7.setPointSize(10);
        font7.setBold(true);
        btnGoToCheckout->setFont(font7);

        horizontalLayout_5->addWidget(btnGoToCheckout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_10->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_10->addItem(verticalSpacer_3);

        verticalLayout_10->setStretch(2, 7);
        verticalLayout_10->setStretch(3, 1);
        verticalLayout_10->setStretch(4, 2);

        horizontalLayout_4->addLayout(verticalLayout_10);

        line_16 = new QFrame(pageCart);
        line_16->setObjectName("line_16");
        line_16->setFrameShadow(QFrame::Shadow::Plain);
        line_16->setFrameShape(QFrame::HLine);

        horizontalLayout_4->addWidget(line_16);

        btnTEMPRightAd_3 = new QPushButton(pageCart);
        btnTEMPRightAd_3->setObjectName("btnTEMPRightAd_3");
        sizePolicy1.setHeightForWidth(btnTEMPRightAd_3->sizePolicy().hasHeightForWidth());
        btnTEMPRightAd_3->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(btnTEMPRightAd_3);


        verticalLayout_9->addLayout(horizontalLayout_4);

        stackedWidget->addWidget(pageCart);

        verticalLayout->addWidget(stackedWidget);

        line_9 = new QFrame(widgetSiteBody);
        line_9->setObjectName("line_9");
        line_9->setFrameShadow(QFrame::Shadow::Plain);
        line_9->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line_9);

        MainWindow->setCentralWidget(widgetSiteBody);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1185, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(false);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "The Drip Shop\342\204\242", nullptr));
        btTEMPTopAd->setText(QCoreApplication::translate("MainWindow", "Top Ad", nullptr));
        btnTEMPLogo->setText(QCoreApplication::translate("MainWindow", "Logo here", nullptr));
        labelSortBy->setText(QCoreApplication::translate("MainWindow", "Sort by:", nullptr));
        btnTEMPRadioSort->setText(QCoreApplication::translate("MainWindow", "this will be radio buttons\n"
"for sorting but rn its a\n"
"button cause we can prob\n"
"generate it from an array or smth", nullptr));
        btnTEMPLeftAd->setText(QCoreApplication::translate("MainWindow", "Left Ad", nullptr));
        lineEditSearch->setText(QCoreApplication::translate("MainWindow", "search bar :)))", nullptr));
        btnSearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        btnTEMPCart->setText(QCoreApplication::translate("MainWindow", "cartImg", nullptr));
        labelCart->setText(QCoreApplication::translate("MainWindow", "Cart (0)", nullptr));
        btnTEMPUserImg->setText(QCoreApplication::translate("MainWindow", "User Img", nullptr));
        labelUserLogIn->setText(QCoreApplication::translate("MainWindow", "Not logged in", nullptr));
        btnSignUpMain->setText(QCoreApplication::translate("MainWindow", "Log in", nullptr));
        btnTEMPLeftAd_3->setText(QCoreApplication::translate("MainWindow", "LeftAd", nullptr));
        labelWelcomeBack->setText(QCoreApplication::translate("MainWindow", "Welcome back our dear consumer!", nullptr));
        labelEmailLogin->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        labelPasswordLogin->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        btnLogIn->setText(QCoreApplication::translate("MainWindow", "LOG IN AND CONTINUE CONSUMPTION!", nullptr));
        btnTEMPRightAd_2->setText(QCoreApplication::translate("MainWindow", "RightAd", nullptr));
        btnTEMPLeftAd_2->setText(QCoreApplication::translate("MainWindow", "LeftAd", nullptr));
        labelCreateAcc->setText(QCoreApplication::translate("MainWindow", "Create a Drip Shop\342\204\242 account!\n"
"BECOME A CONSUMER TODAY!!", nullptr));
        labelFName->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        labelLName->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        labelEmail->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        labelPhoneNum->setText(QCoreApplication::translate("MainWindow", "Phone Number", nullptr));
        labelCity->setText(QCoreApplication::translate("MainWindow", "City", nullptr));
        labelAddress->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        lineEditAddress->setText(QCoreApplication::translate("MainWindow", "not sure how we'll do it yet if address is going to be a class, maybe seperate inputs stuck together idk", nullptr));
        labelPesel->setText(QCoreApplication::translate("MainWindow", "PESEL", nullptr));
        labelPassword->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        labelRepeatPassword->setText(QCoreApplication::translate("MainWindow", "Repeat Password", nullptr));
        pushButtonSignUp->setText(QCoreApplication::translate("MainWindow", "SIGN UP AND BEGIN CONSUMING OUR PRODUCTS", nullptr));
        btnTEMPRightAd->setText(QCoreApplication::translate("MainWindow", "RightAd", nullptr));
        btnTEMPLeftAd_5->setText(QCoreApplication::translate("MainWindow", "Left ad", nullptr));
        labelCheckout->setText(QCoreApplication::translate("MainWindow", "Checkout", nullptr));
        labelCartInfo->setText(QCoreApplication::translate("MainWindow", "Card info pretty please", nullptr));
        labelCreature1->setText(QCoreApplication::translate("MainWindow", "  \360\237\245\272", nullptr));
        labelCreature2->setText(QCoreApplication::translate("MainWindow", "\360\237\221\211\360\237\221\210", nullptr));
        labelCardNum->setText(QCoreApplication::translate("MainWindow", "Card number", nullptr));
        labelPin->setText(QCoreApplication::translate("MainWindow", "PIN", nullptr));
        labelExpiryDate->setText(QCoreApplication::translate("MainWindow", "Expiry date", nullptr));
        labelNumOnBack->setText(QCoreApplication::translate("MainWindow", "Numbers on the back", nullptr));
        checkBoxCheckout1->setText(QCoreApplication::translate("MainWindow", "I agree to the terms and conditions", nullptr));
        checkBoxCheckout2->setText(QCoreApplication::translate("MainWindow", "I hereby forfeit my bank account, all consumer rights, and soul to Drip Shop\342\204\242 ltd.", nullptr));
        btnCheckout->setText(QCoreApplication::translate("MainWindow", "CONSUME PRODUCTS", nullptr));
        btnTEMPRightAd_4->setText(QCoreApplication::translate("MainWindow", "right ad", nullptr));
        btnTEMPLeftAd_4->setText(QCoreApplication::translate("MainWindow", "Left Ad", nullptr));
        labelMyCart->setText(QCoreApplication::translate("MainWindow", "My cart", nullptr));
        btnGoToCheckout->setText(QCoreApplication::translate("MainWindow", "Proceed to checkout", nullptr));
        btnTEMPRightAd_3->setText(QCoreApplication::translate("MainWindow", "Right ad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
