#ifndef QPDFIUM_H
#define QPDFIUM_H

#include <QObject>
#include <QMap>
#include <QWeakPointer>
#include "qpdfiumglobal.h"

QT_BEGIN_NAMESPACE

class QPdfiumPage;

class Q_PDFIUM_EXPORT QPdfium : public QObject
{
    Q_OBJECT
public:
    explicit QPdfium(QString filename, QObject *parent = 0);

    virtual ~QPdfium();

    bool isValid() const;
    QString filename() const;
    int pageCount() const;
    QWeakPointer<QPdfiumPage> page(int i);
private:
    Q_DISABLE_COPY(QPdfium)
    void* m_document;
    QString m_filename;
    QMap<int, QSharedPointer<QPdfiumPage>> m_pages;
};

QT_END_NAMESPACE

#endif // QPDFIUM_H