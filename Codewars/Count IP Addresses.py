def ips_between(start, end):
    start = list(map(int, start.split('.')));
    end = list(map(int, end.split('.')));
    arr1, arr2 = [], [];
    c = 3;
    for x in range(len(start)):
        arr1.append(start[x] * pow(256, c));
        arr2.append(end[x] * pow(256, c));
        c -= 1;
    return sum(arr2) - sum(arr1);

'''
from ipaddress import ip_address

def ips_between(start, end):
    return int(ip_address(end)) - int(ip_address(start))


from ipaddress import IPv4Address

def ips_between(start, end):
    return int(IPv4Address(end)) - int(IPv4Address(start))
'''
