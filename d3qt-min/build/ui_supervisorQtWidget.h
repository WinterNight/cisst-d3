/********************************************************************************
** Form generated from reading UI file 'supervisorQtWidget.ui'
**
** Created: Mon May 12 22:53:37 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPERVISORQTWIDGET_H
#define UI_SUPERVISORQTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_supervisorQtWidget
{
public:
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QVBoxLayout *MainVLayout;
    QWebView *webViewMonitor;
    QPushButton *pushButton_2;
    QWidget *tab_4;

    void setupUi(QDockWidget *supervisorQtWidget)
    {
        if (supervisorQtWidget->objectName().isEmpty())
            supervisorQtWidget->setObjectName(QString::fromUtf8("supervisorQtWidget"));
        supervisorQtWidget->resize(1000, 666);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(supervisorQtWidget->sizePolicy().hasHeightForWidth());
        supervisorQtWidget->setSizePolicy(sizePolicy);
        supervisorQtWidget->setMinimumSize(QSize(1000, 570));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        supervisorQtWidget->setFont(font);
        supervisorQtWidget->setStyleSheet(QString::fromUtf8(" QDockWidget {\n"
"     border: 1px solid lightgray;\n"
"     /*titlebar-close-icon: url(close.png);\n"
"     titlebar-normal-icon: url(undock.png);*/\n"
" }\n"
"\n"
" QDockWidget::title {\n"
"     text-align: Center; /* align the text to the left */\n"
"     background: rgb(100, 170, 200);\n"
"     padding-left: 5px;\n"
" }\n"
"\n"
" QDockWidget::close-button, QDockWidget::float-button {\n"
"     border: 1px solid transparent;\n"
"     background: darkgray;\n"
"     padding: 0px;\n"
" }\n"
"\n"
" QDockWidget::close-button:hover, QDockWidget::float-button:hover {\n"
"     background: gray;\n"
" }\n"
"\n"
" QDockWidget::close-button:pressed, QDockWidget::float-button:pressed {\n"
"     padding: 1px -1px -1px 1px;\n"
" }"));
        supervisorQtWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
        supervisorQtWidget->setAllowedAreas(Qt::TopDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        tabWidget = new QTabWidget(dockWidgetContents);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayoutWidget = new QWidget(tab_3);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 971, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 3, 0, 1, 1);

        MainVLayout = new QVBoxLayout();
        MainVLayout->setObjectName(QString::fromUtf8("MainVLayout"));
        MainVLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        webViewMonitor = new QWebView(verticalLayoutWidget);
        webViewMonitor->setObjectName(QString::fromUtf8("webViewMonitor"));
        webViewMonitor->setUrl(QUrl(QString::fromUtf8("about:blank")));

        MainVLayout->addWidget(webViewMonitor);


        gridLayout_2->addLayout(MainVLayout, 1, 0, 2, 1);


        verticalLayout->addLayout(gridLayout_2);

        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(-20, 570, 988, 32));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());

        verticalLayout_2->addWidget(tabWidget);

        supervisorQtWidget->setWidget(dockWidgetContents);

        retranslateUi(supervisorQtWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(supervisorQtWidget);
    } // setupUi

    void retranslateUi(QDockWidget *supervisorQtWidget)
    {
        supervisorQtWidget->setWindowTitle(QApplication::translate("supervisorQtWidget", "System Monitoring Dashboard - Safety Framework", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("supervisorQtWidget", "Generate Test Event", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("supervisorQtWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("supervisorQtWidget", "Tab 1", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("supervisorQtWidget", "Tab 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class supervisorQtWidget: public Ui_supervisorQtWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPERVISORQTWIDGET_H
