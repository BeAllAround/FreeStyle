def domain_name(url):
    url = url.split('.');
    if(url[0] == 'www'):
        return url[1];
    elif url[0] == 'http://www' or url[0] == 'https://www':
        return url[1];
    elif url[0].startswith('http://'):
        return url[0].split('http://')[1];
    elif url[0].startswith('https://'):
        return url[0].split('https://')[1];
    else:
        return url[0];
