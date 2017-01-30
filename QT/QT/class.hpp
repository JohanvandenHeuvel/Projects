#pragma once
#include <QObject>

class Class : public QObject {
	Q_OBJECT

public:
	Class(QObject * parent = Q_NULLPTR);
	~Class();

private:
	
};
