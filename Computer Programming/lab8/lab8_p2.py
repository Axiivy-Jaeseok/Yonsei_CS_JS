# define function removeValuesInPlace
def removeValuesInPlace(L, threshold):
    """This function is remove the values in L.
        The function get list L and number threshold.
        If the values in L is larger than threshold,
        function remove the values in L.          """

    i = 0

# finding values which are above the threshold in L
    while i < len(L):
        if L[i] > threshold:

# remove the values
            del(L[i])
            i = i-1
        i = i+1

    return L
