from datetime import datetime

def query_now():

    now = datetime.now()
    year = now.year
    month = now.month
    day = now.day
    hour = now.hour
    minute = now.minute
    second = now.second

    time_format = f"Current time is {day}.{month}.{year} {hour}:{minute}:{second}"
    time_format = f"Current African Time is {hour} {minute} {second}"

    return time_format
