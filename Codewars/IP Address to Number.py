def Bint_to_bin(num):
    n = '{:08b}'.format(num);
    return ('0' * (32 - len(n))) +n;

def int_to_bin(num):
    return '{:08b}'.format(num);

def ip_to_num(ip):
    ip = ip.split('.');
    for x in range(len(ip)):
        ip[x] = int_to_bin(int(ip[x]));
    return int(''.join(ip), 2);

def num_to_ip(num):
    s = (Bint_to_bin(num));
    ip = [s[x:x+8] for x in range(0, len(s), 8)];
    for x in range(len(ip)):
        ip[x] = str(int(ip[x], 2));
    return '.'.join(ip);

'''
  # Codewars
  from ipaddress import IPv4Address

  def ip_to_num(ip):
      return int(IPv4Address(ip))

  def num_to_ip(num):
      return str(IPv4Address(num))
  
  
  def ip_to_num(ip):
    merge =""
    for num in (ip.split('.')):
        binary = bin(int(num)).replace('0b','')
        x = binary[::-1]
        while len(x) < 8:
            x += '0'
        binary = x[::-1]
        merge += binary
    return int(merge,2)

  def num_to_ip(num):
      i = 0
      merge = ""
      binary = bin(num).replace('0b','')
      reverse = binary[::-1]
      while len(reverse) < 32:
          reverse += '0'
      binary = reverse[::-1]
      parts = [binary[i:i+8] for i in range(0, len(binary), 8)]
      for bi in parts:
          merge += str(int(bi,2))
          merge += '.'
      x = merge[:-1]
      return x
'''
