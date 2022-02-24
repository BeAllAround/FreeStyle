def increment_string(string):
    if len(string) == 0:
        return '1'
    s = list(reversed([*string]));
    z = 0;
    nums = [];
    i = 0;
    while(i < len(s) and s[i].isdigit()):
        nums.append(s[i]);
        i += 1 
    nums.reverse();
    for item in nums:
        if item != '0':
            break
        z += 1
    for _ in range(z):
        nums.pop(0);
    if len(nums) == 0:
        if i == 0:
            return string + '1';
        return (''.join(list(reversed(s[i:]))) +  '0' * (z-1)) + '1';
    n1 = ''.join(nums);
    n2 = str(int(n1) + 1)
    zeros = '0' * (z - (len(n2) - len(n1)));
    return ''.join(list(reversed(s[i:]))) + zeros + n2;
