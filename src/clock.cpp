#include <clock.h>

Clock::Clock() {
    time = 0;
}

Clock::Clock(const Clock& c) {
    this->time = c.time;
    puts("Clock::Clock(const Clock& c) -> ended runtime.");
}

void Clock::setTime(time_t time) {
    this->time = time;
}

time_t Clock::getTime() {
    return this->time;
}

//TODO: Add year, months, days, etc... (update timeFormat too.)
//TODO: fix const char* [??? c++ sucks i guess...]
std::string Clock::getTimeAsString(const char* timeFormat) {
    int seconds = (int)getTime();
    int minutes = 0;
    int hours = 0;

    if(seconds >= 60) {
        minutes = seconds / 60;
        seconds %= 60;
    }

    if(minutes >= 60) {
        hours = minutes / 60;
        minutes %= 60;
    }

    std::string timeString = "";

    for(char c : std::string(timeFormat))
        switch(c) {
            case 'H': timeString += std::to_string(hours); break;
            case 'M': timeString += std::to_string(minutes); break;
            case 'S': timeString += std::to_string(seconds); break;
            default: timeString += c; //i might wanna check if this is a letter or not 
                                      //(perhaps i could allow only non-alphabetic characters?)
        }

    return timeString;
}