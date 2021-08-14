def domain_name(url):
    first = ['www', 'http://www', 'https://www'];
    url = url.split('.');
    url_start = url[0];
    if url_start in first:
        return url[1];
    elif url_start.startswith('http://'):
        return url_start.split('http://')[1];
    elif url_start.startswith('https://'):
        return url_start.split('https://')[1];
    else:
        return url_start;
