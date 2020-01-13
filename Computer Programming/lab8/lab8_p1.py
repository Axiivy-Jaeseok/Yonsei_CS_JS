# define fuction resetValuesInPlace
def resetValuesInPlace(L, threshold):
    """This function is for reset the values in L.
        The function get list L and number threshold.
        If the values in L are larger than threshold,
        The function change the values to the zero.
                                                    """

# finding value which is above than threshold in L
    for i in range(0, len(L)):
        if L[i]>threshold:

# reset the value to 0
            L[i] = 0

    return L

