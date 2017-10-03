print "hello"
dicto = {}
dicto['a'] = 2000
print dicto
dicto['a'] = 2017
print dicto## Can build up a dict by starting with the the empty dict {}
## and storing key/value pairs into the dict like this:
## dict[key] = value-for-that-key
dict = {}
dict['a'] = 'alpha'
dict['g'] = 'gamma'
dict['o'] = 'omega'

print dict  ## {'a': 'alpha', 'o': 'omega', 'g': 'gamma'}

print dict['a']     ## Simple lookup, returns 'alpha'
dict['a'] = 6       ## Put new key/value into dict
'a' in dict         ## True
##print dict['z']                  ## Throws KeyError
#if 'z' in dict: print dict['z']     ## Avoid KeyError
#print dict.get('z')  ## None (instead of KeyError
