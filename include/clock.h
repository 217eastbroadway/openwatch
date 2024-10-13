#include <iostream>

class Clock {
    private:
        time_t time;

    public:
        Clock();
        Clock(const Clock& c);

        void setTime(time_t time);
        time_t getTime();

        std::string getTimeAsString(const char* timeFormat);
};