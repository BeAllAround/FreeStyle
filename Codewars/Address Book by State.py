def by_state(str): # boy did it get knotty here...
    arr_2 = [];
    s = '';
    names = {'AZ': 'Arizona',
'CA': 'California',
'ID': 'Idaho',
'IN': 'Indiana',
'MA': 'Massachusetts',
'OK': 'Oklahoma',
'PA': 'Pennsylvania',
'VA': 'Virginia'};
    for k in names.keys():
        str = str.replace(k, names[k]);
    arr = sorted(str.split('\n'));
    arr_names = [];
    for x in range(len(arr)):
        item = arr[x];
        k = (item.split(',')[-1].strip().split(' '))[-1];
        arr_2.append([k, x]);
        arr_names.append(k);
    arr_3 = sorted(arr_2)
    arr_names = list(set(arr_names));
    arr_names.sort();
    while(len(arr_names) != 0 and arr_names[0] == ''):
        arr_names.pop(0);
    for name in arr_names:
        s += ' ' + name + '\r\n';
        for k, inx in arr_3:
            if k == name:
                s += '..... ';
                s += arr[inx] + '\r\n'
    s = ''.join([*s][:-2]);
    return s.replace(',', '').strip();
  
'''
    # Codewars
    from collections import defaultdict
    import re

    PATTERN = re.compile(r'(.+?), (.+?), (.+?(?= [A-Z]{2})) ([A-Z]{2})')
    STATES = {"CA": "California",
              "MA": "Massachusetts",
              "OK": "Oklahoma",
              "PA": "Pennsylvania",
              "VA": "Virginia",
              "AZ": "Arizona",
              "ID": "Idaho",
              "IN": "Indiana"}

    def by_state(s):
        dct = defaultdict(list)
        for name,addrs,city,state in PATTERN.findall(s):
            dct[STATES[state]].append("..... {} {} {} {}".format(name, addrs, city, STATES[state]))

        return '\r\n '.join( "{}\r\n{}".format(state, '\r\n'.join(sorted(lst))) for state,lst in sorted(dct.items()) )
'''
