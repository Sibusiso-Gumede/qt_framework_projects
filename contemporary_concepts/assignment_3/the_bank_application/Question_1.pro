TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        account.cpp \
        accountlist.cpp \
        cheque.cpp \
        customer.cpp \
        main.cpp \
        savings.cpp \
        transaction.cpp

HEADERS += \
    account.h \
    accountlist.h \
    cheque.h \
    customer.h \
    savings.h \
    transaction.h
