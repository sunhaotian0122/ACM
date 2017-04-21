'''
Package CC17
'''
_initalized = -1
_input_key = 0
_call_limit = 2000
_wincount = 0

_accepted = "6d37d07307058f1d44d5dd89cb55060b6c2bf3a1"
_wronganswer = "WRONGANSWER"

def rps(shape):
    global _initalized, _input_key, _call_limit, _wincount
    result, computer_shape = -1, -1
    if _call_limit == 0:
        print(_accpeted)
        return 100;
    _call_limit -= 1;
    if _initalized == -1:
        _initalized = int(input())
    if (shape < 0) or (shape > 2):
        print(_wronganswer)
        return 100
    _initalized = (_initalized * 65973 + 28411) % 524288
    computer_shape = _initalized % 3
    result = (shape - computer_shape + 3) % 3
    if result == 2:
        _wincount = 0
        return -1
    elif result == 1:
        _wincount += 1
        if _wincount == 1000:
            print(_accepted)
            return 100
        return 1;
    elif result == 0:
        _wincount = 0
        return 0



if __name__ == "__main__":
    print("You should import this package.")
