from datetime import date;

def filterYear(year_arr, day):
    return list(filter(lambda x: x == day, year_arr));

def most_frequent_days(year):
    weeks = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
    _dict = {'Mon': 'Monday', 'Tue': 'Tuesday', 'Wed': 'Wednesday', 'Thu': 'Thursday', 'Fri': 'Friday', 'Sat': 'Saturday', 'Sun': 'Sunday'};
    arr = [];
    arr_filtered, arr_frequency = [], [];
    m, d = 1, 1;
    while 1:
        try:
            arr.append(date(year, m, d).ctime()[0:3]);
            d += 1;
        except ValueError:
            if m == 12:
                break;
            m += 1;
            d = 1;
    for week in weeks:
        frequency = filterYear(arr, week).__len__();
        arr_filtered.append([_dict[week], frequency]);
        arr_frequency.append(frequency);
    __max = max(arr_frequency); 
    return list(map(lambda item: item[0], filter(lambda item: item[1] == __max, arr_filtered)));
