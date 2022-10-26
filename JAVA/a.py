import re
cadena=input()
print(int(len(re.findall("\w",cadena))/len(re.findall("\d",cadena))))