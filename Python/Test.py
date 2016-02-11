
def test_value(value):
    return 'The value is ' + ('just right.' if value < 100 else 'too big!')
def test_value2(value):
    return 'The value is ' + (value < 100 and 'just right.' or 'too big!')
# problem with 2nd method is what if 'just right' were an empty string? will always return too big

# print test_value(515)
# print test_value2(155)

# for x in range(5):
#     print(x)

import os, time
print time.time()
print os.path.exists("PocketPrimer.py")








