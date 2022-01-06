import datetime;
def make_readable(seconds_input):
    td = datetime.timedelta(seconds=seconds_input);
    seconds = (str(td).split(':')[-1]);
    hours, minutes = ((td.seconds//3600+td.days*24, (td.seconds//60)%60));
    return (':'.join([str(hours).zfill(2), str(minutes).zfill(2), seconds]));
