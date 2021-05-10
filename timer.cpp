#include <iostream>
#include <string>
#include <ctime>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <unistd.h>
using namespace std;



string convertSecondsToHumanReadableTime(double seconds) 
{
    if (seconds < 0) {
        cout << "Total seconds is negative and we can not convert a negative time to Human Readable format";
    }
    string humanReadableTime = "";
    if (seconds > 3599) {
        int hours = seconds / 3600;
        humanReadableTime += to_string(hours);
        humanReadableTime += " hours ";
        while (seconds > 3599) {
            seconds -= 3600;
        }
    }

    if (seconds <= 3599 && seconds >= 60) {
        int minutes = seconds / 60;
        humanReadableTime += to_string(minutes);
        humanReadableTime += " minutes ";
        while (seconds >= 60) {
            seconds -= 60;
        }
    }

    if (seconds >= 0) {
        humanReadableTime += to_string((int) seconds);
        humanReadableTime += " seconds";
    }
    return humanReadableTime;

}

double calculateTotalSeconds(double hours, double minutes, double seconds)
{
    if (hours < 0 || minutes < 0 || seconds < 0) {
        cout << "Please ensure all inputs are positive, greater than or equal to zero.";
        return 0.0;
    }
    double total = 0;
    total += (hours * 60 * 60) + (minutes * 60) + seconds;
    return total;
}



void countDownTimer(double hours, double minutes, double seconds) 
{
    if (hours < 0 || minutes < 0 || seconds < 0) {
        cout << "Please ensure all inputs are positive, greater than or equal to zero.";
        return;
    }
    double totalSeconds = calculateTotalSeconds(hours, minutes, seconds);
    cout << totalSeconds << " seconds total at start \n";

    while (totalSeconds > 0) {
        cout << convertSecondsToHumanReadableTime(totalSeconds) << "\n";
        usleep(1000000);
        --totalSeconds;
    }

    cout << "Your timer has reached zero!\n";
    cout << "Would you like to RESET (R) or QUIT (q)";
    char userInput;
    cin >> userInput;
    switch(userInput){
    case 'R':
        countDownTimer(hours, minutes, seconds);
        break;
    default:
        break;
    }
}

void countdownUserPrompt() 
{
    cout << "Please enter desired countdown time\n";
    double hours = 0.0;
    double minutes = 0.0;
    double seconds = 0.0;

    cout << "Please enter number of hours\n";
    cin >> hours;
    cout << "Please enter number of minutes\n";
    cin >> minutes;
    cout << "Please enter number of seconds\n";
    cin >> seconds;
    countDownTimer(hours, minutes, seconds);
}



void stopWatchTimer()
{
    time_t time_start;
    time_start = time(NULL);
    while (true) {
        clock_t time_elapsed = time(NULL) - time_start;
        if (time_elapsed % 1 == 0)
            cout << time_elapsed << " seconds\n";
    }
        
}

int main()
{   
    string timerType;
    cout << "Please type in COUNTDOWN or STOPWATCH\n";
    cin >> timerType;

    if (timerType == "COUNTDOWN") {
        countdownUserPrompt();
    } else if (timerType == "STOPWATCH") {
        stopWatchTimer();
    } else {
        cout << "You didn't select the correct timer type. Please re-run program.\n";
    }
    return 0;
}