def assemble(input):
    if(len(input) == 0):
        return ''
    arr = [*('*' * len(input[0]))]
    for item in input:
        for x in range(len(arr)):
            if item[x] != '*' and arr[x] == '*':
                arr[x] = item[x]
    return ''.join(arr).replace('*', '#')
  
'''
    # Codewars
    def assemble(input):
      result = list(input[0]) if input else []

      for i in input:
          for j, k in enumerate(i):
              result[j] = k if result[j] == '*' else result[j]

      return ''.join(result).replace('*', '#')
'''
