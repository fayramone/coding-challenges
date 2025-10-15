class Date {
private:
    int day, month, year;

    static bool isLeapYear(int y) {
        return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    }

    bool isValidDate() const {
        if (day < 1) return false;
        if (month < 1 || month > 12) return false;
        if (year < 1970 || year > 2099) return false;

        int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (isLeapYear(year)) daysInMonth[1] = 29;
        
        return (day <= daysInMonth[month - 1]);
    }

    void validCheck() {
        if (!isValidDate()) {
            day = 1;
            month = 1;
            year = 1970;
        }
    }

    int toDays() const {
        int total = 0;

        for (int y = 1970; y < year; ++y) {
            total += (isLeapYear(y) ? 366 : 365);
        }

        int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (isLeapYear(year)) daysInMonth[1] = 29;

        for (int m = 1; m < month; ++m) {
            total += daysInMonth[m - 1];
        }

        total += day - 1;

        return total;
    }

    static Date fromDays(int totalDays) {
        int y = 1970;
        while(totalDays >= (isLeapYear(y) ? 366 : 365)) {
            totalDays -= (isLeapYear(y) ? 366 : 365);
            ++y;
        }

        int m = 1;
        int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (isLeapYear(y)) daysInMonth[1] = 29;
        while(totalDays >= daysInMonth[m - 1]) {
            totalDays -= daysInMonth[m - 1];
            ++m;
        }

        return Date(totalDays + 1, m, y);
    }

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        validCheck();
    }

    int GetDay() const { return day; }
    int GetMonth() const { return month; }
    int GetYear() const { return year; }

    Date operator + (int days) const {
        int total = toDays() + days;
        return fromDays(total);
    }

    Date operator - (int days) const {
        int total = toDays() - days;
        return fromDays(total);
    }

    int operator - (Date rhs) const {
        return this->toDays() - rhs.toDays();
    }
};