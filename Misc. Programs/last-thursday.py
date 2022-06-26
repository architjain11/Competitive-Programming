from datetime import date

day = date.today().day
month = date.today().month
year = date.today().year
weekday = date.today().weekday()

def last_thursday(day, month, year, weekday):
    feb_days = 28
    if ((year%400 == 0) and (year%100 == 0)) or ((year%4 ==0) and (year%100 != 0)):
        feb_days = 29

    weekdays = ['monday', 'tuesday', 'wednesday', 'thursday', 'friday', 'saturday', 'sunday']
    months = ['january', 'february', 'march', 'april', 'may', 'june', 'july', 'august', 'september', 'october', 'november', 'december']
    days_in_month = {
        'january':31,
        'february':feb_days,
        'march':31,
        'april':30,
        'may':31,
        'june':30,
        'july':31,
        'august':31,
        'september':30,
        'october':31,
        'november':30,
        'december':31
    }
    last_day = days_in_month[months[month-1]]
    last_weekday = weekday+((last_day-day)%7)
    while last_weekday != 3:
        last_day-=1
        last_weekday = 6 if last_weekday==0 else last_weekday-1

    if last_day<day:
        day = (last_day+7)%days_in_month[months[month-1]]
        month = month+1 if month<12 else 1
        year = year+1 if month==1 else year
        return last_thursday(day, month, year, 3)

    return last_day


print(last_thursday(day, month, year, weekday))