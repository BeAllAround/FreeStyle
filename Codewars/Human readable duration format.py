import datetime;

def regular(hours, minutes, sec):
    f1, f2, f3 = '', '', '';
    if(hours == 1):
        f1 = '1 hour'
    elif(hours!=0):
        f1 = str(hours) + ' hours';
    if(minutes == 1):
        f2 = '1 minute';
    elif(minutes!=0):
        f2 = str(minutes) + ' minutes'
    if(sec == 1):
        f3 = '1 second';
    elif(sec != 0):
        f3 = str(sec) + ' seconds';
    if(f1 != '' and f2 != '' and f3 != ''):
        return f1 + ", " + f2 + " and " + f3;
    if(f1 != '' and f2 == '' and f3 == ''):
        return f1;
    if(f1 == '' and f2 != '' and f3 == ''):
        return f2;
    if(f1 == '' and f2 == '' and f3 != ''):
        return f3;
    if(f1 == '' and f2 != '' and f3 != ''):
        return f2 + ' and ' + f3;
    if(f1 != '' and f2 != '' and f3 == ''):
        return f1 + ' and ' + f2;
    if(f1 != '' and f2 == '' and f3 != ''):
        return f1 + ' and ' + f3;
    
    
def daYs(n):
    f1, f2 = '', '';
    years = int(n/365);
    n2 = years * 365;
    days = n - n2; # days
    if(years==1):
        f1 = '1 year, '
    elif(years!=0):
        f1 = str(years) + ' years, ';
    if(days == 1):
        f2 = '1 day, ';
    elif(days!=0):
        f2 = str(days) + ' days, ';
    return f1 + f2;

def format_duration(seconds):
    td = datetime.timedelta(seconds=seconds);
    hours, minutes, sec = (td.seconds//3600, ((td.seconds//60)%60), td.seconds%60);
    if(hours == 0 and minutes == 0 and sec == 0):
        return 'now';
    _s = '';
    s_td = str(td);
    if('day' in s_td):
        _s += daYs(int(s_td[:s_td.index(' ')]));
    _s += (regular(hours, minutes, sec));
    return _s;

'''
  # Codewars
times = [("year", 365 * 24 * 60 * 60), 
         ("day", 24 * 60 * 60),
         ("hour", 60 * 60),
         ("minute", 60),
         ("second", 1)]

def format_duration(seconds):

    if not seconds:
        return "now"

    chunks = []
    for name, secs in times:
        qty = seconds // secs
        if qty:
            if qty > 1:
                name += "s"
            chunks.append(str(qty) + " " + name)

        seconds = seconds % secs

    return ', '.join(chunks[:-1]) + ' and ' + chunks[-1] if len(chunks) > 1 else chunks[0]
    
def format_duration(seconds):
    if seconds == 0: return "now"
    units = ( (31536000, "year"  ), 
              (   86400, "day"   ),
              (    3600, "hour"  ),
              (      60, "minute"),
              (       1, "second") )
    ts, t = [], seconds
    for unit in units:
        u, t = divmod(t, unit[0])
        ts += ["{} {}{}".format(u, unit[1], "s" if u>1 else "")] if u != 0 else []
    return ", ".join([str(d)for d in ts[:-1]]) + (" and " if len(ts)>1 else "") + ts[-1]
    
    '''
