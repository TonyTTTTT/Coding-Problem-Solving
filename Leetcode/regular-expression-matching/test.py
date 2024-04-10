def match(text, pattern):
    if not pattern: return not text
    first_match = bool(text) and pattern[0] in {text[0], '.'}
    return first_match and match(text[1:], pattern[1:])

if __name__ == '__main__':
    if match('abdsae', 'ad.dae'):
        print('match')
    else:
        print('not match')
    pass