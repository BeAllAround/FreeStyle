from functools import cmp_to_key;

def max_(songs, n):
    _max = 0;
    for item in songs:
        if(len(item[n]) > _max):
            _max = len(item[n]);
    return _max;

def _cmp(a, b):
    if a[2] < b[2]:
        return -1;
    if a[2] > b[2]:
        return 1;
    if a[0] > (b[0]):
        return 1;
    if a[0] < b[0]:
        return -1;
    return 0;

def format_playlist(songs):
    songs = sorted(songs, key=cmp_to_key(_cmp));
    _str = '';
    strName, artistName, end = '', '', '';
    name, _time, artist = None, None, None;
    if(len(songs) == 0):
        return "+------+------+--------+\n" \
                           "| Name | Time | Artist |\n" \
                           "+------+------+--------+"
    strName = ('+' + ((max_(songs, 0)+2) * '-'));
    artistName = ('+' + ((max_(songs, 2)+2) * '-'));
    name = (len(strName) - len('Name'));
    artist = (len(artistName) - len('Artist'));
    _str += strName + '+' + '------' +  artistName +'+\n';
    end = _str;
    _str += '| Name' + ' ' * (name-2);
    _str += '| Time |';
    _str += ' Artist' + ' ' * (artist-2) + '|\n';
    _str += strName + '+' + '------' +  artistName +'+\n';
    for item in songs:
        name = (len(strName) - len(item[0]));
        artist = (len(artistName) - len(item[2]));
        _str += '| ' + item[0] + (' ' * (name-2));
        _str += '| ' + item[1] + ' |';
        _str += ' ' + item[2] + ' ' * (artist-2) + '|\n';
    end = end.replace('\n', '');
    _str += end;
    return _str
