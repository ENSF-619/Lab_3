
/*
* File Name: lab3Clock.h
* Lab #3
* Completed by: Ziad Chemali
* Submission Date: October 9,2020

*/

#ifndef lab3_exe_C_Clock
#define lab3_exe_C_Clock
/* The following class definition is for Clock that represents 24 hour, and is able to 
* create a clock, increment time by one second, or decrement time by one second.
* 
 */

class Clock {
public:
    Clock();
    // PROMISES: initializes hours,minutes, and seconds to zero
    Clock(int s);
    // PROMISES: initialize the clock data members with values for hour,minute, and second in this
    // argument
    Clock(int h, int m, int s);
    // PROMISES: initialize the data members hour, minute, and second with h,m, and s 
    int get_hour() const;
    // PROMISES: returns hour
    int get_minute() const;
    // PROMISES: return minute
    int get_second() const;
    // PROMISES: return seconds
    void set_hour(int h);
    // PROMISES: updates hour data member with h
    void set_minute(int m);
    // PROMISES: updates the minute data member with m
    void set_second(int s);
    // PROMISES: updates the second data member with s
    void increment();
    // PROMISES: increments the value of clocks time by one second 
    void decrement();
    // PROMISES: decrements the value of the clocks time by one second
    void add_seconds(int s);
    // PROMISES: adds the value of s to the value of current time
private:
    int hms_to_sec();
    // PROMISES: returns the total value of data members in a Clock
    void sec_to_hms(int s);
    // PROMISES: sets the data members of clock to the value of s
    int hour;  
    int minute;  
    int second;
};

#endif
