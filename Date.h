#ifndef DATE_H
#define DATE_H

class Date
{
  public:
    Date(int=0, int=0, int=2000);
    Date(Date*);
    ~Date();
    void setDate(int, int, int);
    void print();
    bool lessThan(Date*);
    bool equals(Date*);
    void add(int);
    bool collides(Date*, int);

  private:
    int day;
    int month;
    int year;
    bool leapYear();
    int  lastDayInMonth();
    
    string getMonthStr() const;
};

#endif
