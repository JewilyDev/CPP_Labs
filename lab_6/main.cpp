#include <QCoreApplication>
#include "customtime.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CustomTime start = CustomTime("15:30"); // Начало пары
    CustomTime end = CustomTime(17,00); // Конец пары
    int lessonTime = end - start; // Длительность пары
    qDebug("Lesson time %d",lessonTime);
    CustomTime newTime = start + lessonTime;
    if(newTime == end)
    {
      qDebug("All is ok");
      newTime.print();
    }

    return a.exec();
}
