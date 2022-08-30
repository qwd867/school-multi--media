/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_stop;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_pre;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_start_puse;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_next;
    QSpacerItem *horizontalSpacer_5;
    QSlider *hSlider_voice;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_open;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSlider *hSlider_progressBar;
    QPushButton *pushButton_playorder;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1000, 600);
        Widget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 70));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_stop = new QPushButton(widget_2);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setMaximumSize(QSize(50, 50));
        pushButton_stop->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\345\201\234\346\255\242.png);"));

        horizontalLayout->addWidget(pushButton_stop);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_pre = new QPushButton(widget_2);
        pushButton_pre->setObjectName(QStringLiteral("pushButton_pre"));
        pushButton_pre->setMaximumSize(QSize(45, 45));
        pushButton_pre->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\344\270\212\344\270\200\344\270\252.png);"));

        horizontalLayout->addWidget(pushButton_pre);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_start_puse = new QPushButton(widget_2);
        pushButton_start_puse->setObjectName(QStringLiteral("pushButton_start_puse"));
        pushButton_start_puse->setMaximumSize(QSize(45, 45));
        pushButton_start_puse->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\346\222\255\346\224\276.png);"));

        horizontalLayout->addWidget(pushButton_start_puse);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_next = new QPushButton(widget_2);
        pushButton_next->setObjectName(QStringLiteral("pushButton_next"));
        pushButton_next->setMaximumSize(QSize(45, 45));
        pushButton_next->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\344\270\213\344\270\200\344\270\252.png);"));

        horizontalLayout->addWidget(pushButton_next);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        hSlider_voice = new QSlider(widget_2);
        hSlider_voice->setObjectName(QStringLiteral("hSlider_voice"));
        hSlider_voice->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(hSlider_voice);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButton_open = new QPushButton(widget_2);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));
        pushButton_open->setMaximumSize(QSize(50, 50));
        pushButton_open->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/image/file-open.png);"));

        horizontalLayout->addWidget(pushButton_open);


        gridLayout->addWidget(widget_2, 2, 0, 1, 1);

        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(label);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        widget_3 = new QWidget(Widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        hSlider_progressBar = new QSlider(widget_3);
        hSlider_progressBar->setObjectName(QStringLiteral("hSlider_progressBar"));
        hSlider_progressBar->setMouseTracking(true);
        hSlider_progressBar->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(hSlider_progressBar);

        pushButton_playorder = new QPushButton(widget_3);
        pushButton_playorder->setObjectName(QStringLiteral("pushButton_playorder"));
        pushButton_playorder->setMaximumSize(QSize(45, 40));
        pushButton_playorder->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/image/\351\241\272\345\272\217\346\222\255\346\224\276.png);"));

        horizontalLayout_3->addWidget(pushButton_playorder);


        gridLayout->addWidget(widget_3, 1, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButton_stop->setText(QString());
        pushButton_pre->setText(QString());
        pushButton_start_puse->setText(QString());
        pushButton_next->setText(QString());
        pushButton_open->setText(QString());
        label->setText(QString());
        pushButton_playorder->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
