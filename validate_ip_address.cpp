function fitsOneByte(chunk):
    # Does this string chunk represent a number
    # from 0 to 255?

    # If it's empty string, return false.
    if chunk.length == 0:
        return false

    # If any character in the string isn't a
    # digit, return false.
    for i from 0 to chunk.length - 1:
        if chunk[i] < '0' OR chunk[i] > '9':
            return false

    # If the string has a leading zero and isn't
    # zero, return false.
    if chunk.length >= 2 AND chunk[0] == '0':
        return false

    # Return true if and only if parsing the
    # chunk as an integer is between 0 and 255.
    return 0 <= int(chunk) AND int(chunk) <= 255

function validate(address):
    # If the number of periods is not 3, then
    # it can't be an IP address.
    chunks = address.split('.')
    if chunks.length != 4:
        return false

    # Check that each chunk delimited by periods,
    # represents a number from 0-255.
    for chunk in chunks:
        if not fitsOneByte(chunk):
            return false

    return true
Note: If our library does not have the builtin “split” for strings, we could still write one as shown below.

We record seen characters into a buffer, and flush the buffer into our answer every time we see a delimiting character.

function split(string, delimiter):
    buffer = ""
    answer = []
    for character in string:
        if character == delimiter:
            answer.push(buffer)
            buffer = ""
        else:
            buffer += character

    answer.push(buffer)
    return answer