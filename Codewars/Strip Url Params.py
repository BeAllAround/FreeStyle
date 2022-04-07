def f(arr):
    def _(x):
        for item in arr:
            if x.startswith(item):
                return False;
        return True;
    return _;

def findIndex(arr, k):
    for x in range(len(arr)):
        if arr[x][0] == k:
            return x;
    return -1;

def filter2(arr):
    a, _a = [], [];
    for item in arr:
        a.append(item.split('='));
    for k,v in a:
        if findIndex(_a, k) == -1:
            _a.append([k, v]);
    return ['='.join(item) for item in _a];

def strip_url_params(url, params_to_strip=[]):
    _f = f(params_to_strip);
    try:
        s = url[:url.index('?')];
        l = (filter2(list(filter(_f, url[url.index('?')+1:].split('&')))));
        if len(l)!=0:
            return s + '?' + '&'.join(l);
        return s;
    except ValueError:
        return url;

'''
import urlparse
import urllib

def strip_url_params(url, strip=None):
    if not strip: strip = []
    
    parse = urlparse.urlparse(url)
    query = urlparse.parse_qs(parse.query)
    
    query = {k: v[0] for k, v in query.iteritems() if k not in strip}
    query = urllib.urlencode(query)
    new = parse._replace(query=query)
    
    return new.geturl()

import re; # *!!!
def strip_url_params(url, remove=[]):
    base, *psa = re.split('\?|\&', url)
    done = set(remove)
    psf = (k+'='+v for k,v in (p.split('=') for p in psa)
          if not (k in done or done.add(k)))
    return base+'?'+'&'.join(psf) if psa else base
'''
