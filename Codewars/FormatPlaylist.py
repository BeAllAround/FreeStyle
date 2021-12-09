def max_(songs, n):
    _max = 0;
    for item in songs:
        if(len(item[n]) > _max):
            _max = len(item[n]);
    return _max;

def Sort(e):
    return len(e[2]);

def Sort2(e):
    return len(e[2]);

def restructure(songs):
    obj = {};
    return obj;

def format_playlist(songs):
    songs.sort(key=Sort);
    # songs.sort(key=Sort2);
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
    _str += end;
    return _str

print(format_playlist([
                    ('Stoned', '3:25', 'King Krule'),
                    ('Serenade', '3:00', 'Travis Scott'),
                    ('I love getting high', '5:15', 'NBA 2k20 Soundtrack'),
                    ('Stuck', '2:54', 'Future'),
                    ('Night', '5:22', 'Travis Scott')]));
